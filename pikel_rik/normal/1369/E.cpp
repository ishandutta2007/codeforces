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
const int N = 1e5 + 5;

int n, m, w[N];
pair<int, int> a[2*N];
set<int> s[N];
bool visited[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        s[x].insert(i);
        s[y].insert(i);
        a[i] = {x, y};
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (s[i].size() <= w[i])
            q.push(i), visited[i] = true;
    }

    vector<int> ans;
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        vector<int> cs;
        for (int i : s[x]) {
            ans.push_back(i);
            int y;
            if (a[i].first == x)
                y = a[i].second;
            else y = a[i].first;

            s[y].erase(i);
            cs.push_back(y);
        }
        s[x].clear();

        for (int c : cs) {
            if (!visited[c] and s[c].size() <= w[c]) {
                q.push(c);
                visited[c] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!s[i].empty()) {
            cout << "DEAD\n";
            return 0;
        }
    }

    reverse(all(ans));
    cout << "ALIVE\n";
    for (int i : ans) cout << i + 1 << " "; cout << "\n";
    return 0;
}