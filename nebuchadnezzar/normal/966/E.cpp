#include "bits/stdc++.h"
#define ff first
#define ss second
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }

const int MAXN = 1e5 + 5, SQRT = 300;

int sz[MAXN];
vector<int> st;
vector<int> graph[MAXN];
vector<vector<int>> paths, choosen;

int dfs1(int v) {
	sz[v] = 1;
	for (int to : graph[v]) {
		dfs1(to);
		sz[v] += sz[to];
	}
	return 0;
}

int dfs2(int v) {
	st.push_back(v);
	if (!szof(graph[v])) {
		paths.push_back(st);
		st.clear();
		return 0;
	}

	
	int mem = -1;
	for (int to : graph[v]) {
		if (mem == -1 || sz[mem] < sz[to]) {
			mem = to;
		}
	}

	dfs2(mem);

	for (int to : graph[v]) {
		if (to != mem) {
			dfs2(to);
		}
	}
	return 0;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> parent(n, -1);
	for (int i = 1; i < n; ++i) {
		cin >> parent[i];
		--parent[i];
		graph[parent[i]].push_back(i);
	}
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		arr[i] *= -1;
	}

	dfs1(0);
	dfs2(0);

	//cerr << "here" << endl;

	vector<int> path_n(n);
	vector<int> whom(n);
	for (int i = 0; i < szof(paths); ++i) {
		for (int q : paths[i]) {
			path_n[q] = i;
		}
		int last = -1;
		choosen.push_back({});
		int lastk = 0;
		for (int j = SQRT; j < szof(paths[i]); j += SQRT) {
			last = j;
			choosen.back().push_back(paths[i][j]);
			for (int k = lastk; k <= j; ++k) {
				whom[paths[i][k]] = choosen.back().back();
			}
			lastk = j + 1;
		}
		if (last != szof(paths[i]) - 1) {
			choosen.back().push_back(paths[i].back());
			for (int k = lastk; k < szof(paths[i]); ++k) {
				whom[paths[i][k]] = choosen.back().back();
			}
		}
	}

	
	vector<int> special(n);
	for (int i = 0; i < szof(choosen); ++i) {
		for (int num : choosen[i]) {
			special[num] = true;
		}
	}




	vector<vector<int>> here(n);
	for (int i = 0; i < n; ++i) {
		here[whom[i]].push_back(arr[i]);
	}

	for (int i = 0; i < n; ++i) {
		sort(here[i].begin(), here[i].end());
	}

	vector<int> rest(n);
	vector<int> add(n);
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		//cerr << "i: " << i << endl;
		int num;
		cin >> num;
		num = abs(num) - 1;
		int change = 1;
		if (rest[num]) {
			change = -1;
		}
		rest[num] ^= 1;
		

		while (num != -1) {
			int cur = whom[num];
			int tmp = num;
			while (tmp != -1 && (tmp == num || whom[tmp] == cur)) {
				arr[tmp] += change;
				//cerr << "change " << tmp << " " << change << endl;
				tmp = parent[tmp];
			}

			ans -= here[cur].end() - upper_bound(here[cur].begin(), here[cur].end(), -add[cur]);
			//cerr << ans << endl;
			here[cur].clear();
			int ind = cur;
			while (ind != -1 && (ind == cur || whom[ind] == cur)) {
				if (!rest[ind]) {
					here[cur].push_back(arr[ind]);
				}
				ind = parent[ind];
			}
			sort(here[cur].begin(), here[cur].end());
			ans += here[cur].end() - upper_bound(here[cur].begin(), here[cur].end(), -add[cur]);
			//cerr << cur << " " << ans << " " << szof(here[cur]) << endl;

			int l = path_n[num];
			for (int j = 0; j < szof(choosen[l]) && choosen[l][j] != cur; ++j) {
				int tmp = choosen[l][j];
				ans -= here[tmp].end() - upper_bound(here[tmp].begin(), here[tmp].end(), -add[tmp]);
				add[tmp] += change;
				ans += here[tmp].end() - upper_bound(here[tmp].begin(), here[tmp].end(), -add[tmp]);
			}
			num = parent[paths[l].front()];
			//cerr << ans << endl;

		}

		cout << ans << " ";
	}
	cout << "\n";
}


int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);
	cerr << fixed << setprecision(15);
	cout << fixed << setprecision(15);
	ios::sync_with_stdio(false);

	int tests = 1;
	// cin >> tests;
	for (int it = 1; it <= tests; ++it) {
		solve();
	}
	
	#ifdef LOCAL
		cerr << "time: " << clock() << " ms\n";
	#endif
	return 0;
}