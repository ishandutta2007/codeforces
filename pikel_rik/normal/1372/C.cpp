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

int n, a[N], pos[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
            pos[a[i]] = i;
        }

        int c = 0, len1 = 0, len2 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == i)
                len1++;
            else break;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (a[i] == i)
                len2++;
            else break;
        }

        for (int i = len1; i < n - len2; i++) {
            if (a[i] == i)
                c++;
        }

        if (len1 == n) cout << 0 << "\n";
        else if (c == 0) cout << 1 << "\n";
        else cout << 2 << "\n";
    }
    return 0;
}