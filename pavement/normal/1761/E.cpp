#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
#define g4(a) get<4>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

int T, N, timer, deg[4005], tin[4005], low[4005], lnk[4005], sz[4005];
bool visited[4005], art[4005];
char c;
vector<int> adj[4005];

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p != -1)
                art[v] = 1;
            ++children;
        }
    }
    if (p == -1 && children > 1)
        art[v] = 1;
}

void find_cutpoints() {
    timer = 0;
    for (int i = 1; i <= N; i++) {
		visited[i] = art[i] = 0;
		tin[i] = low[i] = -1;
	}
    for (int i = 1; i <= N; i++) {
        if (!visited[i])
            dfs (i);
    }
}

int find(int x) {
	if (x == lnk[x]) return x;
	return lnk[x] = find(lnk[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (sz[b] > sz[a]) swap(a, b);
	sz[a] += sz[b];
	lnk[b] = a;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			lnk[i] = i;
			sz[i] = 1;
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> c;
				if (c == '1') {
					unite(i, j);
					adj[i].pb(j);
					adj[j].pb(i);
					deg[i]++;
				}
			}
		}
		find_cutpoints();
		int ans = 2, v_1 = -1, ncmp = 0;
		ii min_sz = mp(LLONG_MAX, -1ll);
		for (int i = 1; i <= N; i++) {
			if (!art[i] && deg[i] != sz[find(i)] - 1) ans = 1, v_1 = i;
		}
		for (int i = 1; i <= N; i++) {
			if (i == find(i)) ncmp++;
			if (sz[find(i)] == N) ans = min(ans, 0ll);
			else min_sz = min(min_sz, mp(sz[find(i)], find(i)));
		}
		if (ans == 2) {
			for (int i = 1; i <= N; i++) {
				assert(deg[i] == sz[find(i)] - 1);
			}
			if (min_sz.first <= 2 || ncmp == 2) {
				cout << min_sz.first << '\n';
				for (int i = 1; i <= N; i++) {
					if (find(i) == min_sz.second) cout << i << ' ';
				}
				cout << '\n';
			} else {
				cout << "2\n";
				for (int i = 1; i <= N; i++)
					if (find(i) == min_sz.second) {
						cout << i << ' ';
						break;
					}
				for (int i = 1; i <= N; i++)
					if (find(i) != min_sz.second) {
						cout << i << ' ';
						break;
					}
				cout << '\n';
					
			}
		} else if (ans == 1) {
			cout << ans << '\n' << v_1 << '\n';
		} else {
			cout << "0\n";
		}
		for (int i = 1; i <= N; i++) {
			adj[i].clear();
			deg[i] = 0;
		}
	}
}