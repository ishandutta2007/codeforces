#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 10;
const int mod = 1e9 + 7;

int f[N];
int c[N][N];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}
	f[0] = 199;
	f[1] = 0;
	for(int i = 2; i < N; ++i){
		f[i] = f[__builtin_popcount(i)] + 1;
	}



	for(int i = 0; i < N; ++i){
		c[i][0] = 1;
		for(int j = 1; j <= i; ++j){
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
		}
	}

	int k;
	string s;
	cin >> s >> k;

	int ans = 0;

	int cur = 0;

	for(int i = 0; i < s.size(); ++i){
		if(s[i] == '0') continue;
		int len = s.size() - i - 1;


		for(int j = 0; j <= len; ++j){
			if(f[cur + j] + 1 == k){
				 ans += c[len][j] - (cur == 0 && j == 1), ans %= mod;
			}
		}

		++cur;

	}

	if(s != "1") ans += (f[cur] == (k - 1));

	cout << ans + (k == 0 && s != "0");

	return 0;
}