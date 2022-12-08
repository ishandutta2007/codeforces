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
int64 arr[3][3];
int64 dp[50][5][5];

int64 mem(int d, int s, int t){
	int m = 0;
	if(s == m || t == m)
		m++;
	if(s == m || t == m)
		m++;
	if(d == 1)
		return min(arr[s][t], arr[s][m] + arr[m][t]);
	if(dp[d][s][t] != -1)
		return dp[d][s][t];
	int64 &ref = dp[d][s][t];
	ref = mem(d - 1, s, m) + arr[s][t] + mem(d - 1, m, t);
	ref = min(ref, 2 * mem(d - 1, s, t) + arr[s][m] + mem(d - 1, t, s) + arr[m][t]);
	return ref;
}

int main(){
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			cin >> arr[i][j];
	cin >> n;
	memset(dp, -1, sizeof dp);
	cout << mem(n, 0, 2) << endl;
	return 0;
}