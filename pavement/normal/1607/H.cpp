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

int T, N, ans, A[200005], B[200005], M[200005], ch[200005];
map<int, vector<iii> > V;
set<int> S;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		ans = 0;
		V.clear();
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> A[i] >> B[i] >> M[i];
			V[A[i] + B[i] - M[i]].eb(A[i] - min(M[i], A[i]), 0ll, i);
			V[A[i] + B[i] - M[i]].eb(A[i] - max(0ll, M[i] - B[i]), 1ll, i);
		}
		for (auto i : V) {
			S.clear();
			sort(i.second.begin(), i.second.end());
			for (auto j : i.second) {
				if (g1(j)) {
					if (S.count(g2(j))) {
						ans++;
						for (auto k : S) ch[k] = g0(j);
						S.clear();
					}
				} else S.insert(g2(j));
			}
		}
		cout << ans << '\n';
		for (int i = 1; i <= N; i++)
			cout << A[i] - ch[i] << ' ' << M[i] - (A[i] - ch[i]) << '\n';
	}
}