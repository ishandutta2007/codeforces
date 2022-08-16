#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 5000 + 5;

int n, a[N], dp[N], ans[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    ans[1] = a[1];
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        int sum = 0;
        for (int j = i; j >= 1; j--) {
            sum += a[j];
            if (sum >= ans[j - 1]) {
                dp[i] = 1 + dp[j - 1];
                ans[i] = sum;
                break;
            }
        }
    }

    cout << n - dp[n] << '\n';
    return 0;
}