#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    ll ans = LLONG_MAX;
    for (int num = 1;; num++) {
        ll pow = 1;

        ll sum = 0;
        for (int i = 0; i < n && sum < ans; i++) {
            sum += abs(pow - a[i]);
            pow *= num;
        }
        if (sum >= ans)
            break;
        ans = min(ans, sum);
    }

    cout << ans << '\n';
    return 0;
}