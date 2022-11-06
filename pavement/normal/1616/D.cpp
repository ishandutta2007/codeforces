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

int T, N, X, A[50005], P[50005], L[50005];
vector<int> vec;

struct node {
	node *left, *right;
	int S, E, val;
	node(int _s, int _e) : S(_s), E(_e) {
		if (S == E) {
			val = L[S];
			return;
		}
		int M = (S + E) >> 1;
		left = new node(S, M);
		right = new node(M + 1, E);
		val = max(left->val, right->val);
	}
	int qry(int l, int r) {
		if (l > E || r < S) return LLONG_MIN;
		if (l <= S && E <= r) return val;
		return max(left->qry(l, r), right->qry(l, r));
	}
} *root;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		vec.clear();
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> A[i];
		cin >> X;
		for (int i = 1; i <= N; i++) {
			A[i] -= X;
			P[i] = P[i - 1] + A[i];
			// find j < i such that P[i] - P[j - 1] < 0
			// P[j - 1] > P[i]
			
			int lo = 0, hi = (int)vec.size() - 1, ans = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (P[vec[mid]] > P[i]) ans = vec[mid], lo = mid + 1;
				else hi = mid - 1;
			}
			
			//for (int j : vec) cout << j << ' ';
			//cout << '\n';
			
			L[i] = ans + 1;
			
			while (!vec.empty() && P[vec.back()] <= P[i - 1]) vec.ppb();
			vec.pb(i - 1);
		}
		root = new node(1, N);
		int i = N, tans = N;
		while (i > 1 && root->qry(1, i)) {
			int lo = 1, hi = i - 1, ans = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (root->qry(mid + 1, i) <= mid) ans = mid, hi = mid - 1;
				else lo = mid + 1;
			}
			i = ans - 1;
			tans--;
		}
		cout << tans << '\n';
	}
}