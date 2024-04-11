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

int T, N, K, ans1, ans2, X[200005];
vector<int> v1, v2;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		ans1 = ans2 = 0;
		v1.clear();
		v2.clear();
		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			cin >> X[i];
			if (X[i] >= 0) v1.pb(X[i]);
			else v2.pb(X[i]);
		}
		sort(v1.begin(), v1.end(), greater<int>());
		sort(v2.begin(), v2.end());
		if (!v1.empty()) {
			ans1 += v1[0];
			for (int i = K; i < v1.size(); i += K) ans1 += 2 * v1[i];
			for (int j = 0; j < v2.size(); j += K) ans1 += 2 * llabs(v2[j]);
		} else ans1 = LLONG_MAX;
		if (!v2.empty()) {
			ans2 += llabs(v2[0]);
			for (int i = K; i < v2.size(); i += K) ans2 += 2 * llabs(v2[i]);
			for (int j = 0; j < v1.size(); j += K) ans2 += 2 * v1[j];
		} else ans2 = LLONG_MAX;
		cout << min(ans1, ans2) << '\n';
	}
}