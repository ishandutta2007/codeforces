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
#define Inf 1000000000
#define Mod 1000000007LL

int n, k;
int arr[30010];
int dp[30010][210][3];

int mem(int idx, int rem, int st){
	if(rem == 0)
		return 0;
	if(idx == n)
		return -Inf;

	int &ref = dp[idx][rem][st];
	if(ref != -1)
		return ref;

	ref = mem(idx + 1, rem, st);
	if(rem != k && rem != 1)
		ref = max(ref, mem(idx + 1, rem - 1, st));

	int sum = 0;
	for(int i = idx; i < n; i++){
		sum += (st - 1) * arr[i] * (rem == 1 || rem == k ? 1 : 2);
		int val = mem(i + 1, rem - 1, 2 - st);
		ref = max(ref, val + sum);
	}
	return ref;
}

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	memset(dp, -1, sizeof dp);
	int t1 = mem(0, k, 0);
	int t2 = mem(0, k, 2);
	cout << max(t1, t2) << endl;
	return 0;
}