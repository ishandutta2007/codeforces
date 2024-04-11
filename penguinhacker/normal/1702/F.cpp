#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, a[mxN], b[mxN];

void solve() {
	cin >> n;
	map<int, int> mp;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		while(a[i]%2==0)
			a[i]/=2;
		for (; a[i]; ++mp[a[i]], a[i]/=2);
	}
	for (int i=0; i<n; ++i) {
		cin >> b[i];
		while(b[i]%2==0)
			b[i]/=2;
		for (; b[i]; --mp[b[i]], b[i]/=2);
	}
	for (auto x : mp)
		if (x.second>0) {
			cout << "NO\n";
			return;
		}
	cout << "YES\n";
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