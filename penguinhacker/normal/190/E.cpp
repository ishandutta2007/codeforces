#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

uint64_t sm(uint64_t x) {
	x += 0x9e3779b97f4a7c15;
	x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
	x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
	return x ^ (x >> 31);
}

namespace std {
	template<> struct hash<ar<int, 2>> {
		size_t operator()(const ar<int, 2> &x) const {
			return 3*sm(x[0])+5*(x[1]);
		}
	};
}

int n, m;
unordered_set<ar<int, 2>> e;
unordered_set<int> rem;
vector<vector<int>> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		if (a>b) swap(a, b);
		e.insert({a, b});
	}
	for (int i=0; i<n; ++i) rem.insert(i);
	while(!rem.empty()) {
		int u=*rem.begin();
		rem.erase(rem.begin());
		vector<int> c={u};
		queue<int> q;
		q.push(u);
		while(!q.empty()) {
			int a=q.front(); q.pop();
			for (auto it=rem.begin(); it!=rem.end(); ) {
				int b=*it;
				ar<int, 2> chk={a, b};
				if (chk[0]>chk[1]) swap(chk[0], chk[1]);
				if (e.find(chk)==e.end()) {
					c.push_back(b);
					q.push(b);
					it=rem.erase(it);
				}
				else ++it;
			}
		}
		ans.push_back(c);
	}
	cout << ans.size() << "\n";
	for (auto& x: ans) {
		cout << x.size() << " ";
		for (int i: x) cout << i+1 << " ";
		cout << "\n";
	}
	return 0;
}