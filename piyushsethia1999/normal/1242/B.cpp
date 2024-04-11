#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#ifndef print
#define print(...)
#endif
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

set<int> ad[100005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n;
	cin >> n;
	int m;
	cin >> m;
	set<int> un;
	for (int i = 0; i < n; ++i) un.insert(i);
	set<int> op;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v; u--; v--;
		ad[u].insert(v);
		ad[v].insert(u);
	}
	int cn = -1;
	while (!un.empty()) {
		set<int> no;
		int u;
		if (op.empty()) {
			u = *un.begin();
			un.erase(un.begin());
			cn++;
		} else {
			u = *op.begin();
			op.erase(op.begin());
		}
		for (int v : ad[u]) {
			if (un.find(v) != un.end()) {
				no.insert(v);
				un.erase(v);
			}
		}
		for (int uu : un) {
			op.insert(uu);
		}
		un.swap(no);
	}
	cout << cn;
}