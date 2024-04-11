#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
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

int Q, N;
multiset<int> S;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> Q;
	while (Q--) {
		S.clear();
		cin >> N;
		for (int i = 1, tmp; i <= N; i++) {
			cin >> tmp;
			S.insert(tmp);
		}
		bool can = 0;
		while (S.size() > 1) {
			int curr = *S.begin(), nxt = *(++S.begin());
			if (curr == 2048 || nxt == 2048) {
				can = 1;
				break;
			}
			if (curr == nxt) {
				//cout << S.size() << '\n';
				S.erase(S.begin());
				//cout << S.size() << '\n';
				S.erase(S.begin());
				S.insert(curr + nxt);
			} else S.erase(S.begin());
		}
		for (int i : S)
			if (i == 2048) can = 1;
		cout << (can ? "YES" : "NO") << '\n';
	}
}