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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int a, b;
    cin >> a >> b;

    ll ans = 0;
    for (int i = 1; i < b; i++) { //ibk + i from k = 1 to a => ik(sum(b)) + a => ika(a+1)/2 + a
        ans = (ans + i * (ll)b % mod * (((a * (ll)(a + 1)) / 2) % mod) % mod + i * (ll)a % mod) % mod;
    }

    cout << ans << "\n";
    return 0;
}