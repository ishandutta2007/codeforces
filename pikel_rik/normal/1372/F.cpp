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
const int N = 2e5 + 5;

int n, a[N];
map<int, int> mp;

int recurse(int l, int r) {
    if (l > r)
        return l - 1;

    cout << "? " << l << " " << r << "\n"; cout.flush();
    int x, f;
    cin >> x >> f;

    if (mp[x]) {
        for (int i = r - f + 1; i <= r - f + mp[x]; i++)
            a[i] = x;
        recurse(l, r - f);
        int ed = r - f + mp[x] + 1;
        mp[x] = 0;
        return ed;
    }
    mp[x] = f;
    int i = l;
    while (mp[x])
        i = recurse(i, i + f - 1);
    return recurse(i, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    recurse(1, n);

    cout << "! ";
    for (int i = 1; i <= n; i++) cout << a[i] << " "; cout << "\n";
    return 0;
}