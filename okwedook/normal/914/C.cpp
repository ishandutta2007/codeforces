#pragma GCC optimize("O3","unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(NULL))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second

template<class T1, class T2> inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<class T1, class T2> inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<class T1> inline void sort(T1 &arr) { sort(all(arr)); }
template<class T1> inline void rsort(T1 &arr) { sort(rall(arr)); }
template<class T1> inline void reverse(T1 &arr) { reverse(all(arr)); }
template<class T1> inline void shuffle(T1 &arr) { 
    for (int i = -int(arr.size()); i < int(arr.size()); ++i)
        swap(arr[rand() % arr.size()], arr[rand() % arr.size()]);
}
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

const ll N = 1001;
ll cnt[N];
ll C[N][N];
ll ans[6];

ll sum(ll a, ll b) {
	ll ans = a + b;
	if (ans > mod) ans -= mod;
	return ans;
}

ll myplus(ll &a, ll b) {
	a = sum(a, b);
}

ll mul(ll a, ll b) {
	ll ans = (a * b) % mod;
	if (ans < 0) ans += mod;
	return ans;
}

void plusone(string &s) {
	for (int i = s.size() - 1; i >= 0; --i)
		if (s[i] == '0') return void(++s[i]);
		else s[i] = '0';
	s = "1" + s;
}

signed main() {
	FAST; FIXED; RANDOM;
	for (int n = 1; n < N; ++n) {
		int k = n;
		while (k > 1) {
			k = __builtin_popcount(k);
			++cnt[n];
		}
	}
	for (int i = 0; i < N; ++i)
		C[i][0] = 1;
	for (int i = 1; i < N; ++i)
		for (int j = 1; j < N; ++j)
			C[i][j] = sum(C[i - 1][j], C[i - 1][j - 1]);
	string s;
	ll k;
	cin >> s >> k;
	plusone(s);
	if (k == 0) {
		cout << 1;
		return 0;
	}
	if (k > 5) {
		cout << 0;
		return 0;
	}
	ll n = s.size();
	ll curr = -1;
	for (int i = 0; i < n; ++i)
		if (s[i] == '1') {
			++curr;
			for (int t = 0; t < n - i; ++t) {
				//cout << n - i - 1 << ' ' << t << '\n'; 
				myplus(ans[cnt[t + curr] + 1], C[n - i - 1][t]);
			}
		}
	cout << ans[k] - (k == 1) * 2;
	return 0;
}