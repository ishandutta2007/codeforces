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

const int MOD = 1e9 + 7;
int N, Q, A[200005], ans = 1, j, x, lp[200005], cnt[200005];
vector<int> vec[200005];
bitset<200005> ip;
multiset<int> yes[200005];
map<int, int> tmp[200005];

int exp_mod(int a, int b) {
	a %= MOD;
	b %= (MOD - 1);
	int r = 1;
	while (b) {
		if (b & 1) r = r * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return r;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	ip.set();
	ip[0] = ip[1] = 0;
	for (int i = 2; i <= 200000; i++) {
		if (!ip[i]) continue;
		lp[i] = i;
		for (int j = i + i; j <= 200000; j += i) {
			if (ip[j]) {
				ip[j] = 0;
				lp[j] = i;
			}
		}
	}
	for (int i = 1; i <= 200000; i++) {
		int curr = i;
		while (curr != 1) {
			vec[i].pb(lp[curr]);
			curr /= lp[curr];
		}
	}
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		for (int j : vec[A[i]]) tmp[i][j]++;
		for (auto j : tmp[i])
			yes[j.first].insert(j.second);
	}
	for (int i = 1; i <= 200000; i++) {
		ans *= exp_mod(i, (yes[i].size() == N ? *yes[i].begin() : 0));
		ans %= MOD;
	}
	for (int i = 1; i <= Q; i++) {
		cin >> j >> x;
		vector<int> cons;
		map<int, int> prv;
		for (int k : vec[x]) prv[k] = tmp[j][k];
		for (int k : vec[x]) tmp[j][k]++, cons.pb(k);
		cons.erase(unique(cons.begin(), cons.end()), cons.end());
		for (int k : cons) {
			ans *= exp_mod(exp_mod(k, yes[k].size() == N ? *yes[k].begin() : 0), MOD - 2);
			if (prv[k]) yes[k].erase(yes[k].find(prv[k]));
			ans %= MOD;
			yes[k].insert(tmp[j][k]);
			ans *= exp_mod(k, yes[k].size() == N ? *yes[k].begin() : 0);
			ans %= MOD;
		}
		cout << ans << '\n';
	}
}