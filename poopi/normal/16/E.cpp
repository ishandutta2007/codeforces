										/* in the name of Allah */
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL

int n;
bool mark[300010];
double dp[300010];
double mat[20][20];

double mem(int mask){
	if(mask == (1 << n) - 1)
		return 1;
	if(mark[mask])
		return dp[mask];
	mark[mask] = true;
	dp[mask] = 0;
	int k = 1;
	for(int i = 0; i < n; i++)
		if(mask & (1 << i))
			k++;
	for(int i = 0; i < n; i++){
		if(mask & (1 << i)) continue;
		double sum = 0;
		for(int j = 0; j < n; j++)
			if(mask & (1 << j))
				sum += mat[j][i];
		dp[mask] += 2 * sum * mem(mask + (1 << i)) / k / (k - 1);
	}
	return dp[mask];
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> mat[i][j];
	for(int i = 0; i < n; i++)
		cout << setprecision(7) << fixed << mem(1 << i) << ' ';
	cout << endl;
	return 0;
}