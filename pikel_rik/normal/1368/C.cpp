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
const int N = 1e3 + 5;

set<pair<int, int>> s;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> ans = {{0, 0}, {1, 0}, {0, 1}, {1, 1}, {1, 2}, {2, 1}, {2, 2}};
    vector<pair<int, int>> temp = {{1, 0}, {0, 1}, {1, 1}};

    for (int i = 1; i < n; i++) {
        pair<int, int> p = ans.back();
        for (auto &j : temp) {
            ans.emplace_back(p.first + j.first, p.second + j.second);
        }
    }

    cout << ans.size() << "\n";
    for (auto &i : ans) cout << i.first << " " << i.second << "\n";
    return 0;
}