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

int n, k, m, lnk[300005], sz[300005], cnt[300005][2], wei[300005];
char ch;
bool inv, s[300005];
vector<int> sw[300005];

int find(int x) {
	if (x == lnk[x]) return x;
	return find(lnk[x]);
}

int get_wei(int x) {
	if (x == lnk[x]) return wei[x];
	return wei[x] ^ get_wei(lnk[x]);
}

void unite(int a, int b, bool w) {
	w ^= get_wei(a) ^ get_wei(b);
	a = find(a);
	b = find(b);
	if (a == b) {
		if (w) {
			while (1) {}
		}
		return;
	}
	if (sz[b] > sz[a]) swap(a, b);
	//~ cout << "! " << w << '\n';
	wei[b] = w;
	cnt[a][0] += cnt[b][w];
	cnt[a][1] += cnt[b][!w];
	sz[a] += sz[b];
	lnk[b] = a;
}

int val(int x) {
	x = find(x);
	return min(cnt[x][0], cnt[x][1]);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> ch;
		s[i] = (ch == '1');
	}
	for (int i = 1, c; i <= k; i++) {
		cin >> c;
		lnk[i] = i;
		sz[i] = 1;
		cnt[i][0]++;
		for (int j = 1, x; j <= c; j++) {
			cin >> x;
			sw[x].pb(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (sw[i].size() == 1) {
			m -= val(sw[i][0]);
			int fix = get_wei(sw[i][0]) ^ s[i];
			cnt[find(sw[i][0])][!fix] += (int)1e9;
			m += val(sw[i][0]);
		} else if (sw[i].size() == 2) {
			bool flag = 0;
			if (find(sw[i][0]) != find(sw[i][1])) {
				m -= val(sw[i][0]);
				m -= val(sw[i][1]);
				flag = 1;
			}
			unite(sw[i][0], sw[i][1], !s[i]);
			if (flag) {
				m += val(sw[i][0]);
			}
		} else {
			assert(sw[i].empty());
			inv |= !s[i];
		}
		assert(!inv);
		//~ for (int j = 1; j <= k; j++) {
			//~ if (j == find(j)) {
				//~ cout << "@ " << j << ' ' << cnt[j][0] << ' ' << cnt[j][1] << '\n';
			//~ }
		//~ }
		// assert(m <= k);
		cout << m << '\n';
	}
}