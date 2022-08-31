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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll k;
    cin >> k;

    vector<int> cnt(10, 1);

    while (true) {
        ll ans = 1;
        for (int i = 0; i < 10; i++)
            ans *= cnt[i];

        if (ans >= k)
            break;

        int best = 0, best_val = inf;
        for (int i = 0; i < 10; i++) {
            if (best_val > cnt[i]) {
                best_val = cnt[i];
                best = i;
            }
        }
        cnt[best]++;
    }

    string s = "codeforces";

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < cnt[i]; j++)
            cout << s[i];
    }
    cout << "\n";
    return 0;
}