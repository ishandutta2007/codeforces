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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int T, N, D, K[100005];
bool yes[200005];
bool done;
map<int, int> pig[200005];
vector<int> chng, vec[100005];
vector<iii> tot;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		done = 0;
		tot.clear();
		D = sqrt(N);
		for (int i : chng) pig[i].clear();
		chng.clear();
		memset(yes, 0, sizeof yes);
		for (int i = 1; i <= N; i++) {
			cin >> K[i];
			vec[i].clear();
			for (int j = 0, x; j < K[i]; j++) {
				cin >> x;
				vec[i].pb(x);
			}
			sort(vec[i].begin(), vec[i].end());
			for (int j = 0; j < K[i]; j++)
				tot.eb(vec[i][j], i, j);
		}
		sort(tot.begin(), tot.end());
		for (int i = 0, cnt = 0, prv = -1; i < tot.size(); i++) {
			if (prv != g0(tot[i])) cnt++;
			vec[g1(tot[i])][g2(tot[i])] = cnt;
			prv = g0(tot[i]);
		}
		for (int i = 1; i <= N; i++) {
			if (K[i] < D) continue;
			for (int j : vec[i]) yes[j] = 1;
			for (int j = 1; j <= N; j++) {
				int cnt = 0;
				if (i == j) continue;
				for (int k : vec[j])
					if (yes[k]) cnt++;
				if (cnt >= 2) {
					cout << i << ' ' << j << '\n';
					done = 1;
					goto fin;
				}
			}
			for (int j : vec[i]) yes[j] = 0;
		}
		for (int i = 1; i <= N; i++) {
			if (K[i] >= D) continue;
			for (int j = 0; j < K[i]; j++)
				for (int k = j + 1; k < K[i]; k++) {
					if (pig[vec[i][j]].find(vec[i][k]) != pig[vec[i][j]].end()) {
						cout << pig[vec[i][j]][vec[i][k]] << ' ' << i << '\n';
						done = 1;
						goto fin;
					}
					chng.pb(vec[i][j]);
					pig[vec[i][j]][vec[i][k]] = i;
				}
		}
		fin:
			if (!done) cout << "-1\n";
	}
}