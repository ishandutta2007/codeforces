#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <queue>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, pii> dat;

int n;
const int sz = 5e5;
ll a[3][sz];
ll dp[3][sz];

int main() {
	fast;
	cin >> n;
	foru(i, 0, 3) {
		foru(j, 0, n)cin >> a[i][j];
	}
	dp[2][n-1] = a[2][n-1];
	dp[1][n-1] = a[1][n-1] + dp[2][n-1];
	dp[0][n-1] = a[0][n-1] + dp[1][n-1];
	ll crsm = a[2][n - 1] + a[1][n - 1] + a[0][n - 1], bstrec2 = crsm, bstrec0 = -1e16;//ends with
	ford(i, n - 2, 0) {
		ll colsum = a[2][i] + a[1][i] + a[0][i];
		bstrec2 = max(bstrec2 + colsum, colsum + dp[2][i + 1]);
		bstrec0 = max(bstrec0 + colsum, colsum + dp[0][i + 1]);
		ford(j, 2, 0) {
			ll cur = a[j][i], bst = -1e18;
			if (j == 2) {
				bst = max({ cur + dp[j][i + 1], cur + a[j - 1][i] + dp[j - 1][i + 1], cur + a[j - 1][i] + a[j - 2][i] + dp[j - 2][i + 1] });
				bst = max(bst, bstrec0);
				dp[j][i] = bst;
			}
			else if (j == 1) {
				dp[j][i] = max({ cur + dp[j + 1][i + 1] + a[j + 1][i],cur + dp[j - 1][i + 1]+a[j - 1][i],cur+dp[j][i+1] });
			}
			else {
				bst = max({ cur + dp[j][i + 1], cur + a[j + 1][i] + dp[j + 1][i + 1], cur + a[j + 1][i] + a[j + 2][i] + dp[j + 2][i + 1] });
				bst = max(bst, bstrec2);
				dp[j][i] = bst;
			}
		}
	}
	cout << dp[0][0];
	return 0;
}