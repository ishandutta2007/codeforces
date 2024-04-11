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
const int N = 3e5 + 5;

int n, k;
pair<int, int> a[N];
ll pref[N];

ll sum(int l, int r) {
    return pref[r] - pref[l - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].first, a[i].second = i;
    cin >> k;

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i].first;
    }

    int best = 1;
    ll cur = 0, best_val = 0;

    for (int i = 1; i < k; i++) {
        cur += sum(i + 1, k) - (k - i) * (ll)a[i].first;
    }

    best_val = cur;
    for (int i = 2; i + k <= n + 1; i++) {
        cur -= sum(i, i + k - 2) - (k - 1) * (ll)a[i - 1].first;
        cur += (k - 1) * (ll)a[i + k - 1].first - sum(i, i + k - 2);
        if (cur < best_val) {
            best = i;
            best_val = cur;
        }
    }

    for (int i = best; i <= best + k - 1; i++) cout << a[i].second << " ";
    cout << '\n';
    return 0;
}