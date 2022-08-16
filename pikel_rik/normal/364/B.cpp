#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 50 + 5;

int n, d, a[N];
bitset<10000*N> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];

    dp[0] = true;
    for (int i = 1; i <= n; i++)
        dp |= dp << a[i];

    int x = 0, ans = 0;
    while (true) {
        int j = ans + d;
        while (!dp[j] and j > ans) j--;
        if (j == ans)
            break;
        ans = j;
        x++;
    }

    cout << ans << " " << x << "\n";
    return 0;
}