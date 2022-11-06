#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
#define int unsigned long long
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
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 998244353;
int N, M, ans, tcnt[200005], cnt[200005], S[200005], T[200005], ft[200005], fac[200005], invfac[200005];

int exp_mod(int a, int b) {
	int r = 1ll;
	while (b) {
		if (b & 1ll) r = r * a % MOD;
		a = a * a % MOD;
		b >>= 1ll;
	}
	return r;
}

inline int ls(int x) { return x & -x; }

int qry(int p) {
	int r = 0;
	for (; p; p -= ls(p)) r += ft[p], r %= MOD;
	return r;
}

void upd(int p, int v) {
	for (; p <= 200000; p += ls(p)) ft[p] += v, ft[p] %= MOD;
}

struct node {
	node *left, *right;
	int S, E, val;
	node(int _s, int _e) : S(_s), E(_e) {
		if (S == E) {
			val = invfac[0];
			return;
		}
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
		val = left->val * right->val % MOD;
	}
	void set(int p, int v) {
		if (S == E) {
			val = v;
			return;
		}
		int M = (S + E) >> 1;
		if (p <= M) left->set(p, v);
		else right->set(p, v);
		val = left->val * right->val % MOD;
	}
	int qry(int l, int r) {
		if (l < E || r > S) return 1;
		if (l <= S && E <= r) return val;
		return left->qry(l, r) * right->qry(l, r) % MOD;
	}
} *root;

main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    fac[0] = invfac[0] = 1;
    for (int i = 1; i <= 200000; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		invfac[i] = exp_mod(fac[i], MOD - 2);
	}
    for (int i = 1; i <= N; i++) {
		cin >> S[i];
		upd(S[i], 1);
		cnt[S[i]]++;
		tcnt[S[i]]++;
	}
	root = new node(1, 200000);
	for (int i = 1; i <= 200000; i++)
		root->set(i, invfac[cnt[i]]);
    for (int i = 1; i <= M; i++) cin >> T[i];
   	if (N < M) {
		bool inv = 0;
		for (int i = 1; i <= N; i++) {
			if (tcnt[T[i]]) tcnt[T[i]]--;
			else {
				inv = 1;
				break;
			}
		}
		if (!inv) ans++;
	}
	for (int i = 0; i <= min(N - 1, M - 1); i++) {
		int con = fac[N - i - 1] * root->val % MOD;
		ans += con * qry(T[i + 1] - 1) % MOD;
		ans %= MOD;
		if (cnt[T[i + 1]]) {
			cnt[T[i + 1]]--;
			upd(T[i + 1], -1);
			root->set(T[i + 1], invfac[cnt[T[i + 1]]]);
		} else break;
	}
	cout << ans << '\n';
}