#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

const int N = 3e3 + 5;

int n, a[N], b[N], c[N], dp0[N], dp1[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    dp0[n - 1] = a[n - 1];
    dp1[n - 1] = (n - 1 == 0 ? a[n - 1] : b[n - 1]);

    for (int i = n - 2; i >= 0; i--) {
        dp0[i] = max(a[i] + dp1[i + 1], b[i] + dp0[i + 1]);
        dp1[i] = max((i == 0 ? b[i] : c[i]) + dp0[i + 1], (i == 0 ? a[i] : b[i]) + dp1[i + 1]);
    }

    cout << dp1[0] << "\n";
    return 0;
}