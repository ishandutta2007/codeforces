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
const int N = 1e5 + 5;

int n, m, pref[30][N];
vector<pair<pair<int, int>, int>> queries;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int l, r, q;
        cin >> l >> r >> q;

        for (int j = 0; j < 30; j++) {
            if (q & (1 << j)) {
                pref[j][l]++;
                pref[j][r+1]--;
            }
        }
        queries.push_back({{l, r}, q});
    }

    for (int i = 0; i < 30; i++) {
        for (int j = 1; j <= n; j++)
            pref[i][j] += pref[i][j-1];
    }

    for (int i = 0; i < 30; i++) {
        for (int j = 1; j <= n; j++)
            pref[i][j] = (pref[i][j] > 0);
    }

    for (int i = 0; i < 30; i++) {
        for (int j = 1; j <= n; j++)
            pref[i][j] += pref[i][j-1];
    }

    for (auto &p : queries) {
        int l = p.first.first, r = p.first.second, q = p.second;
        int ans = 0;

        for (int i = 0; i < 30; i++) {
            if (pref[i][r] - pref[i][l-1] == r - l + 1)
                ans |= (1 << i);
        }

        if (ans != q) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        int ans = 0;
        for (int j = 0; j < 30; j++) {
            if (pref[j][i] - pref[j][i-1] == 1)
                ans |= (1 << j);
        }
        cout << ans << " ";
    }
    return 0;
}