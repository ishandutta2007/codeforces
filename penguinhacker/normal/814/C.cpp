#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, q, dp[1501][26]; //dp is precalculated as 26*1500 rather than 200000
string s;
int calc(int m, int c) {
	int res=0, cur=0;
	for (int l=0, r=0; r<n; ++r) {
		cur+=(s[r]-'a'!=c);
		while(l<r&&cur>m) cur-=(s[l++]-'a'!=c);
		res=max(res, r-l+1);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s >> q;
	for (int i=0; i<26; ++i) {
		for (int j=1; j<=n; ++j) {
			dp[j][i]=calc(j, i);
		}
	}
	while(q--) {
		int m; char c; cin >> m >> c;
		cout << dp[m][c-'a'] << '\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/