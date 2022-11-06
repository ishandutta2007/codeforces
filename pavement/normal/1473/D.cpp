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

int T, N, M, P[200005], S[200005], SM[200005], mn[200005], mx[200005];
char c[200005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		memset(P, 0, sizeof P);
		memset(S, 0, sizeof S);
		memset(SM, 0, sizeof SM);
		memset(mn, 0, sizeof mn);
		memset(mx, 0, sizeof mx);
		memset(c, 0, sizeof c);
		cin >> N >> M;
		mn[0] = 0;
		mx[0] = 0;
		for (int i = 1; i <= N; i++) {
			cin >> c[i];
			if (c[i] == '+') P[i] = P[i - 1] + 1;
			else P[i] = P[i - 1] - 1;
			mx[i] = max(mx[i - 1], P[i]);
			mn[i] = min(mn[i - 1], P[i]);
		}
		S[N + 1] = LLONG_MIN;
		SM[N + 1] = LLONG_MAX;
		for (int i = N; i >= 1; i--) {
			S[i] = max(S[i + 1], P[i]);
			SM[i] = min(SM[i + 1], P[i]);
		}
		for (int i = 1, l, r; i <= M; i++) {
			cin >> l >> r;
			if (l == 1 && r == N) {
				cout << "1\n";
				continue;
			}
			int l1, r1, l2, r2;
			if (l > 1) {
				l1 = mn[l - 1];
				r1 = mx[l - 1];
				if (r == N) {
					cout << r1 - l1 + 1 << '\n';
					continue;
				}
				l2 = SM[r + 1] - P[r] + P[l - 1];
				r2 = S[r + 1] - P[r] + P[l - 1];
				if (l1 > l2) {
					swap(l1, l2);
					swap(r1, r2);
				}
				//cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << '\n';
				if (r1 >= r2) {
					cout << r1 - l1 + 1 << '\n';
				} else {
					cout << r2 - l1 + 1 << '\n';
				}
			} else {
				l2 = min(0ll, SM[r + 1] - P[r]);
				r2 = max(0ll, S[r + 1] - P[r]);
				cout << r2 - l2 + 1 << '\n';
			}
		}
	}
}