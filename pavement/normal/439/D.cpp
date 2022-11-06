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

int N, M, A[100005], B[100005];

int f(int x) {
	int s = 0;
	for (int i = 1; i <= N; i++)
		s += max(0ll, x - A[i]);
	for (int i = 1; i <= M; i++)
		s += max(0ll, B[i] - x);
	return s;
}

int ternary_search(int l, int r) {
    while (r - l >= 3) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        int f1 = f(m1); // evaluates the function at m1
        int f2 = f(m2); // evaluates the function at m2
        if (f1 > f2) l = m1;
        else r = m2;
    }
    int ans = 1e16; // set -INF to a sufficiently small value
    for (int i = l; i <= r; i++) ans = min(ans, f(i));
    return ans; // return the maximum of f(x) in [l, r]
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= M; i++) cin >> B[i];
	cout << ternary_search(1, 1e9);
}