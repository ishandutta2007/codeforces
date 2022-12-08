										/* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>
#define Mod 1000000007LL

int64 dp[1001][1001];

int64 mem(int sz, int rem){
	if(rem == 0)
		return 1;
	if(dp[sz][rem] != -1)
		return dp[sz][rem];
	int64& ref = dp[sz][rem];
	ref = 0;
	for(int i = 1; i <= sz - 2; i++){
		int64 t = (sz - 1 - i) * mem(i, rem - 1);
		ref = (ref + t) % Mod;
	}
	return ref;
}

int n, m, k;

int main(){
	cin >> n >> m >> k;
	memset(dp, -1, sizeof dp);
	int64 t1 = mem(n, k);
	int64 t2 = mem(m, k);
	int64 res = (t1 * t2) % Mod;
	cout << res << endl;
	return 0;
}