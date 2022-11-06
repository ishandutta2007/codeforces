#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
//#define int long long
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

int T, N, ans, m[10000005], d[10000005], lp[10000005], calc[10000005];
vector<int> pr;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	N = 10000000;
	for (int i = 2; i <= N; i++) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; j++)
			lp[i * pr[j]] = pr[j];
	}
	d[1] = 1;
	m[1] = 1;
	for (int i = 2, cnt, tmp, st, sum; i <= N; i++) {
		cnt = 0;
		tmp = i;
		st = lp[i];
		sum = 1;
		while (lp[tmp] == st) {
			sum *= lp[tmp];
			tmp /= lp[tmp];
			cnt++;
		}
		if (tmp == 1) {
			if (cnt > 1) calc[st] *= st;
			else calc[st] = st;
			d[i] = d[i / st] + calc[st];
		} else d[i] = d[sum] * d[tmp];
		if (d[i] <= 1e7 && !m[d[i]]) m[d[i]] = i;
	}
	cin >> T;
	while (T--) {
		cin >> N;
		if (m[N]) cout << m[N] << '\n';
		else cout << "-1\n";
	}
}