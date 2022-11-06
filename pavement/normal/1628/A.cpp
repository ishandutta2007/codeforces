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

int T, N, A[200005], suff[200005];
set<int> ss;

main() {
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> A[i];
		for (int i = 0; i <= N + 4; i++) ss.insert(i);
		for (int i = N; i >= 1; i--) {
			if (ss.find(A[i]) != ss.end()) ss.erase(A[i]);
			suff[i] = *ss.begin();
		}
		vector<int> vec;
		for (int pt = 1; pt <= N; ) {
			int x = suff[pt], brk = -1, mex = 0;
			ss.clear();
			for (int i = pt; i <= N; i++) {
				if (A[i] >= mex) ss.insert(A[i]);
				while (!ss.empty() && *ss.begin() == mex) ss.erase(ss.begin()), mex++;
				if (mex == x) {
					brk = i;
					break;
				}
			}
			assert(brk != -1);
			vec.pb(x);
			pt = brk + 1;
		}
		cout << vec.size() << '\n';
		for (int i : vec) cout << i << ' ';
		cout << '\n';
	}
}