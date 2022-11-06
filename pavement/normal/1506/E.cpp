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

int T, N, Q[200005], P[200005], R[200005];
bool in[200005];
vector<int> vec;
set<int> s;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		vec.clear();
		s.clear();
		for (int i = 1; i <= N; i++) in[i] = 0;
		for (int i = 1; i <= N; i++) cin >> Q[i], in[Q[i]] = 1;
		P[1] = R[1] = Q[1];
		for (int i = N; i >= 1; i--)
			if (!in[i]) vec.pb(i), s.insert(i);
		for (int i = 2; i <= N; i++) {
			if (Q[i] == Q[i - 1]) {
				P[i] = vec.back();
				vec.ppb();
				auto it = --s.upper_bound(Q[i]);
				R[i] = *it;
				s.erase(it);
			} else P[i] = R[i] = Q[i];
		}
		for (int i = 1; i <= N; i++) cout << P[i] << ' ';
		cout << '\n';
		for (int i = 1; i <= N; i++) cout << R[i] << ' ';
		cout << '\n';
	}
}