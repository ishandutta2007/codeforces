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
const int N = 1e5 + 1;

int n, c[N], w[N], col;
vector<int> g[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i] >> w[i];

    set<pair<int, int>> s[2];
    for (int i = 1; i <= n; i++)
        s[c[i]].insert({w[i], i});

    while (!s[0].empty() and !s[1].empty()) {
        pair<int, int> p1 = *s[0].begin(), p2 = *s[1].begin();

        s[0].erase(s[0].begin());
        s[1].erase(s[1].begin());

        cout << p1.second << " " << p2.second << " " << min(p1.first, p2.first) << "\n";
        g[p1.second].push_back(p2.second);
        g[p2.second].push_back(p1.second);

        if (p1.first >= p2.first) {
            p1.first -= p2.first;
            s[0].insert(p1);
        }
        else if (p1.first < p2.first) {
            p2.first -= p1.first;
            s[1].insert(p2);
        }
    }

    if (s[0].empty()) {
        int v = (*s[1].begin()).second;
        v = g[v][0];

        s[1].erase(s[1].begin());
        while (!s[1].empty()) {
            cout << (*s[1].begin()).second << " " << v << " 0\n";
            s[1].erase(s[1].begin());
        }
    }
    else if (s[1].empty()) {
        int v = (*s[0].begin()).second;
        v = g[v][0];

        s[0].erase(s[0].begin());
        while (!s[0].empty()) {
            cout << (*s[0].begin()).second << " " << v << " 0\n";
            s[0].erase(s[0].begin());
        }
    }
    return 0;
}