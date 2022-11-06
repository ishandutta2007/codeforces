#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define ins insert
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int T, N, M, A[55][55];
bool hv[55], chv[55], yes[55], ryes[55];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++)
				cin >> A[i][j];
		}
		for (int i = 1; i <= N; i++) {
			hv[i] = 0;
			for (int j = 1; j <= M; j++)
				hv[i] |= A[i][j];
		}
		for (int j = 1; j <= M; j++) {
			chv[j] = 0;
			for (int i = 1; i <= N; i++)
				chv[j] |= A[i][j];
		}
		int cnt = 0;
		memset(yes, 0, sizeof yes);
		memset(ryes, 0, sizeof ryes);
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				if (!hv[i] && !chv[j]) {
					if (yes[i] || ryes[j]) continue;
					yes[i] = ryes[j] = 1;
					cnt++;
			}
		cout << (cnt & 1 ? "Ashish" : "Vivek") << '\n';
	}
}