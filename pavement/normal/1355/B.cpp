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
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

map<int, int> M;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, N;
	cin >> T;
	while (T--) {
		int S = 0;
		M.clear();
		cin >> N;
		for (int i = 1, E; i <= N; i++) {
			cin >> E;
			M[E]++;
		}
		for (auto i : M)
			S += i.second / i.first;
		vector<int> V;
		for (auto i : M)
			for (int j = 1; j <= i.second % i.first; j++)
				V.pb(i.first);
		for (int i = 0, cursz = 0, curm = 0; i < V.size(); i++) {
			curm = max(curm, V[i]);
			cursz++;
			if (cursz >= curm) {
				S++;
				cursz = 0;
				curm = 0;
			}
		}
		cout << S << '\n';
	}
}