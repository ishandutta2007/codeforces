#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (int) x.size()
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-9;

int n, m;
vector<pair<int, pair<int, int>>> edges;
vector<vector<pair<int, int>>> ans;
vector<int> back;

int main() {
	ios::sync_with_stdio(false);

	cin >> n >> m;
	ans.resize(n);
	back.resize(n, -1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edges.pb(mp(a, mp(-b, i)));
	}

	sort(edges.begin(), edges.end());

	int cur_tree = 0;
	int cur_f = 0;
	for (auto e : edges) {
		int t = e.second.first;
		int id = e.second.second;

		if (t == -1) {
			ans[cur_tree].pb(mp(cur_tree + 1, id));
			ans[cur_tree + 1].pb(mp(cur_tree, id));
			cur_tree++;
		} else {
			while ((back[cur_f] >= cur_f - 2) && cur_f + 1 <= cur_tree) {
				cur_f++;
			}
			if (back[cur_f] >= cur_f - 2) {
				cout << "-1\n";
				return 0;
			}

			back[cur_f]++;
			ans[cur_f].pb(mp(back[cur_f], id));
			ans[back[cur_f]].pb(mp(cur_f, id));
		}

		id++;
	}

	vector<pair<int, int>> out(m);
	for (int i = 0; i < n; i++) {
		for (auto it : ans[i]) {
			out[it.second] = mp(i, it.first);
		}
	}

	for (auto it : out) {
		cout << it.first + 1 << " " << it.second + 1 << "\n";
	}

    return 0;
}