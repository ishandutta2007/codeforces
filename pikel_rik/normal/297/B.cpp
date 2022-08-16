#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ull = unsigned long long;
using ll = long long;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    if (n > m) {
        cout << "YES\n";
        return 0;
    }

    vector<int> bob(m), alice(n);
    for (int i = 0; i < n; i++) cin >> alice[i];
    for (int i = 0; i < m; i++) cin >> bob[i];

    sort(all(alice));
    sort(all(bob));

    for (int i = 0; i < n; i++) {
        if (i > 0 and alice[i] == alice[i-1]) continue;

        int c = lower_bound(all(alice), alice[i]) - alice.begin();
        int idx = lower_bound(all(bob), alice[i]) - bob.begin();

        if (n - c > m - idx) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}