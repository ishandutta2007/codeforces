#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> cnt(20);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 20; j++) {
            if (a[i] & (1 << j))
                cnt[j]++;
        }
    }

    ll ans = 0;
    while (accumulate(all(cnt), 0)) {
        int best = inf;
        for (int i = 0; i < 20; i++) {
            if (cnt[i] == 0) continue;
            best = min(best, cnt[i]);
        }

        int num = 0;
        for (int i = 0; i < 20; i++) {
            if (cnt[i] == 0) continue;
            cnt[i] -= best;
            num |= (1 << i);
        }

        ans += best * (ll)num * num;
    }

    cout << ans << "\n";
    return 0;
}