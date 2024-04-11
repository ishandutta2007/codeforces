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
#define Inf 2100000000
#define Mod 1000000007LL

int n, k;
int step, more;
int64 arr[300010];
int64 dp[5010][5010];

int64 mem(int lev, int rem){
	if(lev == k - 1)
		return 0;
	if(dp[lev][rem] != -1)
		return dp[lev][rem];
	int64 &ref = dp[lev][rem];
	ref = 0;
	int idx = lev * step + more - rem;
	if(k - lev > rem)
		ref = max(ref, mem(lev + 1, rem) + arr[idx + step] - arr[idx + step - 1]);
	if(rem > 0)
		ref = max(ref, mem(lev + 1, rem - 1) + arr[idx + step + 1] - arr[idx + step]);
	return ref;
}

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	memset(dp, -1, sizeof dp);
	step = n / k;
	more = n % k;
	int64 res = arr[n - 1] - arr[0] - mem(0, more);
	cout << res << endl;
	return 0;
}