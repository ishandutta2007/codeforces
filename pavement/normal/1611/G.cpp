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

int T, N, M, ft[1000005];
char C;
vector<int> disc;

inline int ls(int x) { return x & -x; }

int qry(int p) {
	p = disc.size() - p + 1;
	int r = 0;
	for (; p; p -= ls(p)) r = max(r, ft[p]);
	return r;
}

void upd(int p, int v) {
	p = disc.size() - p + 1;
	if (p <= 0) return;
	for (; p <= disc.size(); p += ls(p)) ft[p] = max(ft[p], v);
}

int comp(vector<ii> v) {
	int ans = 0;
	disc.clear();
	vector<ii> nv;
	for (auto i : v) {
		int a = N - i.first, b = i.second - 1;
		nv.eb(a + b, a - b);
		disc.pb(a - b);
	}
	sort(nv.begin(), nv.end());
	sort(disc.begin(), disc.end());
	disc.erase(unique(disc.begin(), disc.end()), disc.end());
	for (int i = 1; i <= disc.size(); i++) ft[i] = 0;
	int prv = -1;
	vector<ii> buf;
	for (auto i : nv) {
		if (i.first != prv) {
			while (!buf.empty()) upd(buf.back().first, buf.back().second), buf.ppb();
		}
		prv = i.first;
		int tmp = lower_bound(disc.begin(), disc.end(), i.second + 1) - disc.begin() + 1, x = qry(tmp) + 1;
		ans = max(ans, x);
		buf.eb(tmp - 1, x);
	}
	return ans;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		vector<ii> v1, v2;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> C;
				if (C == '1') {
					if ((i & 1) ^ (j & 1)) v1.eb(i, j);
					else v2.eb(i, j);
				}
			}
		}
		cout << comp(v1) + comp(v2) << '\n';
	}
}