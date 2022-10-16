#include <bits/stdc++.h>
using namespace std;

const int MAX = 300001;
const int K = 26;

map<string, int> mp;
vector<int> tr(MAX);
vector<int> val(MAX);
multiset<int> vals[MAX];

struct aho_corasick{
	struct Vertex {
		int next[K];
		int leaf = false;
		int p = -1;
		char pch;
		int link = -1;
		int go[K];
		int jp = -1;

		Vertex(int p = -1, char ch = '$') : p(p), pch(ch) {
			fill(begin(next), end(next), -1);
			fill(begin(go), end(go), -1);
		}
	};

	vector<Vertex> t = vector<Vertex>(1);

	void add_string(string s, int id) {
		int v = 0;
		for (char ch : s) {
			int c = ch - 'a';
			if (t[v].next[c] == -1) {
				t[v].next[c] = t.size();
				t.emplace_back(v, ch);
			}
			v = t[v].next[c];
		}
		t[v].leaf = id;
	}

	int get_link(int v) {
		if (t[v].link == -1) {
			if (v == 0 || t[v].p == 0)
				t[v].link = 0;
			else
				t[v].link = go(get_link(t[v].p), t[v].pch);
		}
		return t[v].link;
	}

	int go(int v, char ch) {
		int c = ch - 'a';
		if (t[v].go[c] == -1) {
			if (t[v].next[c] != -1)
				t[v].go[c] = t[v].next[c];
			else
				t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
		}
		return t[v].go[c];
	} 

	int is_leaf(int v) {
		return t[v].leaf;
	}

	int jump(int v) {
		if (t[v].jp != -1) return t[v].jp;

		int nxt = get_link(v);
		if (nxt == 0) {
			t[v].jp = 0;
		} else if (t[nxt].leaf) {
			t[v].jp = nxt;
		} else {
			t[v].jp = jump(nxt);
		}

		return t[v].jp;
	}

	int solve(string s) {
		int ans = -1, cur = 0;
		for (char c: s) {
			cur = go(cur, c);
			int u = cur;

			while (u != 0) {
				if (!vals[t[u].leaf].empty()) {
					ans = max(ans, *vals[t[u].leaf].rbegin());
				}
				u = jump(u);
			}
		}
		return ans;
	}
} ahcs;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		if (mp.find(s) == mp.end()) {
			mp[s] = i;
			ahcs.add_string(s, i);
		}
		tr[i] = mp[s]; 
		vals[mp[s]].insert(0);
	}

	while (m--) {
		int que; cin >> que;
		if (que == 1) {
			int i, x; cin >> i >> x;
			int id = tr[i];

			vals[id].erase(vals[id].find(val[i]));
			val[i] = x;
			vals[id].insert(val[i]);
		} else {
			string s; cin >> s;
			cout << ahcs.solve(s) << '\n';
		}
	}

	return 0;
}