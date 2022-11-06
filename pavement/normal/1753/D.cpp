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
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

int N, M, P, Q, ans = LLONG_MAX, dist[300005][4], dr[] = {-1, 0, 0, 1}, dc[] = {0, -1, 1, 0};
char C[300005];
vector<iii> adj[300005][4];
priority_queue<iii, vector<iii>, greater<iii> > pq;

int conv(int r, int c) {
	return (r - 1) * M + c;
}

int inv(int k) {
	return 3 - k;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> P >> Q;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> C[conv(i, j)];
		}
	}
	//~ cout << '.' << endl;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			for (int k = 0; k < 4; k++)
				dist[conv(i, j)][k] = (int)1e16;
	//~ cout << '.' << endl;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			for (int dir = 0; dir < 4; dir++) {
				if (C[conv(r, c)] == '#') continue;
				if (C[conv(r, c)] == '.') continue;
				set<ii> bad, good;
				bad.emplace(r, c);
				bad.emplace(r + dr[inv(dir)], c + dc[inv(dir)]);
				good.emplace(r, c);
				bool eqr = 0, eqc = 0;
				if (C[conv(r, c)] == 'U') good.emplace(r + 1, c), eqc = 1;
				else if (C[conv(r, c)] == 'D') good.emplace(r - 1, c), eqc = 1;
				else if (C[conv(r, c)] == 'L') good.emplace(r, c + 1), eqr = 1;
				else good.emplace(r, c - 1), eqr = 1;
				for (auto [fr, fc] : good) {
					// fix [fr, fc]
					if (bad.count(mp(fr, fc))) continue;
					for (int k = 0; k < 4; k++) {
						int nfr = fr + dr[k], nfc = fc + dc[k];
						if (!bad.count(mp(nfr, nfc))) {
							int cst;
							if ((nfr == fr && eqr) || (nfc == fc && eqc)) cst = Q;
							else cst = P;
							if (1 <= nfr && nfr <= N && 1 <= nfc && nfc <= M)
								adj[conv(nfr, nfc)][k].eb(conv(r, c), dir, cst);
						}
					}
				}
			}
		}
	}
	//~ cout << '.';
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (C[conv(i, j)] == '.') {
				for (int k = 0; k < 4; k++) {
					dist[conv(i, j)][k] = 0;
					pq.emplace(0, conv(i, j), k);
				}
			}
		}
	}
	while (!pq.empty()) {
		auto [d, cell, dir] = pq.top();
		pq.pop();
		if (d != dist[cell][dir]) continue;
		for (auto [ncell, ndir, w] : adj[cell][dir]) {
			if (d + w < dist[ncell][ndir]) {
				dist[ncell][ndir] = d + w;
				pq.emplace(d + w, ncell, ndir);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int k = 0; k < 4; k++) {
				//~ cout << dist[conv(i, j)][k] << ' ';
				int ni = i + dr[k], nj = j + dc[k];
				if (1 <= ni && ni <= N && 1 <= nj && nj <= M)
					ans = min(ans, dist[conv(ni, nj)][k] + dist[conv(i, j)][inv(k)]);
			}
			//~ cout << '\n';
		}
	}
	cout << (ans >= (int)1e16 ? -1 : ans) << '\n';
}