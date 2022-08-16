#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n;
ld p[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];

    ld ans = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        ans += 2 * sum * p[i] + p[i];
        sum = sum * p[i] + p[i];
    }

    cout << fixed << setprecision(12);
    cout << ans << "\n";
    return 0;
}