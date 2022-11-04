#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;

constexpr ll INF = 1e18;


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, d;
    cin >> n >> d;
    vector<int> a(n + 1);
    vector<double> loga(n + 1);
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    	loga[i] = log(a[i]);
    }

    vector<vector<double>> dp(n + 1, vector<double>(10, -INF));
    vector<vector<int>> from(n + 1, vector<int>(10, -1));
    dp[0][1] = 0;

    for (int i = 0; i < n; i++) {
    	for (int dig = 0; dig < 10; dig++) {
    		if (dp[i][dig] == -INF)
    			continue;

    		auto Update = [&dp, &from](int i, int new_dig, int dig, double val) {
    			if (val > dp[i][new_dig]) {
    				dp[i][new_dig] = val;
    				from[i][new_dig] = dig;
    			}
    		};

    		Update(i + 1, dig, dig, dp[i][dig]);

    		int new_dig = (dig * a[i + 1]) % 10;
    		Update(i + 1, new_dig, dig, dp[i][dig] + loga[i + 1]);
    	}
    }

    // for (int i = 1; i <= n; i++) {
    // 	for (int j = 0; j < 10; j++) {
    // 		if (dp[i][j] < 0) {
    // 			cerr << -1 << " ";
    // 		} else {
    // 			cerr << exp(dp[i][j]) << " ";
    // 		}
    // 	}
    // 	cerr << "\n";
    // }

    if (dp[n][d] < 0 || from[n][d] == -1) {
    	cout << -1;
    	return 0;
    }

    vector<int> sol;
    int dig = d, i = n;
    while (i > 0) {
    	if ((from[i][dig] * a[i]) % 10 == dig) {
    		sol.push_back(i);
    	}
    	dig = from[i][dig];
    	i--;
    }

    if (sol.size() == 0) {
    	cout << -1;
    	return 0;
    }

    cout << sol.size() << "\n";
    for (auto it : sol) {
    	cout << a[it] << " ";
    }

    return 0;
}