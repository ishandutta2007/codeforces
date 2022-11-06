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

int T, N, K, A[200005];
vector<int> vec[200005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> K;
		for (int i = 1; i <= N; i++) cin >> A[i], vec[A[i]].pb(i);
		int lo = 1, hi = N, ansl, ansr;
		while (lo <= hi) {
			int mid = (lo + hi) / 2, curl, curr, sum = -N;
			bool valid = 0;
			for (int j = 1; j < mid; j++) {
				for (int k : vec[j]) sum += 2;
			}
			for (int j = mid; j <= N; j++) {
				for (int k : vec[j - mid]) sum -= 2;
				for (int k : vec[j]) sum += 2;
				if (sum >= K) {
					valid = 1;
					curl = j - mid + 1;
					curr = j;
					break;
				}
			}
			if (valid) {
				ansl = curl;
				ansr = curr;
				hi = mid - 1;
			} else lo = mid + 1;
		}
		for (int i = 1; i <= N; i++) vec[i].clear();
		vector<ii> subs;
		cout << ansl << ' ' << ansr << '\n';
		int pf = 0;
		for (int i = 1; i <= N; i++) {
			pf += (ansl <= A[i] && A[i] <= ansr ? 1 : -1);
			if (pf == 1) {
				subs.eb((subs.empty() ? 0 : subs.back().second) + 1, i);
				pf = 0;
			}
		}
		subs.back().second = N;
		for (int i = 0; i < pf; i++)
			subs[subs.size() - 2].second = N, subs.ppb();
		while (subs.size() > K)
			subs[subs.size() - 2].second = N, subs.ppb();
		for (auto [l, r] : subs) cout << l << ' ' << r << '\n';
	}
}