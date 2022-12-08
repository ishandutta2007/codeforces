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

int n, k;
int64 dp[2010][2010];

int64 mem(int bef, int rem){
	if(rem == 0)
		return 1;
	if(dp[bef][rem] != -1)
		return dp[bef][rem];
	int64 &ref = dp[bef][rem];
	ref = 0;
	for(int i = bef; i <= n; i += bef)
		ref = (ref + mem(i, rem - 1)) % Mod;
	return ref;
}

int main(){
	cin >> n >> k;
	memset(dp, -1, sizeof dp);
	int64 ret = mem(1, k);
	cout << ret << endl;
	return 0;
}