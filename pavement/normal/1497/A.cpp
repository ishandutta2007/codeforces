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

int T, N, A[105];
vector<int> cnt[105];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i <= 100; i++) cnt[i].clear();
		for (int i = 1; i <= N; i++) {
			cin >> A[i];
			cnt[A[i]].pb(i);
		}
		vector<int> seq;
		for (int i = 0; ; i++) {
			if (cnt[i].size()) {
				seq.pb(cnt[i].back());
				cnt[i].ppb();
			} else break;
		}
		for (int i = 0; i <= 100; i++) {
			while (!cnt[i].empty()) {
				seq.pb(cnt[i].back());
				cnt[i].ppb();
			}
		}
		for (int i : seq) cout << A[i] << ' ';
		cout << '\n';
	}
}