#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 5;

int n, m, a[N], b[N];
ll pref_a[N], pref_b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    for (int i = 1; i <= n; i++) pref_a[i] = pref_a[i-1] + a[i];
    for (int i = 1; i <= m; i++) pref_b[i] = pref_b[i-1] + b[i];

    ll best = LLONG_MAX;

    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i-1]) continue;
        int it = upper_bound(b + 1, b + m + 1, a[i]) - b;

        ll cost1 = (i - 1) * (ll)a[i] - pref_a[i-1];
        ll cost2 = (it != m + 1 ? pref_b[m] - pref_b[it - 1] - (m - it + 1) * (ll)a[i] : 0);

        best = min(best, cost1 + cost2);
//        cout << cost1 + cost2 << " ";
    }

    for (int i = 1; i <= m; i++) {
        if (b[i] == b[i-1]) continue;
        int it = lower_bound(a + 1, a + n + 1, b[i]) - a;
        int it2 = upper_bound(b + 1, b + m + 1, b[i]) - b;

        ll cost2 = (it2 != m + 1 ? pref_b[m] - pref_b[it2-1] - (m - it2 + 1) * (ll)b[i] : 0);
        ll cost1 = (it - 1) * (ll)b[i] - pref_a[it-1];

        best = min(best, cost1 + cost2);
//        cout << cost1 + cost2 << " ";
    }

    cout << best << "\n";
    return 0;
}