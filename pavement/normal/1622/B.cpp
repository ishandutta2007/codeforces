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

int T, N, P[200005], out[200005];
char C[200005];
vector<ii> pos, pos2;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		pos.clear();
		pos2.clear();
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> P[i];
		for (int i = 1; i <= N; i++) {
			cin >> C[i];
			if (C[i] == '1') pos.eb(P[i], i);
			else pos2.eb(P[i], i);
		}
		sort(pos2.begin(), pos2.end());
		for (int i = 1; i <= pos2.size(); i++) {
			out[pos2[i - 1].second] = i;
		}
		sort(pos.begin(), pos.end());
		for (int j = pos2.size() + 1; j <= N; j++) {
			out[pos[j - pos2.size() - 1].second] = j;
		}
		for (int i = 1; i <= N; i++) cout << out[i] << ' ';
		cout << '\n';
	}
}