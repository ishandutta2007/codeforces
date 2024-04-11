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

    ll n;
    cin >> n;

    ll a, b, c;
    cin >> a >> b >> c;

    if (a <= b - c or n < b) {
        cout << n / a << "\n";
        return 0;
    }

    n -= b;
    b -= c;

    cout << n / b + 1 + (c + n % b) / a;
    return 0;
}