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

int N, A[200005];

int rec(int b, int l, int r) {
	if (b == -1 || l > r) return 1e9;
	if (b == 0) return 0;
	int ecnt = 0;
	vector<int> nv;
	for (int i = l; i <= r; i++)
		if (!(A[i] & (1 << b))) ecnt++;
	nv.resize(r - l + 1);
	for (int i = l, idx1 = 0, idx2 = ecnt; i <= r; i++)
		if (A[i] & (1 << b)) nv[idx2++] = A[i];
		else nv[idx1++] = A[i];
	for (int i = 0; i < r - l + 1; i++) A[i + l] = nv[i];
	int lr = rec(b - 1, l, l + ecnt - 1), rr = rec(b - 1, l + ecnt, r);
	if (ecnt > 1 && ecnt < r - l + 1) return min(lr + (r - l - ecnt), rr + (ecnt - 1));
	else return (ecnt > r - l + 1 - ecnt ? lr : rr);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	cout << rec(30, 1, N) << '\n';
}