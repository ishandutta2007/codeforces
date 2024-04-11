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
#define Inf 2000000000
#define Mod 1000000007LL

int n, k;
int64 arr[2010], dif;
int64 dp[2010];

int64 mem(int idx){
	if(idx == n - 1)
		return 0;
	if(dp[idx] != -1)
		return dp[idx];
	int64 &ref = dp[idx];
	ref = n - 1 - idx;
	for(int i = idx + 1; i < n; i++){
		int len = i - idx;
		int64 mx = (abs(arr[i] - arr[idx]) + len - 1) / len;
		if(mx <= dif)
			ref = min(ref, mem(i) + len - 1);
	}
	return ref;
}

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	if(k >= n - 1){
		cout << 0 << endl;
		return 0;
	}
	int64 l = 0, r = Inf;
	while(l < r){
		dif = (l + r) / 2;
		memset(dp, -1, sizeof dp);
		int64 res = Inf;
		for(int i = 0; i <= k; i++)
			res = min(res, mem(i) + i);
		if(res <= k)
			r = dif;
		else l = dif + 1;
	}
	cout << r << endl;
	return 0;
}