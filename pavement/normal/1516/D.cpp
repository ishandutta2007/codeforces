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

int N, Q, A[100005], to[100005], spf[100005], anc[100005][25], dep[100005];
vector<int> adj[100005];
map<int, int> yes;
bitset<100005> ip;

struct node {
	node *left, *right;
	int S, E, val;
	node(int _s, int _e) : S(_s), E(_e) {
		if (S == E) {
			val = to[S];
			return;
		}
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
		val = min(left->val, right->val);
	}
	int qry(int l, int r) {
		if (l > E || r < S) return 1e9;
		if (l <= S && E <= r) return val;
		return min(left->qry(l, r), right->qry(l, r));
	}
} *root;

void dfs(int n, int e = -1) {
	anc[n][0] = e;
	for (int i = 1; i <= 20; i++)
		if (anc[n][i - 1] != -1)
			anc[n][i] = anc[anc[n][i - 1]][i - 1];
	for (auto u : adj[n])
		if (u != e)
			dep[u] = dep[n] + 1, dfs(u, n);
}

vector<int> pf(int x) {
	vector<int> ret;
	while (x != 1) {
		ret.pb(spf[x]);
		x /= spf[x];
	}
	return ret;
}

main() {
	ip.set();
	ip[0] = ip[1] = 0;
	for (int i = 2; i <= 100000; i++) {
		if (!ip[i]) continue;
		spf[i] = i;
		for (int j = i + i; j <= 100000; j += i)
			if (ip[j]) {
				ip[j] = 0;
				spf[j] = i;
			}
	}
	memset(anc, -1, sizeof anc);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = N; i >= 1; i--) {
		to[i] = N + 1;
		vector<int> tmp = pf(A[i]);
		for (int j : tmp)
			if (yes.find(j) != yes.end()) to[i] = min(to[i], yes[j]);
		for (int j : tmp) yes[j] = i;
	}
	root = new node(1, N);
	for (int i = 1; i <= N; i++) {
		int lo = i, hi = N, ans = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (root->qry(i, mid) > mid) {
				ans = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		adj[ans + 1].pb(i);
	}
	dfs(N + 1);
	for (int i = 1, l, r; i <= Q; i++) {
		cin >> l >> r;
		int curr = l;
		for (int k = 20; k >= 0; k--)
			if (anc[curr][k] != -1 && anc[curr][k] <= r)
				curr = anc[curr][k];
		cout << dep[l] - dep[curr] + 1 << '\n';
	}
}