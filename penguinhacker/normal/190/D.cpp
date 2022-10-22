#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k, a[400000];
map<int, int> cnt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
	}
	ll ans=0;
	for (int l=0, r=0; r<n; ++r) {
		++cnt[a[r]];
		while(cnt[a[r]]>=k) {
			--cnt[a[l++]];
		}
		ans+=l;
	}
	cout << ans;
	return 0;
}