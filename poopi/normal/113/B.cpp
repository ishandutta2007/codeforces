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

string s, a, b;
bool fa[2010], fb[2010];
int dp[2010][2010];
int mx[2010];

int main(){
	while(cin >> s >> a >> b){
		int n = s.length();
		memset(fa, false, sizeof fa);
		memset(fb, false, sizeof fb);
		for(int i = 0; i < n; i++){
			if(i + (int)a.length() <= n && s.substr(i, (int)a.length()) == a)
				fa[i] = true;
			if(i + (int)b.length() <= n && s.substr(i, (int)b.length()) == b)
				fb[i] = true;
		}
		memset(dp, 0, sizeof dp);
		memset(mx, 0, sizeof mx);
		for(int i = n - 1; i >= 0; i--){
			for(int j = n - 1; j > i; j--){
				if(s[i] == s[j])
					dp[i][j] = dp[i + 1][j + 1] + 1;
				else dp[i][j] = 0;
				mx[j] = max(mx[j], dp[i][j]);
			}
		}
		/*for(int i = 0; i < n; i++){
			cout << fa[i] << ' ';
		}
		cout << endl;

		for(int i = 0; i < n; i++){
			cout << fb[i] << ' ';
		}
		cout << endl;
		for(int i = 0; i < n; i++){
			cout << mx[i] << ' ';
		}
		cout << endl;
		*/
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			//cout << i << ' ' << a.length() << ' ' << b.length() << endl;
			if(i < a.length() || i < b.length())
				continue;
			for(int j = 0; j + i - 1 < n; j++){
				//cout << i << ' ' << j << " D" << endl;
				if(mx[j] >= i)
					continue;
				//cout << j << ' ' << j + i - b.length() << endl;
				if(fa[j] && fb[j + i - b.length()])
					cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}