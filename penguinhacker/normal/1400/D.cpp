#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3000;
int n, a[mxN], cnt[mxN];

void solve() {
	cin >> n;
	memset(cnt, 0, sizeof(cnt));
	for (int i=0; i<n; ++i) {
		cin >> a[i], --a[i];
		++cnt[a[i]];
	}
	ll ans=0;
	for (int i=0; i<n; ++i)
		ans+=1ll*cnt[i]*(cnt[i]-1)*(cnt[i]-2)*(cnt[i]-3)/24;
	for (int i=0; i<n; ++i) {
		--cnt[a[i]];
		int match=0;
		for (int j=0; j<i; ++j) {
			if (a[j]==a[i])
				++match;
			else
				ans+=match*cnt[a[j]];
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while(t--)
		solve();
	return 0;
}