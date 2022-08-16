#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
int k;
int dp[100001];

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> v(100001);

    dp[n] = 1;
    dp[0] = 0;
    v[a[n]] = 1;

    for (int i = n-1; i >= 1; i--) {
        if (v[a[i]] == 0) {
            dp[i] = 1 + dp[i+1];
            v[a[i]] = 1;
        }
        else
            dp[i] = dp[i+1];
    }

    while (m--) {
        int l;
        cin >> l;

        cout << dp[l] << "\n";
    }
    return 0;
}