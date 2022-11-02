#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
const int sz = 1e2 + 3, mxsm = 20020;
int n;
pii a[sz];
int dp[sz][mxsm], prv[sz][mxsm];

int main() {
	fast;
	cin >> n;
	int smhf = 0;
	foru(i, 0, n) {
		cin >> a[i].ff >> a[i].ss;
		smhf += a[i].ss;
	}
	for (int j = 0; j <= n + 2; j++) {
		for (int sm = 1; sm <= 10000; sm++) {
			dp[j][sm] = -1;
			prv[j][sm] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		const int bnd = 100 * (i + 1);//CHANGE
		for (int j = 1; j <= i + 1; j++) {
			for (int sm = 0; sm <= bnd; sm++) {
				dp[j][sm] = prv[j][sm];
				if (prv[j - 1][max(sm - a[i].ss, 0)] != -1)dp[j][sm] = max(dp[j][sm], prv[j - 1][max(sm - a[i].ss, 0)] + 2 * a[i].ff);
			}
		}
		for (int j = 1; j <= i + 1; j++) {
			for (int sm = 0; sm <= bnd; sm++) {
				prv[j][sm] = dp[j][sm];
				dp[j][sm] = -1;
			}
		}
		for (int sm = 0; sm <= bnd + 100; sm++) {
			prv[i + 2][sm] = -1;
		}
	}
	for (int k = 0; k < n; k++) {
		int bst = 0;
		for (int sm = 0; sm <= 10000; sm++) {
			bst = max(bst, min(sm + smhf, prv[k + 1][sm]));
		}
		cout << fixed<<setprecision(11)<<(ld)bst / 2 << ' ';
	}
	return 0;
}