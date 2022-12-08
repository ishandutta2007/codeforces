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

int n, mx;
string str;
int64 dp[2010][2010];
int64 les[2010][2010];

int main(){
	cin >> n >> mx >> str;
	dp[n][0] = 1;
	for(int idx = n; idx > 0; idx--){
		dp[idx - 1][0] = 1;
		for(int k = 0; k <= mx; k++){
			int64 t1 = dp[idx][k] * (str[idx - 1] - 'a');
			les[idx - 1][k] = (les[idx][k] + t1) % Mod;
			dp[idx - 1][k] = (dp[idx - 1][k] + les[idx - 1][k]) % Mod;
			int pnt = idx - 1;
			for(int i = idx - 1; i < n; i++, pnt++){
				int64 t1 = i - idx + 2;
				int64 t2 = n - i;
				if(k + t1 * t2 > mx)
					break;
				dp[idx - 1][k + t1 * t2] += dp[i + 1][k] * ('z' - str[i]);
				dp[idx - 1][k + t1 * t2] %= Mod;
			}
			for(int i = n - 1; i > pnt; i--){
				int64 t1 = i - idx + 2;
				int64 t2 = n - i;
				if(k + t1 * t2 > mx)
					break;
				dp[idx - 1][k + t1 * t2] += dp[i + 1][k] * ('z' - str[i]);
				dp[idx - 1][k + t1 * t2] %= Mod;
			}
		}
	}
	cout << dp[0][mx] << endl;
	return 0;
}