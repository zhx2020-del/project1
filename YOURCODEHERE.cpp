#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <algorithm>
#include <fstream>
#include <map>
#include <math.h>
#include <fcntl.h>
#include <vector>
#include <iterator>

#include "431project.h"

using namespace std;

//latency is related to cache size and set associative
//This function is used to get the latency of dl1 and il1
unsigned int latencycal(unsigned int size, unsigned int assoc) {
	unsigned int latency = 0;
	//cache size == 2 KB
	if (size == (2 * 1024)) {
		if (assoc == 2) {
			//size latency + associative latency
			latency = 1 + 1;
			return latency;
		}
		else if (assoc == 4) {
			latency = 1 + 2;
			return latency;
		}
		else if (assoc == 8) {
			latency = 1 + 3;
			return latency;
		}
		else {
			latency = 1;
			return latency;
		}
	}
	//cache size == 4 KB
	else if (size == (4 * 1024)) {
		if (assoc == 2) {
			latency = 2 + 1;
			return latency;
		}
		else if (assoc == 4) {
			latency = 2 + 2;
			return latency;
		}
		else if (assoc == 8) {
			latency = 2 + 3;
			return latency;
		}
		else {
			latency = 2;
			return latency;
		}
	}
	//cache size == 8 KB
	else if (size == (8 * 1024)) {
		if (assoc == 2) {
			latency = 3 + 1;
			return latency;
		}
		else if (assoc == 4) {
			latency = 3 + 2;
			return latency;
		}
		else if (assoc == 8) {
			latency = 3 + 3;
			return latency;
		}
		else {
			latency = 3;
			return latency;
		}
	}
	//cache size == 16 KB
	else if (size == (16 * 1024)) {
		if (assoc == 2) {
			latency = 4 + 1;
			return latency;
		}
		else if (assoc == 4) {
			latency = 4 + 2;
			return latency;
		}
		else if (assoc == 8) {
			latency = 4 + 3;
			return latency;
		}
		else {
			latency = 4;
			return latency;
		}
	}
	//cache size == 32 KB
	else if (size == (32 * 1024)) {
		if (assoc == 2) {
			latency = 5 + 1;
			return latency;
		}
		else if (assoc == 4) {
			latency = 5 + 2;
			return latency;
		}
		else if (assoc == 8) {
			latency = 5 + 3;
			return latency;
		}
		else {
			latency = 5;
			return latency;
		}
	}
	//cache size == 64 KB
	else if (size == (64 * 1024)) {
		if (assoc == 2) {
			latency = 6 + 1;
			return latency;
		}
		else if (assoc == 4) {
			latency = 6 + 2;
			return latency;
		}
		else if (assoc == 8) {
			latency = 6 + 3;
			return latency;
		}
		else {
			latency = 6;
			return latency;
		}
	}
}

//This function is used to get the latency of ul2
unsigned int latencycal2(unsigned int size, unsigned int assoc) {
	unsigned int latency = 0;
	//cache size == 32 KB
	if (size == (32 * 1024)) {
		if (assoc == 2) {
			//size latency + associative latency
			latency = 5 + 1;
			return latency;
		}
		else if (assoc == 4) {
			latency = 5 + 2;
			return latency;
		}
		else if (assoc == 8) {
			latency = 5 + 3;
			return latency;
		}
		else if (assoc == 16) {
			latency = 5 + 4;
			return latency;
		}
		else {
			latency = 5;
			return latency;
		}
	}
	//cache size == 64 KB
	else if (size == (64 * 1024)) {
		if (assoc == 2) {
			latency = 6 + 1;
			return latency;
		}
		else if (assoc == 4) {
			latency = 6 + 2;
			return latency;
		}
		else if (assoc == 8) {
			latency = 6 + 3;
			return latency;
		}
		else if (assoc == 16) {
			latency = 6 + 4;
			return latency;
		}
		else {
			latency = 6;
			return latency;
		}
	}
	//cache size == 128 KB
	else if (size == (128 * 1024)) {
		if (assoc == 2) {
			latency = 7 + 1;
			return latency;
		}
		else if (assoc == 4) {
			latency = 7 + 2;
			return latency;
		}
		else if (assoc == 8) {
			latency = 7 + 3;
			return latency;
		}
		else if (assoc == 16) {
			latency = 7 + 4;
			return latency;
		}
		else {
			latency = 7;
			return latency;
		}
	}
	//cache size == 256 KB
	else if (size == (256 * 1024)) {
		if (assoc == 2) {
			latency = 8 + 1;
			return latency;
		}
		else if (assoc == 4) {
			latency = 8 + 2;
			return latency;
		}
		else if (assoc == 8) {
			latency = 8 + 3;
			return latency;
		}
		else if (assoc == 16) {
			latency = 8 + 4;
			return latency;
		}
		else {
			latency = 8;
			return latency;
		}
	}
	//cache size == 512 KB
	else if (size == (512 * 1024)) {
		if (assoc == 2) {
			latency = 9 + 1;
			return latency;
		}
		else if (assoc == 4) {
			latency = 9 + 2;
			return latency;
		}
		else if (assoc == 8) {
			latency = 9 + 3;
			return latency;
		}
		else if (assoc == 16) {
			latency = 9 + 4;
			return latency;
		}
		else {
			latency = 9;
			return latency;
		}
	}
	//cache size == 1024 KB
	else if (size == (1024 * 1024)) {
		if (assoc == 2) {
			latency = 10 + 1;
			return latency;
		}
		else if (assoc == 4) {
			latency = 10 + 2;
			return latency;
		}
		else if (assoc == 8) {
			latency = 10 + 3;
			return latency;
		}
		else if (assoc == 16) {
			latency = 10 + 4;
			return latency;
		}
		else {
			latency = 10;
			return latency;
		}
	}
}

/*
 * Enter your PSU IDs here to select the appropriate scanning order.
 */
#define PSU_ID_SUM (901437863+965232865)

/*
 * Some global variables to track heuristic progress.
 * 
 * Feel free to create more global variables to track progress of your
 * heuristic.
 */
unsigned int currentlyExploringDim = 0;
bool currentDimDone = false;
bool isDSEComplete = false;
int coun = 0, temp = 99;

/*
 * Given a half-baked configuration containing cache properties, generate
 * latency parameters in configuration string. You will need information about
 * how different cache paramters affect access latency.
 * 
 * Returns a string similar to "1 1 1"
 */
std::string generateCacheLatencyParams(string halfBackedConfig) {

	string latencySettings;

	//
	//YOUR CODE BEGINS HERE
	//
	latencySettings = "1 1 1";

	unsigned int dl1size, il1size, l2size;
	unsigned int dl1assoc, il1assoc, l2assoc;
	unsigned int latency1, latency2, latency3;

	//get the size of dl1
	dl1size = getdl1size(halfBackedConfig);
	//get the assoc of dl1
	dl1assoc = 1 << extractConfigPararm(halfBackedConfig, 4);
	//get the latency of dl1
	latency1 = latencycal(dl1size, dl1assoc);

	il1size = getil1size(halfBackedConfig);
	il1assoc = 1 << extractConfigPararm(halfBackedConfig, 6);
	latency2 = latencycal(il1size, il1assoc);

	l2size = getl2size(halfBackedConfig);
	l2assoc = 1 << extractConfigPararm(halfBackedConfig, 9);
	latency3 = latencycal2(l2size, l2assoc);

	//set up latency of dl1
	latencySettings[0] = latency1 - 1 + '0';

	//set up latency of il1
	latencySettings[2] = latency2 - 1 + '0';

	//set up latency of l2
	latencySettings[4] = latency3 - 5 + '0';

	//
	//YOUR CODE ENDS HERE
	//
	return latencySettings;
}

/*
 * Returns 1 if configuration is valid, else 0
 */
int validateConfiguration(std::string configuration) {
	unsigned int il1blocksize, dl1blocksize, ifqsize, l2blocksize, temp, temp2, dl1size, il1size, l2size;
	// FIXME - YOUR CODE HERE

	//blocksize of dl1
	dl1blocksize =  8 * (1 << extractConfigPararm(configuration, 2));

	//blocksize of il1
	il1blocksize = 8 * (1 << extractConfigPararm(configuration, 2));

	//blocksize of l2
	l2blocksize = 16 << extractConfigPararm(configuration, 8);

	//blocksize of ifq
	ifqsize = 8 * (1 << extractConfigPararm(configuration, 0));

	//the size of dl1
	dl1size = getdl1size(configuration);

	//the size of il1
	il1size = getil1size(configuration);

	//the size of l2
	l2size = getl2size(configuration);

	//2 times of blocksize of il1
	temp = 2 * il1blocksize;

	//2 times (dl1size + il1size)
	temp2 = 2 * (dl1size + il1size);

	//il1blocksize >=  ifqsize
	if (il1blocksize < ifqsize) {
		cout << "wrong config: "<<configuration<<endl;
		cout << "il1blocksize: " << il1blocksize << "ifqsize: " << ifqsize <<"has to be equal"<<endl;
		return 0;
	}

	//il1blocksize has to be equal to dl1blocksize
	if (il1blocksize != dl1blocksize) {
		cout << "wrong config: " << configuration << endl;
		cout << "il1blocksize: " << il1blocksize << "dl1blocksize: " << dl1blocksize << "has to be equal" << endl;
		return 0;
	}

	//the minimum size of il1 is: 2KB
	if (il1size < (2 * 1024)) {
		cout << "wrong config: " << configuration << endl;
		cout << "il1size: "<< il1size <<"the minimum size of il1 is: 2KB"<<endl;
		return 0;
	}

	//the maximum size of il1 is: 64KB
	if (il1size > (64 * 1024)) {
		cout << "wrong config: " << configuration << endl;
		cout << "il1size: " << il1size << "the maximum size of il1 is: 64KB" << endl;
		return 0;
	}

	//the minimum size of dl1 is: 2KB
	if (dl1size < (2 * 1024)) {
		cout << "wrong config: " << configuration << endl;
		cout << "dl1size: " << dl1size << "the minimum size of dl1 is: 2KB" << endl;
		return 0;
	}

	//the maximum size of dl1 is: 64KB
	if (dl1size > (64 * 1024)) {
		cout << "wrong config: " << configuration << endl;
		cout << "dl1size: " << dl1size << "the maximum size of dl1 is: 64KB" << endl;
		return 0;
	}

	//ul2blocksize has to bigger than 2 times of blocksize of il1
	if (l2blocksize < temp) {
		cout << "wrong config: " << configuration << endl;
		cout << "l2blocksize: " << l2blocksize <<"temp: "<<temp<<"ul2blocksize has to bigger than 2 times of blocksize of il1" << endl;
		return 0;
	}

	//ul2size has to bigger than 2 times of (dl1size + il1size)
	if (l2size < temp2) {
		cout << "wrong config: " << configuration << endl;
		cout << "l2size: " << l2size << "temp2: " << temp2 << "ul2size has to bigger than 2 times of (dl1size + il1size)" << endl;
		return 0;
	}

	//The minimum size of l2: 32KB
	if (l2size < (32 * 1024)) {
		cout << "wrong config: " << configuration << endl;
		cout << "l2size: " << l2size << "The minimum size of l2: 32KB" << endl;
		return 0;
	}

	//The maximum size of l2: 1024KB
	if (l2size > (1024 * 1024)) {
		cout << "wrong config: " << configuration << endl;
		cout << "l2size: " << l2size << "The maximum size of l2: 1024KB" << endl;
		return 0;
	}
	// The below is a necessary, but insufficient condition for validating a
	// configuration.

	return isNumDimConfiguration(configuration);
}

/*
 * Given the current best known configuration, the current configuration,
 * and the globally visible map of all previously investigated configurations,
 * suggest a previously unexplored design point. You will only be allowed to
 * investigate 1000 design points in a particular run, so choose wisely.
 *
 * In the current implementation, we start from the leftmost dimension and
 * explore all possible options for this dimension and then go to the next
 * dimension until the rightmost dimension.
 */
std::string generateNextConfigurationProposal(std::string currentconfiguration,
		std::string bestEXECconfiguration, std::string bestEDPconfiguration,
		int optimizeforEXEC, int optimizeforEDP) {

	//
	// Some interesting variables in 431project.h include:
	//
	// 1. GLOB_dimensioncardinality
	// 2. GLOB_baseline
	// 3. NUM_DIMS
	// 4. NUM_DIMS_DEPENDENT
	// 5. GLOB_seen_configurations

	std::string nextconfiguration = currentconfiguration;
	// Continue if proposed configuration is invalid or has been seen/checked before.
	while (!validateConfiguration(nextconfiguration) ||
		GLOB_seen_configurations[nextconfiguration]) {

		// Check if DSE has been completed before and return current
		// configuration.
		if(isDSEComplete) {
			return currentconfiguration;
		}

		std::stringstream ss;

		string bestConfig;
		if (optimizeforEXEC == 1)
			bestConfig = bestEXECconfiguration;

		if (optimizeforEDP == 1)
			bestConfig = bestEDPconfiguration;

		// Fill in the dimensions already-scanned with the already-selected best
		// value.

		for (int dim = 0; dim < currentlyExploringDim; ++dim) {
			ss << extractConfigPararm(bestConfig, dim) << " ";
		}

		
		// Handling for currently exploring dimension. This is a very dumb
		// implementation.
		int nextValue = extractConfigPararm(nextconfiguration,
				currentlyExploringDim) + 1;

		if (coun == 0 && nextValue > 1){
			temp = nextValue;
			nextValue = 0;
			coun++;
		}

		if (nextValue == temp) {
			nextValue++;
			temp = 99;
		}

		if (nextValue >= GLOB_dimensioncardinality[currentlyExploringDim]) {
			nextValue = GLOB_dimensioncardinality[currentlyExploringDim] - 1;
			currentDimDone = true;
			coun = 0;
		}

		ss << nextValue << " ";

		// Fill in remaining independent params with 0.
		for (int dim = (currentlyExploringDim + 1);
				dim < (NUM_DIMS - NUM_DIMS_DEPENDENT); ++dim) {
			ss << extractConfigPararm(nextconfiguration,dim)<<" ";
		}

		//
		// Last NUM_DIMS_DEPENDENT3 configuration parameters are not independent.
		// They depend on one or more parameters already set. Determine the
		// remaining parameters based on already decided independent ones.
		//
		string configSoFar = ss.str();

		// Populate this object using corresponding parameters from config.
		ss << generateCacheLatencyParams(configSoFar);

		// Configuration is ready now.
		nextconfiguration = ss.str();

		// Make sure we start exploring next dimension in next iteration.
		if (currentDimDone) {
			currentlyExploringDim++;
			currentDimDone = false;
		}

		// Signal that DSE is complete after this configuration.
		if (currentlyExploringDim == (NUM_DIMS - NUM_DIMS_DEPENDENT))
			isDSEComplete = true;


	}
	return nextconfiguration;
}

