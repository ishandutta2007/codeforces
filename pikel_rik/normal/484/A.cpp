#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int pop(ll x) {
    int c = 0;
    for (int i = 0; i <= 60; i++) {
        if (x & (1LL << i))
            c += 1;
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        ll l, r;
        cin >> l >> r;

        ll best = 0;
        for (int i = 60; i >= 0; i--) {
            if ((l & (1LL << i)) == (r & (1LL << i)))
                continue;

            best = (r ^ (1LL << i)) | ((1LL << i) - 1);
            break;
        }

        if (pop(r) > pop(best))
            best = r;
        if (pop(l) > pop(best))
            best = l;

        cout << best << "\n";
    }
    return 0;
}