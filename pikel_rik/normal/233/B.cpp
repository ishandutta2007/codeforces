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

int sod(ll x) {
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll n;
    cin >> n;

    int smallest = INT_MAX;
    for (int i = 1; i <= 9 * 18; i++) {
        ll d = i * i + 4 * n;

        int r = (-i + floor(sqrt(d))) / 2;
        if (r * (ll)r + i * (ll)r - n == 0 and sod(r) == i and r > 0)
            smallest = min(smallest, r);
    }

    if (smallest == INT_MAX)
        cout << "-1\n";
    else cout << smallest << "\n";
    return 0;
}