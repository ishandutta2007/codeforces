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
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, A[100005], spf[200005];
bitset<200005> bs;
map<int, vector<int> > all;

vector<ii> primes(int x) {
	vector<ii> res;
	while (x != 1) {
		if (res.empty() || res.back().first != spf[x]) res.eb(spf[x], 0);
		res.back().second++;
		x /= spf[x];
	}
	return res;
}

int power_of(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1ll) r = r * a;
		a = a * a;
		b >>= 1ll;
	}
	return r;
}

main() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= 2e5; i++) spf[i] = i;
	for (int i = 2; i <= 2e5; i++) {
		if (bs[i]) {
			for (int j = i + i; j <= 2e5; j += i) {
				if (bs[j]) spf[j] = i;
				bs[j] = 0;
			}
		}
	}
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		cnt += (A[i] == 1);
	}
	if (cnt > 1) return cout << "1\n", 0;
	for (int i = 1; i <= N; i++) {
		auto p = primes(A[i]);
		for (auto j : p) {
			all[j.first].pb(j.second);
		}
	}
	int ans = 1;
	for (auto i : all) {
		sort(i.second.begin(), i.second.end());
		if (i.second.size() == N - 1) ans *= power_of(i.first, i.second[0]);
		else if (i.second.size() == N) ans *= power_of(i.first, i.second[1]);
	}
	if (cnt) {
		for (int i = 1; i <= N; i++)
			if (A[i] != 1) ans = __gcd(ans, A[i]);
	}
	cout << ans << '\n';
}