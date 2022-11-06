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

int T, N, M, ans, a[1000005], b[1000005], ft[2000005];
vector<int> disc, seq, vec[1000005];

inline int ls(int x) { return x & -x; }

int qry(int p) {
	int r = 0;
	for (; p; p -= ls(p)) r += ft[p];
	return r;	
}

void upd(int p) {
	for (; p <= disc.size(); p += ls(p)) ft[p]++;
}

void solve(int l, int r, int x, int y) {
	if (l > r || x > y) return;
	int m = (l + r) >> 1, mpos = 0, cpos = 0, pos = x;
	for (int i = x + 1; i <= y; i++) {
		if (a[i - 1] < b[m]) cpos++;
		else if (a[i - 1] > b[m]) cpos--;
		if (cpos > mpos) mpos = cpos, pos = i;
	}
	solve(l, m - 1, x, pos);
	solve(m + 1, r, pos, y);
	vec[pos].pb(b[m]);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		ans = 0;
		seq.clear();
		disc.clear();
		cin >> N >> M;
		for (int i = 1; i <= N; i++) cin >> a[i];
		for (int i = 1; i <= M; i++) cin >> b[i];
		sort(b + 1, b + 1 + M);
		solve(1, M, 1, N + 1);
		for (int i = 1; i <= N + 1; i++) {
			sort(vec[i].begin(), vec[i].end());
			for (int j : vec[i]) seq.pb(j);
			if (i <= N) seq.pb(a[i]);
		}
		for (int i : seq) disc.pb(i);
		sort(disc.begin(), disc.end());
		disc.erase(unique(disc.begin(), disc.end()), disc.end());
		for (int &i : seq) i = lower_bound(disc.begin(), disc.end(), i) - disc.begin() + 1;
		for (int i = (int)seq.size() - 1; i >= 0; i--) {
			upd(seq[i]);
			ans += qry(seq[i] - 1);
		}
		cout << ans << '\n';
		for (int i = 1; i <= N + 1; i++) vec[i].clear();
		for (int i = 1; i <= disc.size(); i++) ft[i] = 0;
	}
}