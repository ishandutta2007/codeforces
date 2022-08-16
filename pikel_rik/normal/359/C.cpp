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

ll modexp(ll x, ll n) {
    ll ans = 1;
    while (n) {
        if (n & 1) ans = ans * x % mod;
        x = x * x % mod;
        n /= 2;
    }
    return ans;
}

int n, x, a[N];
map<ll, int> cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll sum = accumulate(a, a + n, 0ll);
    for (int i = 0; i < n; i++) {
        cnt[sum - a[i]]++;
    }

    ll num = 0;
    while (true) {
        ll now = (*cnt.begin()).first, c = (*cnt.begin()).second;
        if (c % x) break;

        cnt.erase(cnt.begin());
        cnt[now + 1] += c / x;
    }

    num = min((*cnt.begin()).first, sum);
    cout << modexp(x, num) << "\n";
    return 0;
}