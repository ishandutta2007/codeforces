#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld EPS = 1e-7;

const int N = (int) 2e5 + 123;

int n;
ll a[N], p[N], dp[N];

int run() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    partial_sum(a, a + n, p);
    
    
    dp[n] = 0;
    ll cur = p[n - 1] - dp[n];
    for (int i = n - 1; i >= 1; i--) {
        dp[i] = cur;
        cur = max(cur, p[i - 1] - dp[i]);
    }
    
    cout << dp[1] << "\n";
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return run();
}