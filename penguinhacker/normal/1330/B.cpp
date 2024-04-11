#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, a[200005];

void solve() {
	cin >> n;
	bool pref[n+5], suff[n+5];
	memset(pref, 0, sizeof(pref));
	memset(suff, 0, sizeof(suff));
	set<int> s1, s2;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<n; ++i) {
		s1.insert(a[i]);
		if (s1.size() == i+1 && *s1.rbegin() == i+1)
			pref[i] = 1;
	}
	for (int i=0; i<n; ++i) {
		s2.insert(a[n-i-1]);
		if (s2.size() == i+1 && *s2.rbegin() == i+1)
			suff[i] = 1;
	}
	int cnt = 0;
	for (int i=0; i<n-1; ++i)
		if (pref[i] && suff[n-i-2])
			cnt++;
	cout << cnt << '\n';
	for (int i=0; i<n-1; ++i)
		if (pref[i] && suff[n-i-2])
			cout << i+1 << ' ' << n-i-1 << '\n';
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