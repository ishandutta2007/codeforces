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

int N, Q, S, _lab, dist[1000005];
vector<ii> adj[1000005];
priority_queue<ii, vector<ii>, greater<ii> > pq;

struct node;

node *pt[100005];
vector<node*> idx;

struct node {
	node *left, *right;
	int S, E, lab;
	node(int _s, int _e, bool b = 0) : left(nullptr), right(nullptr), S(_s), E(_e) {
		lab = ++_lab;
		if (S == E) {
			if (b == 0) pt[S] = this;
			else assert(0);
			return;
		}
		int M = (S + E) >> 1;
		if (S == M && b) left = pt[S];
		else left = new node(S, M, b);
		if (M + 1 == E && b) right = pt[E];
		else right = new node(M + 1, E, b);
		if (b) {
			adj[left->lab].eb(lab, 0);
			adj[right->lab].eb(lab, 0);
		} else {
			adj[lab].eb(left->lab, 0);
			adj[lab].eb(right->lab, 0);
		}
	}
	void getall(int l, int r) {
		if (l > E || r < S) return;
		if (l <= S && E <= r) {
			idx.pb(this);
			return;
		}
		left->getall(l, r);
		right->getall(l, r);
	}
} *root, *root2;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q >> S;
	if (N == 1) return cout << "0\n", 0;
	root = new node(1, N);
	root2 = new node(1, N, 1);
	for (int i = 1, t, v, u, w, l, r; i <= Q; i++) {
		cin >> t;
		if (t == 1) {
			cin >> v >> u >> w;
			adj[pt[v]->lab].eb(pt[u]->lab, w);
		} else if (t == 2) {
			cin >> v >> l >> r >> w;
			idx.clear();
			root->getall(l, r);
			for (int i = 0; i < idx.size(); i++)
				adj[pt[v]->lab].eb(idx[i]->lab, w);
		} else {
			cin >> v >> l >> r >> w;
			idx.clear();
			root2->getall(l, r);
			for (int i = 0; i < idx.size(); i++)
				adj[idx[i]->lab].eb(pt[v]->lab, w);
		}
	}
	fill(dist, dist + 1000005, (int)1e18);
	dist[pt[S]->lab] = 0;
	pq.emplace(0, pt[S]->lab);
	while (!pq.empty()) {
		auto [dst, curr] = pq.top();
		pq.pop();
		if (dst != dist[curr]) continue;
		for (auto u : adj[curr])
			if (dst + u.second < dist[u.first]) {
				dist[u.first] = dst + u.second;
				pq.emplace(dist[u.first], u.first);
			}
	}
	for (int i = 1; i <= N; i++)
		cout << (dist[pt[i]->lab] == 1e18 ? -1 : dist[pt[i]->lab]) << ' ';
	cout << '\n';
}