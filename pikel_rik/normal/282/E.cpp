#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n;
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    multiset<ll> s;
    ll suf = 0;
    s.insert(suf);

    for (int i = n - 1; i >= 0; i--) {
        suf ^= a[i];
        s.insert(suf);
    }

    ll pref = 0, best = *s.rbegin();
    for (int i = 0; i < n; i++) {
        pref ^= a[i];
        s.erase(s.find(suf));

        suf ^= a[i];

        ll lo = 0, hi = (1ll << 40) - 1;

        for (int j = 39; j >= 0; j--) {
            if (pref & (1ll << j)) {
                auto it = s.lower_bound(lo);
                if (it != s.end() and *it <= hi - (1ll << j))
                    hi -= (1ll << j);
                else lo += (1ll << j);
            }
            else {
                auto it = s.lower_bound(lo + (1ll << j));
                if (it != s.end() and *it <= hi)
                    lo += (1ll << j);
                else hi -= (1ll << j);
            }
        }
        best = max(best, pref ^ lo);
    }

    cout << best << "\n";
    return 0;
}