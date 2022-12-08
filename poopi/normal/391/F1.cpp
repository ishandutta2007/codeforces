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
int64 arr[3010];
bool mark[3010][3010][2];
int64 dp[3010][3010][2];

int64 mem(int idx, int rem, int st){
	if(idx == n || rem == 0)
		return 0;
	int64 &ref = dp[idx][rem][st];
	if(mark[idx][rem][st])
		return ref;
	mark[idx][rem][st] = true;

	ref = mem(idx + 1, rem, st);
	if(st == 0)
		ref = max(ref, mem(idx + 1, rem, 1) - arr[idx]);
	else ref = max(ref, mem(idx + 1, rem - 1, 0) + arr[idx]);
	return ref;
}

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	cout << mem(0, k, 0) << endl;
	return 0;
}