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
const int N = 500 + 5;

int n, a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int j = 0; j < n; j++) cin >> b[j];

        if (n % 2 != 0 and a[n / 2] != b[n / 2]) {
            cout << "No\n";
            continue;
        }

        multiset<pair<int, int>> s;
        for (int i = 0; i < n / 2; i++) {
            s.insert({a[i], a[n - i - 1]});
        }

        bool flag = false;
        for (int i = 0; i < n / 2; i++) {
            if (s.find({b[i], b[n - i - 1]}) != s.end()) {
                s.erase(s.find({b[i], b[n - i - 1]}));
            }
            else if (s.find({b[n - i - 1], b[i]}) != s.end()) {
                s.erase(s.find({b[n - i - 1], b[i]}));
            }
            else {
                flag = true;
                break;
            }
        }

        if (flag) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}