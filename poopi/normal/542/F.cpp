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

int n, t;
vector <P> v;
int dp[2][2010][110];

int main(){
	cin >> n >> t;
	int a, b;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		v.push_back(P(a, b));
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	int cur = 0, bef = 1;
	for(int i = n - 1; i >= 0; i--){
		for(int j = 2 * n; j >= 0; j--){
			for(int k = t; k >= 0; k--){
				dp[cur][j][k] = dp[bef][j][k];
				if(j <= n)
					dp[cur][j][k] = max(dp[cur][j][k], dp[cur][2 * j][k + 1]);
				if(j > 0 && k + v[i].first <= t)
					dp[cur][j][k] = max(dp[cur][j][k], dp[bef][j - 1][k] + v[i].second);
			}
		}
		cur = 1 - cur;
		bef = 1 - bef;
	}
	cout << dp[bef][1][0] << endl;
	return 0;
}