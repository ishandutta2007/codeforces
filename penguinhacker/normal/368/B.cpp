#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	int n, m, a[100000];
	cin >> n >> m;
	for (int i=0; i<n; ++i) cin >> a[i];
    
    int dp[100000];
    dp[n-1] = 1;
    unordered_set<int> s;
    s.insert(a[n-1]);
    for (int i=n-2; i>=0; --i) {
        if (s.find(a[i]) != s.end()) {
            dp[i] = dp[i+1];
        }
        else dp[i] = dp[i+1] + 1;
        s.insert(a[i]);
    }

    while (m--) {
        int k;
        cin >> k;
        cout << dp[k-1] << '\n';
    }
	return 0;
}