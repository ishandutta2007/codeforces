#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#ifdef WIN_32
#define getchar_unlocked _getchar_nolock
#endif
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
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
typedef long double ld;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int T, N, A[300005], lft[300005], rig[300005], K[300005];
stack<int> S;
map<int, vector<int> > vec;
map<int, int> tmpp;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		while (!S.empty()) S.pop();
		vec.clear();
		tmpp.clear();
		for (int i = 1; i <= N + 1; i++) K[i] = 0;
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> A[i];
		for (int i = 1; i <= N; i++) {
			while (!S.empty() && A[S.top()] > A[i]) S.pop();
			lft[i] = (S.empty() ? 0 : S.top());
			S.push(i);
		}
		while (!S.empty()) S.pop();
		for (int i = N; i >= 1; i--) {
			while (!S.empty() && A[S.top()] >= A[i]) S.pop();
			rig[i] = (S.empty() ? N + 1 : S.top());
			S.push(i);
		}
		int lim = 0, lim2 = 0;
		for (int i = 1; i <= N; i++) {
			K[i] = rig[i] - lft[i] - 1;
			vec[A[i]].pb(K[i]);
			if (rig[i] != i + 1 && lft[i] != i - 1) lim = max(lim, K[i] - 1);
		}
		for (auto i : vec) {
			if (i.second.size() > 1) {
				sort(i.second.begin(), i.second.end(), greater<int>());
				lim2 = max(lim2, i.second[1]);
			}
		}
		for (int i = N; i >= 1; i--)
			tmpp[A[i]] = max(tmpp[A[i]], K[i]);
		int msf = 0;
		for (auto it = tmpp.rbegin(); it != tmpp.rend(); it++) {
			msf = max(msf, it->second);
			it->second = max(it->second, msf);
		}
		//for (auto i : tmpp) cout << i.first << ' ' << i.second << '\n';
		for (int i = 1; i <= N; i++) {
			auto it = tmpp.lower_bound(N - i + 2);
			if (i <= lim2 || (i > 1 && i <= lim)) cout << '0';
			else if (it != tmpp.end() && it->second >= i) cout << '0';
			else cout << '1';
		}
		cout << '\n';
	}
}