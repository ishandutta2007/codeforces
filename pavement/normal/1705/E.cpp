#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
// #define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
#define g4(a) get<4>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

const int LIM = 2e5 + 100;
int N, Q, A[200005], T[200005], ans[200005], ft1[LIM + 5], ft2[LIM + 5];
stack<iii> st;

int ls(int x) { return x & -x; }

int ft_qry(int k) { // sum of range [1, p]
    int r = 0;
    for (int p = k; p; p -= ls(p)) r += ft1[p] * k - ft2[p];
    return r;
}

void ft_upd(int l, int r, int v) { // add v to range [l, r]
	// cout << "UPD " << l << ' ' << r << ' ' << v << '\n';
	for (int p = l; p <= LIM; p += ls(p)) {
        ft1[p] += v;
        ft2[p] += v * (l - 1);
    }
    for (int p = r + 1; p <= LIM; p += ls(p)) {
        ft1[p] -= v;
        ft2[p] -= v * r;
    }
}

struct node {
	node *left, *right;
	int S, E;
	vector<int> val;
	node(int _s, int _e) : S(_s), E(_e) {
		if (S == E) return;
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
	}
	void upd(int l, int r, int v) {
		if (l > E || r < S) return;
		if (l <= S && E <= r) {
			val.pb(v);
			return;
		}
		left->upd(l, r, v);
		right->upd(l, r, v);
	}
	void dfs() {
		for (int i : val) {
			// add element i
			int lo = 0, hi = LIM - i + 1, ans = -1;
			while (lo <= hi) {
				int mid = (lo + hi) >> 1;
				if (ft_qry(i + mid - 1) - ft_qry(i - 1) == mid) ans = mid, lo = mid + 1;
				else hi = mid - 1;
			}
			assert(ans != -1);
			// cout << "+ " << i << ' ' << ans << '\n';
			if (ans) ft_upd(i, i + ans - 1, -1);
			ft_upd(i + ans, i + ans, 1);
			if (ans) st.emplace(i, i + ans - 1, i + ans);
			else st.emplace(-1, -1, i + ans);
		}
		if (S == E) {
			int lo = 0, hi = LIM, c_ans = -1, tmp = ft_qry(LIM);
			while (lo <= hi) {
				int mid = (lo + hi) >> 1;
				if (ft_qry(mid) == tmp) c_ans = mid, hi = mid - 1;
				else lo = mid + 1;
			}
			assert(c_ans != -1);
			ans[S] = c_ans;
		} else {
			left->dfs();
			right->dfs();
		}
		for (int i : val) {
			// rollback
			auto [a, b, c] = st.top();
			st.pop();
			if (a != -1) ft_upd(a, b, 1);
			ft_upd(c, c, -1);
		}
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> A[i];
	root = new node(0, Q);
	for (int k, l, i = 1; i <= Q; i++) {
		cin >> k >> l;
		// cout << "+ " << T[k] << ' ' << i - 1 << ' ' << A[k] << '\n';
		root->upd(T[k], i - 1, A[k]);
		A[k] = l;
		T[k] = i;
	}
	for (int i = 1; i <= N; i++) {
		// cout << "+ " << T[i] << ' ' << Q << ' ' << A[i] << '\n';
		root->upd(T[i], Q, A[i]);
	}
	root->dfs();
	for (int i = 1; i <= Q; i++)
		cout << ans[i] << '\n';
}