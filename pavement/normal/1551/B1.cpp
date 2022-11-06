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

int T, M[35];
string S;
priority_queue<ii> pq;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		for (int i = 0; i < 26; i++) M[i] = 0;
		cin >> S;
		for (char c : S) M[c - 'a']++;
		int lo = 1, hi = S.size(), ans = 0;
		while (lo <= hi) {
			while (!pq.empty()) pq.pop();
			for (int i = 0; i < 26; i++) pq.emplace(M[i], i);
			int mid = (lo + hi) / 2, grp = 0;
			vector<ii> tmp;
			while (1) {
				tmp.clear();
				for (int i = 0; i < mid; i++) {
					if (pq.top().first == 0) goto done;
					tmp.eb(pq.top().first, pq.top().second);
					pq.pop();
				}
				grp++;
				for (auto i : tmp) pq.emplace(i.first - 1, i.second);
			}
			done:;
			if (grp >= 2) {
				ans = mid;
				lo = mid + 1;
			} else hi = mid - 1;
		}
		cout << ans << '\n';
	}
}