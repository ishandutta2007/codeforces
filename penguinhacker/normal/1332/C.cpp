#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k, cnt[200000][26];
string s;

void solve() {
	cin >> n >> k >> s;
	for (int i=0; i<k; ++i)
		for (int j=0; j<26; ++j)
			cnt[i][j]=0;
	for (int i=0; i<n; ++i)
		cnt[i%k][s[i]-'a']++;
	int ans=0;
	for (int i=0; i<k/2; ++i) {
		int best=0;
		for (int j=0; j<26; ++j)
			best=max(best, cnt[i][j]+cnt[k-i-1][j]);
		ans+=2*n/k-best;
	}
	if (k&1) {
		int best=0;
		for (int j=0; j<26; ++j)
			best=max(best, cnt[k/2][j]);
		ans+=n/k-best;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}