										/* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>
#define Mod 1000000007LL

string s1, s2;

int64 dp[5010][5010];

int main(){
	while(cin >> s1 >> s2){
		memset(dp, 0, sizeof dp);
		for(int i = s1.size() - 1; i >= 0; i--){
			for(int j = s2.size() - 1; j >= 0; j--){
				dp[i][j] = dp[i][j + 1];
				if(s1[i] == s2[j])
					dp[i][j] += 1 + dp[i + 1][j + 1];
				dp[i][j] %= Mod;
			}
		}
		int64 cnt = 0;
		for(int i = 0; i < s1.length(); i++)
			cnt = (cnt + dp[i][0]) % Mod;
		cout << cnt << endl;
	}
	return 0;
}