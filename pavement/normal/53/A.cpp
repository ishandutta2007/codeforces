#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#endif
#define int long long
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
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N;
string S, ans, F[105];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> S >> N;
	for (int i = 1; i <= N; i++) {
		cin >> F[i];
		bool cannot = 0;
		if (F[i].size() < S.size()) continue;
		for (int j = 0; j < S.size(); j++)
			if (F[i][j] != S[j]) {
				cannot = 1;
				break;
			}
		if (cannot) continue;
		ans = (ans == "" ? F[i] : min(ans, F[i]));
	}
	cout << (ans == "" ? S : ans) << '\n';
}