#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k, a[10000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		for (int i=0; i<n; ++i)
			cin >> a[i];
		set<int> s;
		for (int i=0; i<n; ++i)
			s.insert(a[i]);
		if (s.size()>k) {
			cout << "-1\n";
			continue;
		}
		cout << n*k << '\n';
		for (int i=0; i<n; ++i) {
			for (const int &j : s)
				cout << j << ' ';
			for (int j=0; j<k-s.size(); ++j)
				cout << 1 << ' ';
		}
		cout << '\n';
	}
	return 0;
}