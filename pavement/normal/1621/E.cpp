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

int T, N, M, K[100005], mpp[100005];
vector<int> vec[100005];
vector<bool> out[100005];
vector<tuple<ld, int, int> > disc;

struct node {
	node *left, *right;
	int S, E, pref, sum;
	node(int _s, int _e) : S(_s), E(_e), pref(0), sum(0) {
		if (S == E) return;
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
	}
	void upd(int p, int v) {
		if (S == E) {
			sum += v;
			pref += v;
			return;
		}
		int M = (S + E) >> 1;
		if (p <= M) left->upd(p, v);
		else right->upd(p, v);
		sum = left->sum + right->sum;
		pref = min(left->pref, left->sum + right->pref);
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		disc.clear();
		cin >> N >> M;
		for (int i = 1, Ai; i <= N; i++) {
			cin >> Ai;
			disc.eb((ld)Ai, LLONG_MAX, LLONG_MAX);
			vec[i].clear();
		}
		for (int i = 1; i <= M; i++) {
			cin >> K[i];
			out[i].resize(K[i]);
			for (int j = 0; j < K[i]; j++) out[i][j] = 0;
			int sum = 0;
			for (int j = 0, x; j < K[i]; j++) {
				cin >> x;
				vec[i].pb(x);
				sum += x;
			}
			ld avg = (ld)sum / (ld)K[i];
			disc.eb(avg, i, 0);
			int idx = 0;
			for (int j : vec[i]) {
				sum -= j;
				disc.eb((ld)sum / (ld)(K[i] - 1), i, ++idx);
				sum += j;
			}
		}
		sort(disc.begin(), disc.end(), greater<tuple<ld, int, int> >());
		root = new node(0, (int)disc.size() - 1);
		for (int i = 0; i < disc.size(); i++) {
			auto [a, b, c] = disc[i];
			if (b == LLONG_MAX) root->upd(i, 1);
			else if (c == 0) {
				mpp[b] = i;
				root->upd(i, -1);
			}
		}
		for (int i = 0; i < disc.size(); i++) {
			auto [a, b, c] = disc[i];
			if (b == LLONG_MAX || c == 0) continue;
			root->upd(mpp[b], 1);
			root->upd(i, -1);
			if (root->pref >= 0) out[b][c - 1] = 1;
			root->upd(mpp[b], -1);
			root->upd(i, 1);
		}
		for (int i = 1; i <= M; i++)
			for (bool j : out[i]) cout << j;
		cout << '\n';
	}
}