#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
#define ins insert
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, M, ft[1000005], out[100005];
string S;
stack<int> P;
vector<ii> qu[1000005];

inline int ls(int x) { return x & -x; }

int qry(int p) {
	int r = 0;
	for (; p; p -= ls(p)) r += ft[p];
	return r;
}

void upd(int p, int v) {
	for (; p <= N; p += ls(p)) ft[p] += v;
}

main() {
	cin >> S >> M;
	N = S.size();
	for (int i = 1, l, r; i <= M; i++) {
		cin >> l >> r;
		qu[l].eb(r, i);
	}
	for (int i = N; i >= 1; i--) {
		if (S[i - 1] == '(') {
			if (!P.empty()) {
				upd(P.top(), 1);
				P.pop();
			}
		} else P.push(i);
		for (auto j : qu[i])
			out[j.second] = qry(j.first) << 1;
	}
	for (int i = 1; i <= M; i++) cout << out[i] << '\n';
}