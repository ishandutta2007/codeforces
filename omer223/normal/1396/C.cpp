#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <bitset>
#include <stack>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e6 + 5;
ll a[sz], n, r[3], d, dp[sz][2];//without, with

void input() {
	cin >> n;
	foru(i, 0, 3)cin >> r[i];
	cin >> d;
	foru(i, 0, n)cin >> a[i + 1];
}


int main() {
	fast;
	input();
	ll tot = (n - 1)*d, o1, o2, o3 = r[1] + 2 * d + r[0], mnc, mnp, o1p, o2p;
	foru(i, 1, n + 1) {
		o1 = a[i] * r[0] + 2 * r[0] + 2 * d;
		o2 = a[i] * r[0] + r[2];
		mnp = min(dp[i - 1][0], dp[i - 1][1]);
		mnc = min(o1, o3);
		dp[i][0] = mnp + o2;
		dp[i][1] = mnc + mnp;
		if (i > 1) {
			o1p = a[i - 1] * r[0] + 2 * r[0] + 2 * d;
			o2p = a[i - 1] * r[0] + r[2];
			ll amt = min(dp[i - 2][0], dp[i - 2][1]) + min(o1p, o3) + mnc - 2 * d;
			if (dp[i][1] > amt)dp[i][1] = amt;
		}
		if (i == n - 1) {
			dp[i][1] = min(dp[i][1], mnp + mnc - d);
		}
	}
	cout << tot + min(dp[n][0], dp[n][1]) << endl;
	return 0;
}