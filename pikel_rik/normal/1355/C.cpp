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
const int N = 1e6 + 1;

ll pref[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    for (int i = a; i <= b; i++) {
        pref[i + b] += 1;
        pref[i + c + 1] -= 1;
    }

    for (int i = 1; i < N; i++)
        pref[i] += pref[i-1];
    for (int i = 1; i < N; i++)
        pref[i] += pref[i-1];

    ll ans = 0;
    for (int i = c; i <= d; i++) {
        ans += pref[N-1] - pref[i];
    }

    cout << ans << "\n";
    return 0;
}