#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
vector<set<int>> g;
vector<set<int>> leaves;

struct comp {
	bool operator() (int a, int b) const {
		if (leaves[a].size() == leaves[b].size()) return a < b;
		return leaves[a].size() > leaves[b].size();
	}
};

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		g = leaves = vector<set<int>>(n);
		for (int i = 0; i < n - 1; ++i) {
			int x, y;
			cin >> x >> y;
			--x, --y;
			g[x].insert(y);
			g[y].insert(x);
		}
		for (int i = 0; i < n; ++i) {
			if (g[i].size() == 1) {
				leaves[*g[i].begin()].insert(i);
			}
		}
		set<int, comp> st;
		for (int i = 0; i < n; ++i) {
			st.insert(i);
		}
		int ans = 0;
		while (true) {
			int v = *st.begin();
			if (int(leaves[v].size()) < k) break;
			for (int i = 0; i < k; ++i) {
				int leaf = *leaves[v].begin();
				g[leaf].erase(v);
				g[v].erase(leaf);
				st.erase(v);
				st.erase(leaf);
				leaves[v].erase(leaf);
				if (leaves[leaf].count(v)) leaves[leaf].erase(v);
				if (g[v].size() == 1) {
					int to = *g[v].begin();
					st.erase(to);
					leaves[to].insert(v);
					st.insert(to);
				}
				st.insert(v);
				st.insert(leaf);
				
			}
			ans += 1;
		}
		cout << ans << endl;
	}
	
	return 0;
}