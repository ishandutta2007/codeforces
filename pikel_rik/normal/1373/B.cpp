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
        vector<int> a;
        int cur = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                a.push_back(cur);
                cur = 0;
            }
            cur++;
        }
        a.push_back(cur);

        int num = 0;
        for (int i = 1; i < a.size(); i++) {
            num += min(a[i], a[i - 1]);
            if (a[i] == a[i - 1])
                i++;
            else if (a[i] > a[i - 1])
                a[i] -= a[i - 1];
            else {
                if (i + 1 < a.size()) {
                    a[i + 1] += a[i - 1] - a[i];
                    i++;
                }
            }
        }

        if (num % 2 == 0)
            cout << "NET\n";
        else cout << "DA\n";
    }
    return 0;
}