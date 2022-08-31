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
//    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int m;
        cin >> m;

        vector<int> b(m);
        for (int i = 0; i < m; i++) cin >> b[i];

        sort(all(s));

        string ans;
        for (int i = 0; i < m; i++) ans += ' ';

        while (count(all(ans), ' ')) {
            vector<int> pos;

            for (int i = 0; i < m; i++) {
                if (b[i] == 0 and ans[i] == ' ')
                    pos.push_back(i);
            }

            int cnt = 0;
            char ch;

            while (cnt < pos.size()) {
                cnt = 0;
                char c = s.back();
                while (!s.empty() and s.back() == c)
                    s.pop_back(), cnt++;
                ch = c;
            }

            for (int j : pos) {
                ans[j] = ch;
            }

            for (int i = 0; i < m; i++) {
                if (!b[i]) continue;
                for (int j : pos) {
                    b[i] -= abs(i - j);
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}