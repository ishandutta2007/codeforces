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

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int pos = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0')
                pos = i;
        }

        if (pos == -1) {
            cout << s << "\n";
            continue;
        }

        string ans = s.substr(pos, s.length());

        int pos1 = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                pos1 = i;
                break;
            }
        }

        if (pos1 == -1 or pos1 > pos) {
            cout << s << "\n";
            continue;
        }
        ans = s.substr(0, pos1) + ans;
        cout << ans << "\n";
    }
    return 0;
}