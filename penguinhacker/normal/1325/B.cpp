#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;

void solve() {
	set<int> s;
	cin >> n;
	for (int i=0, a; i<n; ++i) {
		cin >> a;
		s.insert(a);
	}
	cout << s.size() << '\n';
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