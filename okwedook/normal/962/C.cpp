#pragma GCC optimize("O3","unroll-loops")
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define pb push_back
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-8
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf (1 << 31) - 1
#define f first
#define s second

#include <bits/stdc++.h>
using namespace std;

template<typename T1, typename T2>inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

int main() {
	FAST;
	string s;
	cin >> s;
	ll shift = s.size();
	ll ans = shift + 1;
	for (ll i = 1; i < (1 << shift); ++i) {
		ll summ = 0;
		ll cnt = 0;
		bool flag = false;
		for (ll j = shift - 1; j >= 0; --j)
			if ((i >> j) & 1) {
				if (summ == 0 && s[shift - j - 1] == '0') flag = true;
				summ = summ * 10 + (s[shift - j - 1] - '0');
				++cnt;
			}
		if (!flag)
			if (ll(sqrt(summ)) == sqrt(summ))
				ans = min(ans, shift - cnt);
	}
	if (ans == shift + 1) cout << -1;
	else cout << ans;
    return 0;
}