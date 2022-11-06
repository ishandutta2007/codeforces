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

int N, K, curr, mrg[200005];
char C[200005], mrgc[200005];
bool yep[200005];
vector<ii> segs;

inline int dist(int u, int v) {
	if (u <= v) return v - u;
	else return N - u + v;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> C[i];
	for (int i = 1; i <= N; i++) {
		if ((C[(i == 1 ? N : i - 1)] != C[i]) && (C[i] != C[(i == N ? 1 : i + 1)])) {
			if (curr) segs.eb(i - curr, i - 1);
			curr = 0;
			yep[i] = 1;
		} else {
			curr++;
		}
	}
	if (curr && !segs.empty() && segs[0].first == 1) segs[0].first = N - curr + 1;
	else if (curr) segs.eb(N - curr + 1, N);
	for (int i = 0; i < segs.size(); i++) {
		if (i == (int)segs.size() - 1) {
			for (int j = (segs[i].second % N) + 1; j != segs[0].first; j = (j % N) + 1) {
				if (dist(segs[i].second, j) <= dist(j, segs[0].first)) {
					mrg[j] = dist(segs[i].second, j);
					mrgc[j] = C[segs[i].second];
				} else {
					mrg[j] = dist(j, segs[0].first);
					mrgc[j] = C[segs[0].first];
				}
			}
		} else {
			for (int j = (segs[i].second % N) + 1; j != segs[i + 1].first; j = (j % N) + 1)
				if (dist(segs[i].second, j) <= dist(j, segs[i + 1].first)) {
					mrg[j] = dist(segs[i].second, j);
					mrgc[j] = C[segs[i].second];
				} else {
					mrg[j] = dist(j, segs[i + 1].first);
					mrgc[j] = C[segs[i + 1].first];
				}
		}
	}
	if (segs.empty()) {
		for (int i = 1; i <= N; i++)
			if (K & 1) cout << (C[i] == 'W' ? 'B' : 'W');
			else cout << C[i];
		cout << '\n';
	} else {
		for (int i = 1; i <= N; i++)
			if (!yep[i]) cout << C[i];
			else if (mrg[i] > K) {
				if (K & 1) cout << (C[i] == 'W' ? 'B' : 'W');
				else cout << C[i];
			} else cout << mrgc[i];
		cout << '\n';
	}
}