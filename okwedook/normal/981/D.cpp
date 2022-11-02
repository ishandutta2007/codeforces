#pragma GCC optimize("O3","unroll-loops")
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
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

#include <bits/stdc++.h>
using namespace std;

template<typename T1, typename T2> inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2> inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1> inline void sort(T1 &arr) { sort(arr.begin(), arr.end()); }
template<typename T1> inline void shuffle(T1 &arr) { 
    for (int i = -arr.size(); i < arr.size(); ++i) {
        int f = ((rand() << 16) + rand()) % arr.size(), s = ((rand() << 16) + rand()) % arr.size();
        swap(arr[f], arr[s]);
    }
}
template<typename T1> inline void reverse(T1 &arr) { reverse(arr.begin(), arr.end()); }
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

vector<ll> arr;
vector<vector<ll>> sum;

signed main() {
	FAST;
	ll n, kek;
	cin >> n >> kek;
	arr = vector<ll> (n);
	sum = vector<vector<ll>>(100, vector<ll>(100, 0));
	for (auto &i : arr) cin >> i;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= i; ++j)
			for (int k = j; k <= i; ++k)
				sum[j][i] += arr[k];
	vector<vector<ll>> dp(100, vector<ll>(100));
	vector<ll> pow2(61);
	pow2[0] = 1;
	for (int i = 1; i < 61; ++i) pow2[i] = pow2[i - 1] * 2;
	ll ans = 0;
	for (int k = 60; k >= 0; --k) {
		ll check = ans | pow2[k];
		for (int i = 1; i <= kek; ++i)
			for (int j = 0; j < n; ++j)
				if (i == 1 && (sum[0][j] | check) == sum[0][j]) dp[i][j] = sum[0][j];
				else dp[i][j] = -1;
		for (int l = 1; l < kek; ++l)
			for (int i = 0; i < n; ++i)
				for (int j = 1; j <= i; ++j) 
					if (dp[l][j - 1] != -1 && (sum[j][i] | check) == sum[j][i])
						checkmax(dp[l + 1][i], dp[l][j - 1] & sum[j][i]);
		if (dp[kek][n - 1] != -1) ans |= pow2[k];
	}
	cout << ans;
    return 0;
}