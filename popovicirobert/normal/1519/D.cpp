#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;



int main() {
#ifdef HOME
    ifstream cin("C.in");
    ofstream cout("C.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<ll> pref(n), suff(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		pref[i] = (i > 0 ? pref[i - 1] : 0) + 1LL * a[i] * b[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		suff[i] = suff[i + 1] + 1LL * a[i] * b[i];
	}

	ll answer = pref[n - 1];
	vector<vector<ll>> dp(n, vector<ll>(n));

	for (int i = 0; i < n; i++) {
		dp[i][i] = 1LL * a[i] * b[i];
		if (i + 1 < n) {
			dp[i][i + 1] = 1LL * a[i] * b[i + 1] + 1LL * a[i + 1] * b[i];
			int j = i + 1;
			answer = max(answer, dp[i][j] + (i > 0 ? pref[i - 1] : 0) + suff[j + 1]);
		}
	}
	for (int len = 2; len < n; len++) {
		for (int i = 0; i + len < n; i++) {
			int j = i + len;
			dp[i][j] = dp[i + 1][j - 1] + 1LL * a[j] * b[i] + 1LL * b[j] * a[i];
			answer = max(answer, dp[i][j] + (i > 0 ? pref[i - 1] : 0) + suff[j + 1]);
		}
	}

	cout << answer;

    return 0;
}