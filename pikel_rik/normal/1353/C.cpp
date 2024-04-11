#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        ll ans = 0;

        for (int i = n; i >= 1; i -= 2) {
            ans += (i / 2) * (ll)(4 * i - 4);
        }

        cout << ans << "\n";
    }
    return 0;
}