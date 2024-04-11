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

int T, ans;
string a, b, curr, curr2;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> a >> b;
		ans = a.size() + b.size();
		for (int i = 0; i < a.size(); i++) {
			curr.clear();
			for (int j = i; j < a.size(); j++) {
				curr.pb(a[j]);
				for (int k = 0; k < b.size(); k++) {
					curr2.clear();
					for (int l = k; l < b.size(); l++) {
						curr2.pb(b[l]);
						if (curr == curr2) ans = min(ans, i + (int)a.size() - j - 1 + k + (int)b.size() - l - 1);
					}
				}
			}
		}
		cout << ans << '\n';
	}
}