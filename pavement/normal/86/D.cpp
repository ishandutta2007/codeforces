#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
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
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, T, BS, curr, A[200005], L[200005], R[200005], idx[200005], ans[200005], cnt[10000005];
tuple<int, int, int> S[200005];

void addl(int x) {
	curr -= A[x] * cnt[A[x]] * cnt[A[x]];
	cnt[A[x]]++;
	curr += A[x] * cnt[A[x]] * cnt[A[x]];
	// add leftmost element (index at x)
}

void addr(int x) {
	curr -= A[x] * cnt[A[x]] * cnt[A[x]];
	cnt[A[x]]++;
	curr += A[x] * cnt[A[x]] * cnt[A[x]];
	// add rightmost element (index at x)
}

void reml(int x) {
	curr -= A[x] * cnt[A[x]] * cnt[A[x]];
	cnt[A[x]]--;
	curr += A[x] * cnt[A[x]] * cnt[A[x]];
	// remove leftmost element (index at x)
}

void remr(int x) {
	curr -= A[x] * cnt[A[x]] * cnt[A[x]];
	cnt[A[x]]--;
	curr += A[x] * cnt[A[x]] * cnt[A[x]];
	// remove rightmost element (index at x)
}

main() {
	cin >> N >> T;
	BS = sqrt(N);
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= T; i++) {
		cin >> L[i] >> R[i];
		S[i] = mt(L[i], R[i], i);
	}
	sort(S + 1, S + 1 + T, [](const auto &lhs, const auto &rhs) {
		auto lp = mp(g0(lhs) / BS, (g0(lhs) / BS & 1) ? -g1(lhs) : g1(lhs)), rp = mp(g0(rhs) / BS, (g0(rhs) / BS & 1) ? -g1(rhs) : g1(rhs));
		return lp < rp;
	});
	for (int i = 1; i <= T; i++)
		tie(L[i], R[i], idx[i]) = S[i];
	for (int i = L[1]; i <= R[1]; i++) addr(i);
	ans[idx[1]] = curr;
	for (int i = 2; i <= T; i++) {
		if (R[i] >= R[i - 1]) {
			for (int j = R[i - 1] + 1; j <= R[i]; j++) addr(j);
			if (L[i] <= L[i - 1]) for (int j = L[i - 1] - 1; j >= L[i]; j--) addl(j);
			else for (int j = L[i - 1]; j < L[i]; j++) reml(j);
		} else {
			if (L[i] <= L[i - 1]) for (int j = L[i - 1] - 1; j >= L[i]; j--) addl(j);
			else for (int j = L[i - 1]; j < L[i]; j++) reml(j);
			for (int j = R[i - 1]; j > R[i]; j--) remr(j);
		}
		ans[idx[i]] = curr;
	}
	for (int i = 1; i <= T; i++) cout << ans[i] << '\n';
}