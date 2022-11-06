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

int T, N, sL, sR, L[100005], R[100005], C[100005];
map<int, int> mL, mR;
map<ii, int> segs;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		sL = LLONG_MAX;
		sR = LLONG_MIN;
		mL.clear();
		mR.clear();
		segs.clear();
		for (int i = 1; i <= N; i++) {
			cin >> L[i] >> R[i] >> C[i];
			if (mL.find(L[i]) != mL.end()) mL[L[i]] = min(mL[L[i]], C[i]);
			else mL[L[i]] = C[i];
			if (mR.find(R[i]) != mR.end()) mR[R[i]] = min(mR[R[i]], C[i]);
			else mR[R[i]] = C[i];
			if (segs.find(mp(L[i], R[i])) != segs.end()) segs[mp(L[i], R[i])] = min(segs[mp(L[i], R[i])], C[i]);
			else segs[mp(L[i], R[i])] = C[i];
			sL = min(sL, L[i]);
			sR = max(sR, R[i]);
			cout << min(mL[sL] + mR[sR], (segs.find(mp(sL, sR)) == segs.end() ? LLONG_MAX : segs[mp(sL, sR)])) << '\n';
		}
	}
}