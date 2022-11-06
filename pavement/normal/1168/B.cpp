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

int N, ans, st;
string S;

bool valid(int l, int r) {
	for (int x = l; x <= r; x++)
		for (int k = 1; x + 2 * k <= r; k++)
			if (S[x] == S[x + k] && S[x + k] == S[x + 2 * k]) return 1;
	return 0;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> S;
	N = S.size();
	st = N;
	for (int i = 0; i < N; i++)
		if (valid(0, i)) {
			st = i;
			break;
		}
	for (int i = st, ptr = 0; i < N; i++) {
		while (ptr <= i && valid(ptr, i)) ptr++;
		ans += ptr;
	}
	cout << ans << '\n';
}