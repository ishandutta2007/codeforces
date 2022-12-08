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
#define Max 2000001

int n;
int dp[Max];

int main(){
	memset(dp, -1, sizeof dp);
	cin >> n;
	int t;
	for(int i = 0; i < n; i++){
		cin >> t;
		dp[t] = 0;
	}
	for(int i = 1; i < Max; i++)
		if(dp[i] == -1)
			dp[i] = dp[i - 1] + 1;
	
	int ans = 0;
	for(int i = 2; i < Max; i++){
		if(dp[i] != 0) continue;
		for(int j = 2 * i - 1; j < Max; j += i)
			ans = max(ans, i - 1 - dp[j]);
	}
	cout << ans << endl;
	return 0;
}