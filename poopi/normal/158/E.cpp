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
#define Inf 100000

int n, k;
int t[5000], d[5000];
int dp[4010][4010];

int mem(int idx, int rem){
	if(rem < 0)
		return Inf;
	if(idx == 0)
		return 0;
	if(dp[idx][rem] != -1)
		return dp[idx][rem];
	int bef = mem(idx - 1, rem);
	dp[idx][rem] = min(mem(idx - 1, rem - 1), max(bef + 1, t[idx]) + d[idx] - 1);
	return dp[idx][rem];
}

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> t[i] >> d[i];
	t[0] = d[0] = 0;
	t[n + 1] = 86401;
	memset(dp, -1, sizeof dp);
	int mx = 0;
	for(int i = 0; i <= n; i++){
		int str = mem(i, k);
		int end = t[i + 1];
		mx = max(mx, end - str - 1);
	}
	cout << mx << endl;
	return 0;
}