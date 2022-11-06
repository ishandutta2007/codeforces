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

int T, N, tot, pref[2005][35], suff[2005][35], A[2005];
map<int, int> cnt;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		memset(pref, 0, sizeof pref);
		memset(suff, 0, sizeof suff);
		tot = 0;
		cnt.clear();
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> A[i];
			++cnt[A[i]];
			for (int j = 1; j <= 26; j++)
				pref[i][j] = cnt[j];
		}
		cnt.clear();
		for (int i = N; i >= 1; i--) {
			++cnt[A[i]];
			for (int j = 1; j <= 26; j++)
				suff[i][j] = cnt[j];
		}
		for (int k = 1; k <= 26; k++) tot = max(tot, pref[N][k]);
		for (int i = 1; i <= N; i++)
			for (int j = i; j <= N; j++) {
				if (A[i] == A[j]) {
					int ans = pref[j][A[i]] - pref[i][A[j]] + 1, tmp = 0;
					for (int k = 1; k <= 26; k++)
						if (pref[i - 1][k] && suff[j + 1][k]) tmp = max(tmp, min(pref[i - 1][k], suff[j + 1][k]) * 2);
					ans += tmp;
					tot = max(tot, ans);
				}
			}
		cout << tot << '\n';
	}
}