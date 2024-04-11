#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q; cin >> q;
	while(q--) {
		int u, v; cin >> u >> v;
		if (u > v || __builtin_popcount(u) < __builtin_popcount(v)) {
			cout << "NO\n";
			continue;
		}
		if (u == v) {
			cout << "YES\n";
			continue;
		}
		auto Get = [&](int x) {
			vector<int> v;
			for (int i = 0; i < 30; ++i) if (x & (1 << i)) v.push_back(i);
			return v;
		};
		vector<int> a = Get(u);
		vector<int> b = Get(v);
		while(!a.empty() && !b.empty() && a.back() == b.back()) a.pop_back(), b.pop_back();
		assert(!b.empty());
		if (a.back() > b.back()) {
			cout << "NO\n";
			continue;
		}
		b.pop_back();
		while(a.size() > b.size()) a.pop_back();
		bool g = 1;
		for (int i = 0; i < a.size(); ++i) g &= a[i] <= b[i];
		cout << (g ? "YES" : "NO") << "\n";
	}
	return 0;
}