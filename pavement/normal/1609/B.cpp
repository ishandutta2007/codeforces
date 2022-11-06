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

int N, Q, p, ans;
char c;
string S;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q >> S;
	for (int i = 0; i < (int)S.size() - 2; i++) {
		if (S[i] == 'a' && S[i + 1] == 'b' && S[i + 2] == 'c') ans++;
	}
	for (int i = 1; i <= Q; i++) {
		cin >> p >> c;
		p--;
		if (S[p] == 'a') {
			if (p + 2 < N && S[p + 1] == 'b' && S[p + 2] == 'c') {
				ans--;
			}
		} else if (S[p] == 'b') {
			if (p + 1 < N && p - 1 >= 0 && S[p - 1] == 'a' && S[p + 1] == 'c') {
				ans--;
			}
		} else if (S[p] == 'c') {
			if (p - 2 >= 0 && S[p - 1] == 'b' && S[p - 2] == 'a') {
				ans--;
			}
		}
		if (c == 'a') {
			if (p + 2 < N && S[p + 1] == 'b' && S[p + 2] == 'c') {
				ans++;
			}
		} else if (c == 'b') {
			if (p + 1 < N && p - 1 >= 0 && S[p - 1] == 'a' && S[p + 1] == 'c') {
				ans++;
			}
		} else if (c == 'c') {
			if (p - 2 >= 0 && S[p - 1] == 'b' && S[p - 2] == 'a') {
				ans++;
			}
		}
		S[p] = c;
		cout << ans << '\n';
	}
}