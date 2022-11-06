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

const int MOD = 1e9 + 7;
int T, N, mem[505][40005];
vector<int> vec;

bool palin(int x) {
	string s = to_string(x);
	string t = s;
	reverse(t.begin(), t.end());
	return s == t;
}

int dp(int x, int n) {
	if (n < 0) return 0;
	if (x == -1) return n == 0;
	if (mem[x][n] != -1) return mem[x][n];
	return mem[x][n] = (dp(x, n - vec[x]) + dp(x - 1, n)) % MOD;
}

main() {
	memset(mem, -1, sizeof mem);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	for (int i = 1; i <= 40000; i++)
		if (palin(i)) vec.pb(i);
	while (T--) {
		cin >> N;
		cout << dp(vec.size() - 1, N) << '\n';
	}
}