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

int T, N, K, link[200005], sz[200005], X[200005], Y[200005], timer[200005];
map<int, vector<ii> > MX, MY;

int find(int x) {
	if (x == link[x]) return x;
	return link[x] = find(link[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (sz[b] > sz[a]) swap(a, b);
	sz[a] += sz[b];
	link[b] = a;
	timer[a] = min(timer[a], timer[b]);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		MX.clear();
		MY.clear();
		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			cin >> X[i] >> Y[i] >> timer[i];
			MX[X[i]].eb(Y[i], i);
			MY[Y[i]].eb(X[i], i);
			link[i] = i;
			sz[i] = 1;
		}
		for (auto &i : MX) {
			sort(i.second.begin(), i.second.end());
			for (int j = 0; j < (int)i.second.size() - 1; j++)
				if (i.second[j + 1].first - i.second[j].first <= K) unite(i.second[j].second, i.second[j + 1].second);
		}
		for (auto &i : MY) {
			sort(i.second.begin(), i.second.end());
			for (int j = 0; j < (int)i.second.size() - 1; j++)
				if (i.second[j + 1].first - i.second[j].first <= K) unite(i.second[j].second, i.second[j + 1].second);
		}
		int lo = 0, hi = N, ans = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2, tmp = -1;
			for (int i = 1; i <= N; i++)
				if (i == find(i) && timer[i] > mid) tmp++;
			if (tmp <= mid) ans = mid, hi = mid - 1;
			else lo = mid + 1;
		}
		cout << ans << '\n';
	}
}