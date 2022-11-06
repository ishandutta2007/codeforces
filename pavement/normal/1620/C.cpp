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

int T, N, K, X, tt[2005];
char S[2005];
string out;
vector<int> segs;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		out.clear();
		segs.clear();
		cin >> N >> K >> X;
		for (int i = 0; i < N; i++) tt[i] = 0;
		for (int i = 1; i <= N; i++) cin >> S[i];
		int tmp = 0;
		for (int i = 1; i <= N; i++) {
			if (S[i] == '*') tmp++;
			else {
				if (tmp) segs.pb(tmp);
				tmp = 0;
				if (segs.empty()) out.pb('a');
				else tt[(int)segs.size() - 1]++;
			}
		}
		if (tmp) segs.pb(tmp);
		for (int i = 0; i < segs.size(); i++) {
			__int128 cnt = 1;
			for (int j = i + 1; j < segs.size(); j++) {
				cnt *= (__int128)(segs[j] * K + 1);
				if (cnt >= X) break;
			}
			__int128 curr = 0;
			for (int j = 0; j <= segs[i] * K; j++) {
				curr += cnt;
				if (curr >= X) {
					X -= curr - cnt;
					for (int k = 0; k < j; k++) out.pb('b');
					break;
				}
			}
			for (int j = 0; j < tt[i]; j++) out.pb('a');
		}
		cout << out << '\n';
	}
}