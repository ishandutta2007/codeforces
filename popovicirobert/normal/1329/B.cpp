#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;



int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
    int t, i, j;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
	    int d, m; cin >> d >> m;
	    vector<int> dp(100);
	   	dp[0] = 1;
	   	for(i = 1; (1 << i) <= d; i++) {
	   		for(j = i - 1; j >= 0; j--) {
	   			dp[i] = (dp[i] + dp[j]) % m;
	   		}
	   		int coef = (1 << i);
	   		if((1 << (i + 1)) > d) {
	   			coef = d - (1 << i) + 1;
	   		}
	   		dp[i]++;
	   		dp[i] = (1LL * dp[i] * coef) % m;
	   	}
	   	int ans = 0;
	   	for(i = 0; i < 100; i++) {
	   		ans = (ans + dp[i]) % m;
	   	}
	   	cout << ans << "\n";
  	}

    return 0;
}