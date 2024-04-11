#include <bits/stdc++.h>
using namespace std;

#define int long long

struct DSU {
	vector<int> P, S;
	DSU(int n) {
		P.resize(n+1);
		S.resize(n+1, 1);
		for (int i = 1; i <= n; i++) P[i] = i;
	}

	int add_node() {
		int id = P.size();
		P.push_back(id);
		S.push_back(1);
		return id;
	}
	
	int find(int x) {
		if (x == P[x]) return x;
		return P[x] = find(P[x]);
	}
	
	bool merge(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) return 0;
		if (S[a] < S[b]) swap(a, b);
		
		S[a] += S[b];
		P[b] = a;
		return 1;
	}
	
	int same(int a, int b) {
		return find(a) == find(b);
	}
};

int has_building(set<pair<int, int>> &st, int x) {
	auto it = st.lower_bound({x, -1});
	if (it == st.end()) return 0;
	if (it->first != x) return 0;
	return it->second;
}

vector<int> real_id;
set<pair<int, int>> st;
map<int, int> height;
DSU d(0);

void do_merge(int l, int r, int dest) {
	vector<pair<int, int>> nodes;
	for (auto it = st.lower_bound({l, -1}); it != st.end(); it++) {
		if (it->first > r) break;
		nodes.push_back(*it);
	}
	if (nodes.empty()) return;

	for (int i = 1; i < nodes.size(); i++) {
		d.merge(nodes[i-1].second, nodes[i].second);
	}
	int rt = d.find(nodes[0].second);

	for (auto p: nodes) {
		st.erase(st.find(p));
	}

	st.insert({dest, rt});
	height[rt] = dest;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	real_id.resize(n+1);
	
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		int id = has_building(st, x);
		real_id[i] = d.add_node();

		if (!id) {
			st.insert({x, real_id[i]});
			height[real_id[i]] = x;
		} else {
			d.merge(i, id);
			height[d.find(i)] = x;
		}
	}

	int q; cin >> q;
	while (q--) {
		//for (auto [u, v]: st) cout << "ST " << u << ' ' << v << endl;

		/*
		cout << "RES ";
		for (int k = 1; k <= n; k++) {
			cout << height[d.find(real_id[k])] << ' ';
		}
		cout << '\n';
		*/

		int t; cin >> t;
		if (t == 1) {
			int k, w; cin >> k >> w;

			int new_id = d.add_node();
			real_id[k] = new_id;

			int id = has_building(st, w);
			if (!id) {
				st.insert({w, new_id});
				height[new_id] = w;
			} else {
				d.merge(new_id, id);
				height[d.find(new_id)] = w;
			}
		} else if (t == 2) {
			int k; cin >> k;
			cout << height[d.find(real_id[k])] << '\n';
		} else if (t == 3) {
			int l, r; cin >> l >> r;
			int mid = (r+l)/2;

			do_merge(l, mid, l-1);
			do_merge(mid+1, r, r+1);
		}
	}

	return 0;
}