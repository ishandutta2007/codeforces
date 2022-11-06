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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, a[300005], b[300005], dist[300005][2], from[300005][2];
set<int> S;
priority_queue<iii, vector<iii>, greater<iii> > pq;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i <= N; i++) {
		S.insert(i);
		dist[i][0] = dist[i][1] = 1e9;
	}
	for (int i = 1; i <= N; i++) cin >> a[i];
	for (int i = 1; i <= N; i++) cin >> b[i];
	pq.emplace(0, N, 1);
	dist[N][1] = 0;
	while (!pq.empty()) {
		vector<set<int>::iterator> del;
		auto [d, v, s] = pq.top();
		pq.pop();
		if (dist[v][s] != d) continue;
		if (s) {
			auto it = S.lower_bound(v - a[v]);
			while (it != S.end() && *it <= v) {
				del.pb(it);
				from[*it][0] = v;
				dist[*it][0] = d + 1;
				pq.emplace(d + 1, *it, 0);
				++it;
			}
			for (auto i : del) S.erase(i);
		} else {
			if (d < dist[v + b[v]][1]) {
				from[v + b[v]][1] = v;
				dist[v + b[v]][1] = d;
				pq.emplace(d, v + b[v], 1);
			}
		}
	}
	if (dist[0][0] == 1e9) cout << "-1\n";
	else {
		cout << dist[0][0] << '\n';
		vector<int> out;
		for (int curr = 0, currs = 0; ; ) {
			if (!currs) out.pb(curr);
			curr = from[curr][currs];
			currs ^= 1;
			if (curr == N && currs == 1) break;
		}
		reverse(out.begin(), out.end());
		for (int i : out) cout << i << ' ';
		cout << '\n';
	}
}