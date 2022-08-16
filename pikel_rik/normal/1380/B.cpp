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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = s.length();

        int c1 = 0, c2 = 0, c3 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R')
                c1++;
            else if (s[i] == 'S')
                c2++;
            else c3++;
        }

        string ans;
        if (c1 == max({c1, c2, c3}))
            ans = string(n, 'P');
        else if (c2 == max({c1, c2, c3}))
            ans = string(n, 'R');
        else ans = string(n, 'S');

        cout << ans << "\n";
    }
    return 0;
}