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

int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int n;
pair<int, int> st, fi;
pair<int, pair<int, int>> a[N];

set<pair<int, int>> s;
map<int, map<int, int>> lvl;

int bfs() {
    queue<pair<int, int>> q;
    q.push(st);

    lvl[st.first][st.second] = 0;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int x = p.first + dir[i][0], y = p.second + dir[i][1];
            if (s.find({x, y}) != s.end()) {
                s.erase({x, y});
                lvl[x][y] = lvl[p.first][p.second] + 1;
                q.push({x, y});
            }
        }
    }

    if (!lvl[fi.first][fi.second])
        return -1;
    return lvl[fi.first][fi.second];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> st.first >> st.second >> fi.first >> fi.second;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second.first >> a[i].second.second;
        for (int j = a[i].second.first; j <= a[i].second.second; j++)
            s.emplace(a[i].first, j);
    }

    int lvl = bfs();
    cout << lvl << "\n";
    return 0;
}