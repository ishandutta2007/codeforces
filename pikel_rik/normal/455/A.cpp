#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int m = *max_element(all(a));
    vi count(m + 1);
    for (int i = 0; i < n; i++) count[a[i]] += 1;

    ll dp[m+1];
    dp[0] = 0;
    dp[1] = count[1];

    for (int i = 2; i <= m; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + i * (ll)count[i]);
    }

    cout << dp[m];
    return 0;
}