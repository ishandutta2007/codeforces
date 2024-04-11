#include <bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7;

int main() {
	int n; cin >> n;

	int res = 0;
	vector<pair<int,int>> v;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		v.emplace_back(i,x);
		for (auto &[j,y]: v) y = gcd(y,x);
		auto it = unique(begin(v), end(v), [&](auto p, auto q) { return p.second == q.second; });
		v.erase(it, end(v));

		bool remove = false;
		v.emplace_back(i+1,0);
		for (int k = 0; k+1 < ssize(v); k++) {
			auto [j1,y] = v[k];
			auto [j2,z] = v[k+1];
			if (j1 <= i+1-y && i+1-y < j2) remove = true;
		}
		v.pop_back();

		res += remove;
		if (remove) v = {{0,1}, {i,P}};
		cout << res << " \n"[i+1==n];
	}
}