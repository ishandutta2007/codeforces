#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ordered_set = tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 5e5 + 5;

ll pref[N], suf[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, a, b, t;
    cin >> n >> a >> b >> t;

    string s;
    cin >> s;

    pref[0] = 1 + (s[0] == 'w' ? b : 0);

    for (int i = 1; i < n; i++) {
        pref[i] = 1 + pref[i-1] + a + (s[i] == 'w' ? b : 0);
    }

    suf[n-1] = 1 + (s[n-1] == 'w' ? b : 0);
    for (int i = n - 2; i >= 1; i--) {
        suf[i] = 1 + suf[i+1] + a + (s[i] == 'w' ? b : 0);
    }

    int best = 0;
    for (int i = 0; i < n; i++) {
        if (t - pref[i] >= 0)
            best = max(best, i + 1);
        else break;

        ll c = t - pref[i] - a * (i + 1);
        int lo = i + 1, hi = n - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (suf[mid] <= c)
                hi = mid;
            else lo = mid + 1;
        }

        if (c >= suf[lo])
            best = max(best, i + 1 + (n - 1 - lo + 1));
    }

    for (int i = n - 1; i >= 1; i--) {
        if (t - (pref[0] + a + suf[i]) >= 0)
            best = max(best, 1 + n - 1 - i + 1);
        else break;

        ll c = t - suf[i] - a * (n - 1 - i + 2);
        int lo = 0, hi = i - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (pref[mid] <= c)
                lo = mid;
            else hi = mid - 1;
        }

        if (c >= pref[lo])
            best = max(best, (n - 1 - i + 1) + lo + 1);
    }

    cout << best << "\n";
    return 0;
}