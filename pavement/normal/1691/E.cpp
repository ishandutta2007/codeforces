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

int TC, N, L[100005], R[100005], link[100005], sz[100005];
bool C[100005];
iii T[100005];
vector<ii> ss[2];

int find(int x) {
	if (x == link[x]) return x;
	return link[x] = find(link[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (sz[b] > sz[a]) swap(a, b);
	sz[a] += sz[b];
	link[b] = a;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> TC;
	while (TC--) {
		for (int i = 0; i < 2; i++)
			ss[i].clear();
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> C[i] >> L[i] >> R[i];
			link[i] = i;
			sz[i] = 1;
			T[i] = mt(R[i], L[i], C[i]);
		}
		sort(T + 1, T + 1 + N);
		for (int i = 1; i <= N; i++) {
			tie(R[i], L[i], C[i]) = T[i];
			int lst = -1;
			for (int j = (int)ss[!C[i]].size() - 1; j >= 0; j--)
				if (ss[!C[i]][j].first >= L[i]) lst = j;
			if (lst == -1) {
				ss[C[i]].eb(R[i], i);
			} else {
				ii sf = mp(-1ll, -1ll);
				for (int j = lst; j < ss[!C[i]].size(); j++) {
					unite(i, ss[!C[i]][j].second);
					sf = max(sf, ss[!C[i]][j]);
				}
				for (int k = ss[!C[i]].size() - lst; k >= 1; k--)
					ss[!C[i]].ppb();
				ss[!C[i]].pb(sf);
				ss[C[i]].eb(R[i], i);
			}
		}
		int cc = 0;
		for (int i = 1; i <= N; i++)
			if (i == find(i)) cc++;
		cout << cc << '\n';
	}
}