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
#define Max 30001

#pragma comment(linker, "/STACK:50000000")

int n, d, B = 300;
int dp[Max][600];
int cnt[Max];

int mem(int idx, int cur){
	if(idx >= Max)
		return 0;
	if(d + cur - B <= 0)
		return 0;

	int &ref = dp[idx][cur];
	if(ref != -1)
		return ref;

	int diff = d + cur - B;
	int t1 = mem(idx + diff - 1, cur - 1);
	int t2 = mem(idx + diff, cur);
	int t3 = mem(idx + diff + 1, cur + 1);
	return ref = max(t1, max(t2, t3)) + cnt[idx];
}

int main(){
	cin >> n >> d;
	int t;
	for(int i = 0; i < n; i++){
		cin >> t;
		cnt[t]++;
	}
	memset(dp, -1, sizeof dp);
	cout << mem(d, B) << endl;
	return 0;
}