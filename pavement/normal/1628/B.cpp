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

int T, N;
string S[100005];
map<string, int> has;

string rev(string S) {
	reverse(S.begin(), S.end());
	return S;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		has.clear();
		cin >> N;
		bool ans = 0;
		for (int i = 1; i <= N; i++) {
			cin >> S[i];
			if (S[i] == rev(S[i])) ans = 1;
		}
		for (int i = N; i >= 1; i--) {
			if (has[rev(S[i])]) ans = 1;
			if (S[i].size() == 2) {
				for (char c = 'a'; c <= 'z'; c++) {
					string tmp = "";
					tmp.pb(c);
					tmp.pb(S[i][1]);
					tmp.pb(S[i][0]);
					if (has[tmp]) {
						ans = 1;
					}
				}
			} else if (S[i].size() == 3) {
				string tmp = S[i];
				tmp.ppb();
				if (has[rev(tmp)]) ans = 1;
			}
			has[S[i]] = 1;
		}
		cout << (ans ? "YES" : "NO") << '\n';
	}
}