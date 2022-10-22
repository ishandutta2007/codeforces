#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, q, p[mxN+1][26];
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q >> s;
	for (int i=0; i<n; ++i) {
		memcpy(p[i+1], p[i], sizeof(p[i]));
		++p[i+1][s[i]-'a'];
	}
	while(q--) {
		int l, r;
		cin >> l >> r, --l, --r;
		int ans=0;
		for (int i=0; i<26; ++i)
			ans+=(i+1)*(p[r+1][i]-p[l][i]);
		cout << ans << "\n";
	}
	return 0;
}