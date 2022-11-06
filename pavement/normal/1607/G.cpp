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

int T, N, M, lr, rr, sA, sB, q, A[200005], B[200005], L[200005], R[200005];
ii ans;
vector<ii> out;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		lr = rr = sA = sB = 0;
		for (int i = 1; i <= N; i++) {
			cin >> A[i] >> B[i];
			sA += A[i];
			sB += B[i];
			lr += max(0ll, M - B[i]);
			rr += min(M, A[i]);
			L[i] = lr;
			R[i] = rr;
		}
		q = sA - sB + N * M;
		ans = min(mp(llabs(q - 2 * lr), lr), mp(llabs(q - 2 * rr), rr));
		if (lr <= q / 2 && q / 2 <= rr)
			ans = min(ans, mp(llabs(q - 2 * (q / 2)), q / 2));
		cout << ans.first << '\n';
		out.clear();
		for (int i = N; i >= 1; i--) {
			assert(max(max(0ll, M - B[i]), ans.second - R[i - 1]) <= min(min(M, A[i]), ans.second - L[i - 1]));
			out.eb(max(max(0ll, M - B[i]), ans.second - R[i - 1]), M - max(max(0ll, M - B[i]), ans.second - R[i - 1]));
			ans.second -= max(max(0ll, M - B[i]), ans.second - R[i - 1]);
		}
		reverse(out.begin(), out.end());
		for (auto i : out) cout << i.first << ' ' << i.second << '\n';
	}
}