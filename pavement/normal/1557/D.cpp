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

int N, M, curr, frnt;
bool seen[300005];
ii dp[300005];
vector<int> tmp;
vector<iii> tmp2;
vector<ii> vec[300005];

struct node {
	node *left = nullptr, *right = nullptr;
	int S, E;
	ii val, pv;
	node(int _s, int _e) : S(_s), E(_e), val(0ll, 0ll), pv(0ll, 0ll) {
		if (S == E) return;
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
	}
	void prop() {
		if (S == E || pv == mp(0ll, 0ll)) return;
		left->val = max(left->val, pv);
		left->pv = max(left->pv, pv);
		right->val = max(right->val, pv);
		right->pv = max(right->pv, pv);
		pv = mp(0ll, 0ll);
	}
	void upd(int l, int r, ii v) {
		if (l > E || r < S) return;
		if (l <= S && E <= r) {
			val = max(val, v);
			pv = max(pv, v);
			return;
		}
		prop();
		left->upd(l, r, v);
		right->upd(l, r, v);
		val = max(left->val, right->val);
	}
	ii qry(int l, int r) {
		if (l > E || r < S) return mp(0ll, 0ll);
		if (l <= S && E <= r) {
			return val;
		}
		prop();
		return max(left->qry(l, r), right->qry(l, r));
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1, x, l, r; i <= M; i++) {
		cin >> x >> l >> r;
		tmp.pb(l);
		tmp.pb(r);
		tmp2.eb(x, l, r);
	}
	sort(tmp.begin(), tmp.end());
	for (auto [x, l, r] : tmp2) {
		l = lower_bound(tmp.begin(), tmp.end(), l) - tmp.begin() + 1;
		r = lower_bound(tmp.begin(), tmp.end(), r) - tmp.begin() + 1;
		vec[x].eb(l, r);
	}
	root = new node(1, 2 * M);
	for (int i = 1; i <= N; i++) {
		//for (auto j : vec[i]) cout << j.first << ' ' << j.second << '\n';
		//cout << "--\n";
		for (auto j : vec[i]) {
			//cout << j.first << ' ' << j.second << '\n';
			//cout << "QRY " << j.first << ' ' << j.second << ' ' << root->qry(j.first, j.second).first << ' ' << root->qry(j.first, j.second).second << '\n';
			dp[i] = max(dp[i], root->qry(j.first, j.second));
			//cout << j.first << ' ' << j.second << '\n';
		}
		dp[i].first++;
		for (auto j : vec[i]) {
			//cout << "UPD " << j.first << ' ' << j.second << ' ' << dp[i].first << ' ' << dp[i].second << '\n';
			root->upd(j.first, j.second, mp(dp[i].first, i));
		}
		if (dp[i].first > curr) {
			curr = dp[i].first;
			frnt = i;
		}
		//cout << "DP " << i << ' ' << dp[i].first << ' ' << dp[i].second << '\n';
	}
	cout << N - curr << '\n';
	while (frnt != 0) {
		seen[frnt] = 1;
		frnt = dp[frnt].second;
	}
	for (int i = 1; i <= N; i++) if (!seen[i]) cout << i << ' ';
	cout << '\n';
}