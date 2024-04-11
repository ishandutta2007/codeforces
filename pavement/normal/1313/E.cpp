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
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

const int p = 31, MOD = 998244353;
int N, M, ans, powp[1000005], invp[1000005], phshA[1000005], phshB[1000005], phshS[1000005], shshS[1000005];
char A, B, S;
vector<int> to_add[1000005], to_del[1000005];

int exp_mod(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1ll) r = r * a % MOD;
		a = a * a % MOD;
		b >>= 1ll;
	}
	return r;
}

int hshA(int l, int r) {
	return ((phshA[r] - phshA[l - 1]) * invp[l - 1] % MOD + MOD) % MOD;
}

int hshB(int l, int r) {
	return ((phshB[r] - phshB[l - 1]) * invp[l - 1] % MOD + MOD) % MOD;
}

struct node {
	node *left, *right;
	int S, E, val, active_count, pv;
	node(int _s, int _e) : S(_s), E(_e), val(0), active_count(0), pv(0) {
		if (S == E) return;
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
	}
	void prop() {
		if (S == E || !pv) return;
		left->val += left->active_count * pv;
		left->pv += pv;
		right->val += right->active_count * pv;
		right->pv += pv;
		pv = 0;
	}
	void upd(int l, int r) {
		if (l > E || r < S) return;
		if (l <= S && E <= r) {
			val += active_count;
			pv++;
			return;
		}
		prop();
		left->upd(l, r);
		right->upd(l, r);
		val = left->val + right->val;
	}
	void activate(int p) {
		if (S == E) {
			active_count++;
			return;
		}
		prop();
		int M = (S + E) >> 1;
		if (p <= M) left->activate(p);
		else right->activate(p);
		active_count = left->active_count + right->active_count;
	}
	void deactivate(int p) {
		if (S == E) {
			active_count--;
			val = 0;
			return;
		}
		prop();
		int M = (S + E) >> 1;
		if (p <= M) left->deactivate(p);
		else right->deactivate(p);
		active_count = left->active_count + right->active_count;
		val = left->val + right->val;
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	powp[0] = invp[0] = 1;
	for (int i = 1; i <= max(N, M); i++) {
		powp[i] = powp[i - 1] * p % MOD;
		invp[i] = exp_mod(powp[i], MOD - 2);
	}
	for (int i = 1; i <= N; i++) {
		cin >> A;
		A = A - 'a' + 1;
		phshA[i] = phshA[i - 1] + powp[i - 1] * A;
		phshA[i] %= MOD;
	}
	for (int i = 1; i <= N; i++) {
		cin >> B;
		B = B - 'a' + 1;
		phshB[i] = phshB[i - 1] + powp[i - 1] * B;
		phshB[i] %= MOD;
	}
	for (int i = 1; i <= M; i++) {
		cin >> S;
		S = S - 'a' + 1;
		phshS[i] = phshS[i - 1] + powp[i - 1] * S;
		phshS[i] %= MOD;
	}
	for (int i = 1; i <= M; i++)
		shshS[i] = ((phshS[M] - phshS[M - i]) * invp[M - i] % MOD + MOD) % MOD;
	root = new node(1, N);
	for (int i = 1; i <= N; i++) {
		int lo = i, hi = min(N, i + M - 2), ans = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (hshA(i, mid) == phshS[mid - i + 1]) ans = mid, lo = mid + 1;
			else hi = mid - 1;
		}
		if (ans != -1) {
			root->activate(i);
			to_del[ans - i + 1].pb(i);
		}
	}
	for (int i = 1; i <= N; i++) {
		int lo = max(1ll, i - M + 2), hi = i, ans = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (hshB(mid, i) == shshS[i - mid + 1]) ans = mid, hi = mid - 1;
			else lo = mid + 1;
		}
		if (ans != -1) {
			to_add[M - (i - ans + 1)].pb(i);
		}
	}
	for (int x = 1; x < M; x++) {
		for (int i : to_add[x])
			root->upd(max(1ll, i - M + 2), i);
		ans += root->val;
		for (int i : to_del[x])
			root->deactivate(i);
	}
	cout << ans << '\n';
}