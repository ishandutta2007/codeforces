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
int N, ans, cnt[200005], A[200005];
vector<ii> v;
map<int, int> m;

int exp_mod(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1) r = r * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return r;
}

int ce(int x) {
	return (exp_mod(2, x - 1) - 1) % MOD;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int tmp = 0;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		if (A[i] % 2 == 0) tmp++;
		while (A[i] % 2 == 0) {
			cnt[i]++;
			A[i] /= 2;
		}
		if (cnt[i]) m[cnt[i]]++;
	}
	ans = exp_mod(2, N) - exp_mod(2, tmp);
	ans %= MOD;
	for (auto i : m) v.pb(i);
	reverse(v.begin(), v.end());
	int curr = 0;
	for (auto i : v) {
		ans += (exp_mod(2, curr) * ce(i.second)) % MOD;
		ans %= MOD;
		curr += i.second;
		curr %= MOD;
	}
	cout << (ans + MOD) % MOD << '\n';
}