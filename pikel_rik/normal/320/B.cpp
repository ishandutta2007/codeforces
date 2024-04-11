#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 998244353;
const int inf = 2e9 + 5;

map<int, map<int, bool>> v;
map<int, map<int, vector<pi>>> g;

void dfs(int x, int y) {
    v[x][y] = true;

    for (auto const &i : g[x][y]) {
        if (!v[i.first][i.second])
            dfs(i.first, i.second);
    }
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<pi> a;

    while (n--) {
        int t, x, y;
        cin >> t >> x >> y;

        if (t == 1) {
            for (auto const &i : a) {
                if ((i.first < x and x < i.second) or (i.first < y and y < i.second))
                    g[x][y].push_back({i.first, i.second});
                if ((x < i.first and i.first < y) or (x < i.second and i.second < y))
                    g[i.first][i.second].push_back({x, y});
            }
            a.emplace_back(x, y);
            continue;
        }

        for (auto const &i : a) {
            v[i.first][i.second] = false;
        }

        dfs(a[x-1].first, a[x-1].second);

        if (v[a[y-1].first][a[y-1].second])
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}