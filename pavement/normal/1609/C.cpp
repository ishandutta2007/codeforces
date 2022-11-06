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

int T, N, E, ans, A[200005];
vector<int> cong[200005];
bitset<1000005> ip;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ip.set();
	ip[0] = ip[1] = 0;
	for (int i = 2; i <= 1e6; i++) {
		if (ip[i])
			for (int j = i + i; j <= 1e6; j += i) ip[j] = 0;
	}
	cin >> T;
	while (T--) {
		cin >> N >> E;
		for (int i = 0; i < E; i++) cong[i].clear();
		for (int i = 1; i <= N; i++) {
			cin >> A[i];
			A[i] = (A[i] == 1 ? 0 : (ip[A[i]] ? 1 : 2));
			cong[i % E].pb(A[i]);
		}
		ans = 0;
		for (int i = 0; i < E; i++) {
			//cout << "@ " << i << '\n';
			int pt = (int)cong[i].size() - 1, pt2 = (int)cong[i].size() - 1, cnt = 0, cnt2 = 0;
			for (int j = (int)cong[i].size() - 1; j >= 0; j--) {
				if (cong[i][j] == 2) {
					pt = pt2 = j - 1;
					cnt = cnt2 = 0;
					continue;
				}
				cnt += cong[i][j];
				while (cnt >= 2) {
					cnt -= cong[i][pt];
					pt--;
				}
				cnt2 += cong[i][j];
				while (cnt2 >= 1) {
					cnt2 -= cong[i][pt2];
					pt2--;
				}
				if (cong[i][j]) ans += pt - j;//, cout << "+ " << pt - j << '\n';
				else ans += pt - pt2;//, cout << "+ " << pt - pt2 << '\n';
				//out << j << ": " << pt << ' ' << pt2 << '\n';
				//ans += pt - j;
			}
		}
		cout << ans << '\n';
	}
}