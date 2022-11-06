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

int N, ans, curr, off, A[100005], B[100005];
ii T[100005];
bool vis[100005];
priority_queue<iii, vector<iii>, greater<iii> > pq;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i] >> B[i], ans += A[i], T[i] = mp(B[i], A[i]);
	sort(T + 1, T + 1 + N, greater<ii>());
	for (int i = 1; i <= N; i++) tie(B[i], A[i]) = T[i];
	for (int i = 1; i <= N; i++) pq.emplace(B[i], A[i], i);
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		while (!pq.empty() && curr < B[i]) {
			auto [x, y, z] = pq.top();
			if (vis[z] || A[i] - cnt + curr < x) break;
			pq.pop();
			assert(!vis[z]);
			int to = max(0ll, x - curr);
			ans += to;
			curr += to;
			cnt += to;
			vis[z] = 1;
			curr += y;
		}
		vis[i] = 1;
		if (curr >= B[i]) break;
		ans += A[i] - cnt;
		curr += A[i] - cnt;
	}
	cout << ans << '\n';
}