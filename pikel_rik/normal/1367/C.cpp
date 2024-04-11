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
        int n, k;
        cin >> n >> k;

        string s = "1";
        for (int i = 0; i < k; i++) s += '0';

        string temp;
        cin >> temp;
        s += temp;

        for (int i = 0; i < k; i++) s += '0';
        s += '1';

        vector<int> pos;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1')
                pos.push_back(i);
        }

        int ans = 0;
        for (int i = 1; i < pos.size(); i++) {
            ans += max(0, (pos[i] - pos[i - 1]) / (k + 1) - 1);
        }

        cout << ans << "\n";
    }
    return 0;
}