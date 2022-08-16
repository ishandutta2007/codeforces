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
const int N = 1e5 + 5;

int n, a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    set<int, greater<>> s;
    for (int i = 0; i <= n; i++)
        s.insert(i);

    for (int i = n; i >= 2; i--) {
        s.erase(a[i]);
        if (a[i] > a[i-1]) {
            b[i] = a[i-1];
        }
        else {
            b[i] = *s.begin();
            s.erase(s.begin());
        }
    }

    s.erase(a[1]);
    b[1] = *s.begin();
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
    return 0;
}