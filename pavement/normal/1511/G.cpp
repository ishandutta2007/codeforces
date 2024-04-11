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

int N, M, Q, P[200005], val[200005][25];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1, C; i <= N; i++) {
		cin >> C;
		P[C]++;
	}
	for (int i = 1; i <= M; i++) P[i] += P[i - 1];
	for (int j = 1; j <= 20; j++)
		for (int i = 1; i <= M; i++)
			if (i + (1ll << j) - 1 <= M)
				val[i][j] = val[i][j - 1] ^ val[i + (1ll << (j - 1))][j - 1] ^ ((P[i + (1ll << j) - 1] - P[i + (1ll << (j - 1)) - 1]) & 1 ? (1ll << (j - 1)) : 0);
	cin >> Q;
	for (int i = 1, l, r, ans; i <= Q; i++) {
		cin >> l >> r;
		ans = 0;
		for (int c = l; c <= r; )
			for (int k = 20; k >= 0; k--)
				if (c + (1ll << k) - 1 <= r) {
					ans ^= val[c][k];
					if ((P[r] - P[c + (1ll << k) - 1]) & 1) ans ^= (1ll << k);
					c += (1ll << k);
					break;
				}
		cout << (ans ? 'A' : 'B');
	}
	cout << '\n';
}