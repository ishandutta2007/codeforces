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

int T, N, A[300005], B[2][300005], flog[2][300005], st[2][300005][25];

ii combine(ii a, ii b) {
	if (a.first != b.first) return min(a, b);
	else return mp(a.first, a.second + b.second);
}

struct node {
	node *left, *right;
	int S, E;
	ii val;
	node(int _s, int _e, int p) : S(_s), E(_e) {
		if (S == E) {
			val = mp((int)1e16, 1ll);
			return;
		}
		int M = (S + E) >> 1;
		left = new node(S, M, p);
		right = new node(M + 1, E, p);
		val = combine(left->val, right->val);
	}
	void upd(int p, int v) {
		if (S == E) {
			val = mp(v, 1ll);
			return;
		}
		int M = (S + E) >> 1;
		if (p <= M) left->upd(p, v);
		else right->upd(p, v);
		val = combine(left->val, right->val);
	}
	ii qry(int l, int r) {
		if (l > E || r < S) return mp((int)1e16, -1ll);
		if (l <= S && E <= r) return val;
		return combine(left->qry(l, r), right->qry(l, r));
	}
} *root[2];

void build(int v) { // array A stores the original array, must be 1-indexed
    for (int i = 2; i <= N; i++)
        flog[v][i] = flog[v][i >> 1] + 1; 
    for (int i = 1; i <= N; i++)
        st[v][i][0] = B[v][i];
    for (int j = 1; (1 << j) <= N; j++)
        for (int i = 1; i + (1 << j) - 1 <= N; i++)
            st[v][i][j] = min(st[v][i][j - 1], st[v][i + (1 << (j - 1))][j - 1]);
}

int qry(int v, int l, int r) { // minimum element in range [l, r]
    int j = flog[v][r - l + 1];
    return min(st[v][l][j], st[v][r - (1 << j) + 1][j]);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		int tans = 0;
		for (int i = 1; i <= N; i++) cin >> A[i];
		int delt1 = 0, delt0 = 0;
		root[0] = new node(1, N, 0);
		root[1] = new node(1, N, 1);
		for (int i = N; i >= 1; i--) {
			if (i & 1) {
				delt1 += A[i];
				delt0 -= A[i];
			} else {
				delt1 -= A[i];
				delt0 += A[i];
			}
			B[i & 1][i] = A[i] - ((i & 1) ? delt1 : delt0);
			B[i & 1 ^ 1][i] = 1e16;
			root[i & 1]->upd(i, A[i] - ((i & 1) ? delt1 : delt0));
		}
		//cout << "&\n";
		build(0);
		build(1);
		delt1 = 0, delt0 = 0;
		for (int i = N; i >= 1; i--) {
			if (i & 1) {
				delt1 += A[i];
				delt0 -= A[i];
			} else {
				delt1 -= A[i];
				delt0 += A[i];
			}
			int lo = i, hi = N, ans = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (qry(0, i, mid) + delt0 >= 0 && qry(1, i, mid) + delt1 >= 0) ans = mid, lo = mid + 1;
				else hi = mid - 1;
			}
			//cout << i << ' ' << ans << '\n';
			auto tmp = root[0]->qry(i, ans);
			//cout << tmp.first << ' ' << tmp.second << '\n';
			if (tmp.first + delt0 == 0) tans += tmp.second;
			tmp = root[1]->qry(i, ans);
			//cout << tmp.first << ' ' << tmp.second << '\n';
			if (tmp.first + delt1 == 0) tans += tmp.second;
			//cout << tans << '\n';
		}
		cout << tans << '\n';
	}
}