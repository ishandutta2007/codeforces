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
#define Inf 100000000LL
#define Mod 1000000007LL

int n;
int t[2000], c[2000];
int64 dp[2010][2010];

int64 mem(int idx, int rem){
	if(rem <= 0) return 0;
	if(idx == n) return Inf * Inf;
	if(dp[idx][rem] != -1)
		return dp[idx][rem];
	return dp[idx][rem] = min(mem(idx + 1, rem), mem(idx + 1, rem - t[idx] - 1) + c[idx]);
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> t[i] >> c[i];
	memset(dp, -1, sizeof dp);
	cout << mem(0, n) << endl;
	return 0;
}