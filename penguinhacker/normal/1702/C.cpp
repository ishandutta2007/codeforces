#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, q;
		cin >> n >> q;
		map<int, int> first, last;
		for (int i=0; i<n; ++i) {
			int a;
			cin >> a;
			last[a]=i;
			if (first.find(a)==first.end())
				first[a]=i;
		}
		while(q--) {
			int a, b;
			cin >> a >> b;
			if (first.find(a)==first.end()||first.find(b)==first.end()) {
				cout << "NO\n";
				continue;
			}
			cout << (first[a]<last[b]?"YES":"NO") << "\n";
		}
	}
	return 0;
}