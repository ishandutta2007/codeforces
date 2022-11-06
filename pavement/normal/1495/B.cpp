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

int N, ans, P[100005], lef[100005], lef2[100005], rig[100005], rig2[100005], mpref[100005], msuff[100005];
vector<int> vec;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> P[i];
	lef[1] = lef2[1] = 1;
	for (int i = 2; i <= N; i++) {
		if (P[i] > P[i - 1]) lef[i] = lef[i - 1], lef2[i] = i;
		else lef[i] = i, lef2[i] = lef2[i - 1];
		mpref[i] = max(mpref[i - 1], max(i - lef[i], i - lef2[i]));
	}
	rig[N] = rig2[N] = N;
	for (int i = N - 1; i >= 1; i--) {
		if (P[i] > P[i + 1]) rig[i] = rig[i + 1], rig2[i] = i;
		else rig[i] = i, rig2[i] = rig2[i + 1];
		msuff[i] = max(msuff[i + 1], max(rig[i] - i, rig2[i] - i));
	}
	for (int i = 1; i <= N; i++) {
		if (lef[i] == i || rig[i] == i) continue;
		// [lef[i], rig[i]]
		vec.clear();
		vec.pb(i - 1);
		vec.pb(i + 1);
		vec.pb(lef[i]);
		vec.pb(rig[i]);
		vec.pb(lef[i] + 1);
		vec.pb(rig[i] - 1);
		bool win = 1;
		for (auto j : vec) {
			// try Daniel's position as j, Qingshan's position as i
			if (i == j) continue;
			if (j < i) {
				assert(lef[i] <= j);
				if ((i - j) & 1) {
					if (rig[i] - i <= max(i - j, j - lef2[j])) win = 0;
				} else {
					if (lef2[j] == j) {
						// Daniel dies
					} else if (rig[i] - i <= max(i - j, j - lef[j]) && i - j <= j - lef2[j]) {
						win = 0;
					}
				}
			} else {
				assert(j <= rig[i]);
				if ((j - i) & 1) {
					if (i - lef[i] <= max(j - i, rig2[j] - j)) win = 0;
				} else {
					if (rig2[j] == j) {
						// Daniel dies
					} else if (i - lef[i] <= max(j - i, rig2[j] - j) && j - i <= rig2[j] - j) {
						win = 0;
					}
				}
			}
		}
		if (max(rig[i] - i, i - lef[i]) <= max(mpref[lef[i] - 1], msuff[rig[i] + 1])) win = 0;
		ans += win;
	}
	cout << ans << '\n';
}