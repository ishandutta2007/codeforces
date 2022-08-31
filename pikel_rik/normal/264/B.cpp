#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

const int N = 1e5 + 5;

int n, a[N], dp[N], d[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n == 1 and a[0] == 1) {
        cout << "1\n";
        return 0;
    }

    int best = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;

        for (int j = 2; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                dp[i] = max(dp[i], 1 + d[j]);
                if (j != a[i] / j)
                    dp[i] = max(dp[i], 1 + d[a[i] / j]);
            }
        }

        for (int j = 2; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                d[j] = max(d[j], dp[i]);
                d[a[i] / j] = max(d[a[i] / j], dp[i]);
            }
        }

        d[a[i]] = dp[i];
        best = max(best, dp[i]);
    }

    cout << best << "\n";
    return 0;
}