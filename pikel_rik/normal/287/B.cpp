#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

ll f(ll n) {
    return (n * (n + 1)) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    if (n == 1) {
        cout << "0\n";
        return 0;
    }

    if (n <= k) {
        cout << "1\n";
        return 0;
    }

    if (n > k + f(k - 2)) {
        cout << "-1\n";
        return 0;
    }

    n -= k;
    ll ans = 1;
    k -= 2;

    ll lo = 1, hi = min(n, k), num = min(n, k);
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (f(num) - f(mid) <= n)
            hi = mid;
        else lo = mid + 1;
    }

    ans += num - lo + (f(num) - f(lo) != n ? 1 : 0);
    cout << ans << "\n";
    return 0;   
}