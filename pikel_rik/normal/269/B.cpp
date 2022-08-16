#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

const int N = 3e3 + 5;

int n, m, a[5001];
double x[5001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i] >> x[i];

    int dp[n];

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[i] >= a[j])
                dp[i] = max(dp[i], 1 + dp[j]);
        }
    }

    cout << n - *max_element(dp, dp + n) << "\n";
    return 0;
}