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
#define pf push_front
#define ppb pop_back
#define ppf pop_front
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

int T, N, M, A[100005], B[100005], C[100005], pnt[100005], yes[100005], tmp[100005], latest[100005];
bool has[100005], complete[100005];
vector<int> need[100005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 1; i <= N; i++) cin >> A[i];
		for (int i = 1; i <= N; i++) cin >> B[i], has[B[i]] = 1;
		for (int i = 1; i <= M; i++) cin >> C[i];
		for (int i = 1; i <= N; i++) {
			if (A[i] == B[i]) complete[A[i]] = 1, tmp[A[i]] = i;
			else need[B[i]].pb(i);
		}
		for (int i = 1; i <= M; i++) {
			if (has[C[i]]) {
				if (complete[C[i]] && need[C[i]].size() == 0) yes[i] = tmp[C[i]], pnt[tmp[C[i]]] = i;
				else {
					assert(need[C[i]].size() > 0);
					if (need[C[i]].size() == 1) {
						yes[i] = need[C[i]].back();
						pnt[need[C[i]].back()] = i;
						complete[C[i]] = 1;
						tmp[C[i]] = need[C[i]].back();
						need[C[i]].ppb();
					} else {
						yes[i] = need[C[i]].back();
						pnt[need[C[i]].back()] = i;
						need[C[i]].ppb();
					}
				}
			}
		}
		int target = -1;
		for (int i = 1; i <= N; i++) {
			if (pnt[i] == M) {
				target = i;
				break;
			}
		}
		for (int i = 1; i <= N; i++)
			if (B[i] != (pnt[i] == 0 ? A[i] : C[pnt[i]]))
				target = -1;
		if (target == -1) {
			cout << "NO\n";
			for (int i = 1; i <= max(N, M); i++) {
				pnt[i] = has[i] = complete[i] = A[i] = B[i] = C[i] = yes[i] = tmp[i] = latest[i] = 0;
				need[i].clear();
			}
			continue;
		}
		cout << "YES\n";
		for (int i = 1; i <= M; i++) {
			if (has[C[i]]) cout << yes[i] << ' ';
			else cout << target << ' ';
		}
		cout << '\n';
		for (int i = 1; i <= max(N, M); i++) {
			pnt[i] = has[i] = complete[i] = A[i] = B[i] = C[i] = yes[i] = tmp[i] = latest[i] = 0;
			need[i].clear();
		}
	}
}