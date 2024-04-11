#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		vector<string> a(n);
		for (auto &u : a) cin >> u;
		set<string> s;
		int res = 0;
		vector<int> need;
		for (int i = 0; i < a.size(); i++) {
			if (s.count(a[i])) {
				res++;
				need.push_back(i);
			} else s.insert(a[i]);
		}

		auto getNext = [&](string u) {
			u.back()++;
			if (u.back() > '9') u.back() = '0';
			return u; 
		};

		for (int u : need) {
			while (s.count(a[u])) {
				a[u] = getNext(a[u]);
			}
			s.insert(a[u]);
		}
		cout << res << '\n';
		for (string u : a) cout << u << '\n';
	}
	return 0;
}