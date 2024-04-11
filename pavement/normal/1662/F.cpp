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

int T, N, A, B, P[200005], L[200005], R[200005], dist[200005];
bool vis[200005];
vector<int> tmpp;
queue<int> Q;

struct node {
	node *left, *right;
	int S, E;
	ii valL, valR;
	node(int _s, int _e) : S(_s), E(_e) {
		if (S == E) {
			valL = mp(L[S], S);
			valR = mp(R[S], S);
			return;
		}
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
		valL = min(left->valL, right->valL);
		valR = max(left->valR, right->valR);
	}
	void del(int p) {
		if (S == E) {
			valL = mp(LLONG_MAX, -1ll);
			valR = mp(LLONG_MIN, -1ll);
			return;
		}
		int M = (S + E) >> 1;
		if (p <=M) left->del(p);
		else right->del(p);
		valL = min(left->valL, right->valL);
		valR = max(left->valR, right->valR);
	}
	ii qryL(int l, int r) {
		if (l > E || r < S) return mp(LLONG_MAX, -1ll);
		if (l <= S && E <= r) return valL;
		return min(left->qryL(l, r), right->qryL(l, r));
	}
	ii qryR(int l, int r) {
		if (l > E || r < S) return mp(LLONG_MIN, -1ll);
		if (l <= S && E <= r) return valR;
		return max(left->qryR(l, r), right->qryR(l, r));
	}
} *root;

void enqueue(int x) {
	auto tmp = root->qryR(L[x], x);
	while (tmp.first >= x) {
		vis[tmp.second] = 1;
		root->del(tmp.second);
		tmpp.pb(tmp.second);
		tmp = root->qryR(L[x], x);
	}
	tmp = root->qryL(x, R[x]);
	while (tmp.first <= x) {
		vis[tmp.second] = 1;
		root->del(tmp.second);
		tmpp.pb(tmp.second);
		tmp = root->qryL(x, R[x]);
	}
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> A >> B;
		for (int i = 1; i <= N; i++) {
			cin >> P[i];
			L[i] = max(1ll, i - P[i]);
			R[i] = min(N, i + P[i]);
		}
		root = new node(1, N);
		vis[A] = 1;
		root->del(A);
		Q.push(A);
		while (!Q.empty()) {
			auto u = Q.front();
			Q.pop();
			tmpp.clear();
			enqueue(u);
			for (auto v : tmpp) {
				dist[v] = dist[u] + 1;
				Q.push(v);
			}
		}
		cout << dist[B] << '\n';
		for (int i = 1; i <= N; i++) {
			vis[i] = 0;
			dist[i] = 0;
		}
	}
}