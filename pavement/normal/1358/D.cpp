#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define ins insert
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, X, tans, D[200005], numpf[200005], sumpf[200005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> X;
	for (int i = 1; i <= N; i++) {
		cin >> D[i];
		numpf[i] = numpf[i - 1] + D[i];
		sumpf[i] = sumpf[i - 1] + D[i] * (D[i] + 1) / 2;
	}
	for (int i = 1; i <= N; i++) {
		int lo = i + 1, hi = N, ans = i, fulltake = 0, numtake = 0;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (numpf[mid] - numpf[i] + 1 <= X) numtake = numpf[mid] - numpf[i], fulltake = sumpf[mid] - sumpf[i], ans = mid, lo = mid + 1;
			else hi = mid - 1;
		}
		if (ans == N) {
			lo = 1, hi = i;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (numpf[N] - numpf[i] + 1 + numpf[mid] <= X) numtake = numpf[N] - numpf[i] + numpf[mid], fulltake = sumpf[N] - sumpf[i] + sumpf[mid], ans = mid, lo = mid + 1;
				else hi = mid - 1;
			}
		}
		numtake++;
		tans = max(tans, (X - numtake) * (X - numtake + 1) / 2 + fulltake + D[i]);
		if (D[i] >= X) {
			tans = max(tans, D[i] * (D[i] + 1) / 2 - (D[i] - X) * (D[i] - X + 1) / 2);
			continue;
		}
		lo = 1, hi = i - 1, ans = i;
		numtake = D[i];
		fulltake = D[i] * (D[i] + 1) / 2;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (numpf[i] - numpf[mid - 1] <= X) numtake = numpf[i] - numpf[mid - 1], fulltake = sumpf[i] - sumpf[mid - 1], ans = mid, hi = mid - 1;
			else lo = mid + 1;
		}
		if (ans == 1) {
			lo = i + 1, hi = N;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				//cout << "SEARCH " << mid << ' ' << numpf[N] - numpf[mid - 1] + numpf[i] << '\n';
				if (numpf[i] + numpf[N] - numpf[mid - 1] <= X) numtake = numpf[i] + numpf[N] - numpf[mid - 1], fulltake = sumpf[i] + sumpf[N] - sumpf[mid - 1], ans = mid, hi = mid - 1;
				else lo = mid + 1;
			}
		}
		//cout << i << ' ' << ans << ' ' << fulltake << ' ' << numtake << '\n';
		if (ans > 1) tans = max(tans, fulltake + D[ans - 1] * (D[ans - 1] + 1) / 2 - (D[ans - 1] - (X - numtake)) * (D[ans - 1] - (X - numtake) + 1) / 2);
		else tans = max(tans, fulltake + D[N] * (D[N] + 1) / 2 - (D[N] - (X - numtake)) * (D[N] - (X - numtake) + 1) / 2);
	}
	cout << tans << '\n';
}