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

int T, N, cnt[200005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i <= N; i++) cnt[i] = 0;
		for (int i = 1, A; i <= N; i++) {
			cin >> A;
			cnt[A]++;
		}
		bool flip = 0, cant = 0;
		int ans = 0;
		multiset<int> ss;
		for (int i = 0; i <= N; i++) {
			for (int j = 1; j < cnt[i]; j++) ss.insert(i);
			if (!cnt[i] && !flip) {
				flip = 1;
				cout << "0 ";
			} else if (!flip) cout << cnt[i] << ' ';
			else cout << (cant ? -1 : ans + cnt[i]) << ' ';
			if (flip && !cnt[i]) {
				if (ss.empty()) cant = 1;
				else {
					ans += i - *ss.rbegin();
					ss.erase(--ss.end());
				}
			}
		}
		cout << '\n';
	}
}