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

int n, m;
int s[110], t[21];
char c[21];
int dp[1100010][21];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> s[i];
	sort(s, s + n);
	reverse(s, s + n);
	cin >> m;
	for(int i = 0; i < m; i++)
		cin >> c[i] >> t[i];

	for(int i = 0; i < (1 << m); i++)
		dp[i][m] = 0;
	for(int idx = m - 1; idx >= 0; idx--){
		for(int mask = 0; mask < (1 << m); mask++){
			int sg = 1;
			if(idx < m - 1 && t[idx] != t[idx + 1])
				sg = -1;

			int &ref = dp[mask][idx];
			ref = -Inf;
			if(c[idx] == 'b'){
				ref = sg * dp[mask][idx + 1];
				for(int i = 0; i < m; i++)
					if(mask & (1 << i))
						ref = max(ref, sg * dp[mask - (1 << i)][idx + 1]);
			}
			else{
				for(int i = 0; i < m; i++)
					if(mask & (1 << i))
						ref = max(ref, sg * dp[mask - (1 << i)][idx + 1] + s[i]);
			}
		}
	}

	int res = dp[(1 << m) - 1][0];
	if(t[0] == 2)
		res *= -1;
	cout << res << endl;
	return 0;
}