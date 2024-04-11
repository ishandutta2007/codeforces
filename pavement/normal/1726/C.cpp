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

int T, N, lnk[200005], sz[200005];
char S[200005];
stack<int> st;

int find(int x) {
	if (x == lnk[x]) return x;
	return lnk[x] = find(lnk[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (sz[b] > sz[a]) swap(a, b);
	sz[a] += sz[b];
	lnk[b] = a;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		while (!st.empty()) st.pop();
		cin >> N;
		for (int i = 1; i <= 2 * N; i++) {
			lnk[i] = i;
			sz[i] = 1;
		}
		for (int i = 1; i <= 2 * N; i++) {
			cin >> S[i];
			if (S[i] == '(') st.push(i);
			else {
				int to = st.top();
				st.pop();
				unite(to, i);
				if (S[to - 1] == ')') unite(to - 1, to);
			}
		}
		int cc = 0;
		for (int i = 1; i <= 2 * N; i++) {
			if (i == find(i)) cc++;
		}
		cout << cc << '\n';
	}
}