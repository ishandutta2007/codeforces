#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[200000];

void solve() {
	cin >> n;
	int last = 0;
	vector<int> a1, a2;
	set<int> s1, s2;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (i == 0 || a[i] > a[i - 1]) {
			a1.push_back(a[i]);
			a2.push_back(a[i]);
			for (int j = last + 1; j < a[i]; ++j)
				s1.insert(j), s2.insert(j);
			last = a[i];
		}
		else {
			a1.push_back(*s1.begin()); s1.erase(s1.begin());
			a2.push_back(*s2.rbegin()); s2.erase(--s2.end());
		}
	}
	for (int i : a1) cout << i << " ";
	cout << "\n";
	for (int i : a2) cout << i << " ";
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
	return 0;
}