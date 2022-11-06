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

int t, n, ans, p[100005], mem[100005], prv[100005];
vector<int> buf;
map<int, int> fs;

int dp(int n) {
	if (n == 0) return 0;
	if (mem[n] != -1) return mem[n];
	return mem[n] = min(dp(n - 1) + 1, prv[n] == -1 ? (int)1e9 : (dp(prv[n]) + max(1ll, n - prv[n] - 1)));
}

int solve(vector<int> v) {
	fs[0] = 0;
	for (int i = 0; i < v.size(); i++) {
		p[i + 1] = p[i] ^ v[i];
		if (fs.find(p[i + 1]) != fs.end()) prv[i + 1] = fs[p[i + 1]];
		else prv[i + 1] = -1;
		fs[p[i + 1]] = i + 1;
	}
	int tmp = dp(v.size());
	fs.clear();
	for (int i = 1; i <= v.size(); i++) {
		p[i] = 0;
		mem[i] = -1;
	}
	return tmp;
}

main() {
	memset(mem, -1, sizeof mem);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1, a; i <= n; i++) {
			cin >> a;
			if (a == 0) {
				ans += solve(buf);
				buf.clear();
			} else buf.pb(a);
		}
		ans += solve(buf);
		buf.clear();
		cout << ans << '\n';
		ans = 0;
	}
}