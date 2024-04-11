#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"


const int MAXN = 1e5 + 10;

int cnt(ll x) {
	assert(x >= 0);
	if  (!x) return 0;
	ll i = 1;
	for (; i * i * i <= x; ++i);
	--i;
	return 1 + cnt(x - i * i * i);
}

ll c3(ll x) {
	return x * x * x;
}

ll sqrt3(ll x) {
	ll r = pow(x, 1.0 / 3);
	ll L = r - 100;
	ll R = r + 100;
	while (L != R - 1) {
		ll M = (L + R) / 2;
		if  (c3(M) <= x) {
			L = M;
		} else {
			R = M;
		}
	}	
	return L;
}

bool check(ll l, ll r, int cnt) {
	if  (l > r) {
		return false;
	}

	// cout << "check " << l << " " << r << ", cnt = " << cnt << endl;

	ll y0 = sqrt3(r);

	if  (cnt == 0) {
		return l <= 0 && 0 <= r;
	}

	if  (r <= 0) {
		return false;
	}

	for (int i = 0; i >= -1; --i) {
		ll y = y0 + i;
		for (ll cur_cnt = 1; cur_cnt <= cnt && cur_cnt * c3(y) <= r; ++cur_cnt) {
			// cout << "y = " << y << ", cur_cnt = " << cur_cnt << endl;
			ll L = l - cur_cnt * c3(y);
			L = max(L, 0ll);
			ll R = r - cur_cnt * c3(y);
			R = min(R, c3(y) - 1);
			R = min(R, c3(y + 1) - 1 - cur_cnt * c3(y));
			if  (check(L, R, cnt - cur_cnt)) {
				return true;
			}
		}  
	}

	return false;
}

pair<ll, ll> solve(ll m) {
	ll sum = 0;
	int ans = 0;
	multiset<int> S;
	for (int i = 1; c3(i) <= m; ++i) {
		ll nxt = c3(i + 1);
		while (sum + c3(i) < nxt && sum + c3(i) <= m) {
			++ans;
			sum += c3(i);
			S.insert(i);
			// printf("++ with %d\n", (int) i);
		}
	}

	ll L = 0;
	ll R = m + 1;
	while (L != R - 1) {
		ll M = (L + R) / 2;
		if  (check(M, m, ans)) {
			L = M;
		} else {
			R = M;
		}
	}

	return mp(ans, L);

	while (!S.empty() && sum < m) {
		int last = *S.rbegin();
		if  (sum - c3(last) + c3(last + 1) <= m && sum - c3(last) + c3(last + 1) < c3(last + 2)) {
			S.erase(last);
			S.insert(last + 1);
			sum += -c3(last) + c3(last + 1);
		} else {
			S.erase(last);
		}
	}

	return mp(ans, sum);
}

ll brut_cnt(ll m) {
	ll mx = 0;
	for (ll x = 1; x <= m; ++x) {
		mx = max(mx, 1ll * cnt(x));
	}
	return mx;
}

int main() {
#ifdef LOCAL
	// freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	// for (ll m = 1; ; ++m) {
	// 	auto res = solve(m);
	// 	// cout << "cnt = " << res.fst << ", X = " << res.snd << ", real_cnt = " << cnt(res.snd) << endl;
	// 	assert(cnt(res.snd) == res.fst);
	// 	assert(brut_cnt(m) == res.fst);
	// 	cerr << "ok " << m << endl;
	// }

	ll m;
	cin >> m;

	auto res = solve(m);
	cout << res.fst << " " << res.snd << endl;

	// m = (ll) 1e15;
	// for (ll mm = m; mm; mm /= 2) {
	// 	auto res = solve(mm);
	// 	cout << res.fst << " " << res.snd << endl;
	// }

#ifdef LOCAL
	printf("Time: %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}