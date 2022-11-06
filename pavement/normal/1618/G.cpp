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
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, M, Q, cst, out[400005], link[400005], sz[400005], cnt[400005], P[400005], ll[400005], rr[400005];
ii A[400005], B[400005], C[400005], K[400005], curr[400005];

int find(int x) {
	if (x == link[x]) return x;
	return link[x] = find(link[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	assert(a != b);
	if (sz[b] > sz[a]) swap(a, b);
	
	cst -= P[rr[b]] - P[rr[b] - cnt[b]];
	cst -= P[rr[a]] - P[rr[a] - cnt[a]];
	
	sz[a] += sz[b];
	cnt[a] += cnt[b];
	ll[a] = min(ll[a], ll[b]);
	rr[a] = max(rr[a], rr[b]);
	cst += P[rr[a]] - P[rr[a] - cnt[a]];
	link[b] = a;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> Q;
	for (int i = 1; i <= N; i++) cin >> A[i].first, A[i].second = 0;
	for (int i = 1; i <= M; i++) cin >> B[i].first, B[i].second = 1;
	sort(A + 1, A + 1 + N);
	sort(B + 1, B + 1 + M);
	merge(A + 1, A + 1 + N, B + 1, B + 1 + M, C + 1);
	for (int i = 1; i <= N + M; i++) {
		P[i] = P[i - 1] + C[i].first;
		link[i] = ll[i] = rr[i] = i;
		sz[i] = 1;
		cnt[i] = !C[i].second;
		if (!C[i].second) cst += C[i].first;
	}
	for (int i = 1; i <= Q; i++) {
		cin >> K[i].first;
		K[i].second = i;
	}
	sort(K + 1, K + 1 + Q);
	for (int i = 1; i < N + M; i++)
		curr[i] = mp(C[i + 1].first - C[i].first, i);
	sort(curr + 1, curr + N + M);
	for (int pt = 1, i = 1; i <= Q; i++) {
		while (pt < N + M && curr[pt].first <= K[i].first) {
			unite(curr[pt].second, curr[pt].second + 1);
			pt++;
		}
		out[K[i].second] = cst;
	}
	for (int i = 1; i <= Q; i++) cout << out[i] << '\n';
}