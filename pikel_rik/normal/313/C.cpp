#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int no(int x) {
    int c = 0;
    while (x > 0)
        x /= 4, c += 1;
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(all(a));
    int sz = 1, cur = 0, times = no(n);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[n - i - 1] * (ll)times;
        if (i + 1 == pow(4, cur)) {
            cur += 1;
            times -= 1;
        }
    }

    cout << ans << "\n";
    return 0;
}