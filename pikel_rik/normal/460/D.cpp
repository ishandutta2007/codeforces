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

ll l, r;
int k;

ll last(ll x) {
    for (int i = 40; i >= 0; i--) {
        if (x & (1ll << i))
            return (1ll << i);
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> l >> r >> k;

    if (k == 1) {
        cout << l << "\n";
        cout << 1 << "\n" << l << "\n";
        return 0;
    }

    if (r == l + 1) {
        if ((l ^ r) < l) {
            cout << (l ^ r) << "\n";
            cout << 2 << "\n" << l << " " << r << "\n";
        }
        else {
            cout << l << "\n";
            cout << 1 << "\n" << l << "\n";
        }
        return 0;
    }

    if (k == 2) {
        if (l % 2 != 0)
            l++;
        cout << 1 << "\n" << 2 << "\n" << l << " " << l + 1 << "\n";
        return 0;
    }

    if (k == 4) {
        if (r - l + 1 == 4 and (l & 1)) {
            vector<ll> a = {l, l + 1, l + 2, l + 3};

            vector<ll> ans = {l};
            ll best = l;

            for (int mask = 1; mask < (1 << 4); mask++) {
                vector<ll> temp;
                ll sum = 0;

                for (int i = 0; i < 4; i++) {
                    if (mask & (1 << i)) {
                        temp.push_back(a[i]);
                        sum ^= a[i];
                    }
                }

                if (sum < best) {
                    best = sum;
                    ans = temp;
                }
            }

            cout << best << "\n" << ans.size() << "\n";
            for (ll i : ans) cout << i << " "; cout << "\n";
        }
        else {
            if (l & 1)
                l++;
            cout << 0 << "\n" << 4 << "\n" << l << " " << l + 1 << " " << l + 2 << " " << l + 3 << "\n";
        }
        return 0;
    }

    if (k > 4) {
        if (l & 1)
            l++;
        cout << 0 << "\n" << 4 << "\n" << l << " " << l + 1 << " " << l + 2 << " " << l + 3 << "\n";
        return 0;
    }

    for (int i = 0; i < 40; i++) {
        ll num1 = ((r >> i) << i), num2 = r ^ num1;
        if (num1 == 0 or num1 == r) continue;

        for (int j = 40; j >= 0; j--) {
            if (r & (1ll << j))
                continue;
            ll pos1 = num1 | (1ll << j), pos2 = num2 | (1ll << j);
            if (pos1 <= r and pos2 <= r) {
                num1 |= (1ll << j);
                num2 |= (1ll << j);
            }
        }
        if (num1 >= l and num2 >= l and num1 <= r and num2 <= r) {
            cout << 0 << "\n" << 3 << "\n" << r << " " << num1 << " " << num2 << "\n";
            return 0;
        }
    }

    ll temp = r;
    r = last(r) - 1;
    if (r >= l) {
        for (int i = 0; i < 40; i++) {
            ll num1 = ((r >> i) << i), num2 = r ^ num1;
            if (num1 >= l and num2 >= l and num1 <= temp and num2 <= temp) {
                cout << 0 << "\n" << 3 << r << " " << num1 << " " << num2 << "\n";
                return 0;
            }
        }
    }

    if (l & 1)
        l++;
    cout << 1 << "\n" << 2 << "\n" << l << " " << l + 1 << "\n";
    return 0;
}