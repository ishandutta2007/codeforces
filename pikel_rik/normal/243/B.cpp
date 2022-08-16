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

int n, m, h, t;
vector<int> g[N];
vector<pair<int, int>> edges;

vector<int> intersect(int u, int v) {
    int c = 0;
    if (g[u].size() > g[v].size())
        swap(u, v);

    vector<int> I;
    for (int &i : g[u]) {
        if (binary_search(all(g[v]), i))
            I.push_back(i);
    }
    return I;
}

void check1(int u, int v) {
    if (g[u].size() >= t + h + 1 and g[v].size() >= t + h + 1) {
        cout << "YES\n";
        cout << u << " " << v << "\n";

        set<int> temp;
        vector<int> ans1, ans2;

        for (int &x: g[u]) {
            if (x != v and ans1.size() < h)
                ans1.push_back(x), temp.insert(x);
        }
        for (int &x: g[v]) {
            if (x != u and temp.find(x) == temp.end() and ans2.size() < t)
                ans2.push_back(x);
        }

        for (int i : ans1) cout << i << " "; cout << "\n";
        for (int i : ans2) cout << i << " "; cout << "\n";
        cout << "\n";
        exit(0);
    }
}

void check2(int u, int v, vector<int> I) {
    if (g[u].size() >= h + 1 and g[v].size() >= t + 1 and g[u].size() + g[v].size() - I.size() >= h + t + 2) {
        cout << "YES\n";
        cout << u << " " << v << "\n";

        vector<int> ans1, ans2;
        for (int &x : g[u]) {
            if (x != v and !binary_search(all(I), x) and ans1.size() < h)
                ans1.push_back(x);
        }
        for (int &x : g[v]) {
            if (x != u and !binary_search(all(I), x) and ans2.size() < t)
                ans2.push_back(x);
        }

        while (ans1.size() < h) {
            ans1.push_back(I.back());
            I.pop_back();
        }

        while (ans2.size() < t) {
            ans2.push_back(I.back());
            I.pop_back();
        }

        for (int x : ans1) cout << x << " "; cout << "\n";
        for (int x : ans2) cout << x << " "; cout << "\n";
        exit(0);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> h >> t;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.emplace_back(u, v);
    }

    for (int i = 1; i <= n; i++)
        sort(all(g[i]));

    for (int i = 0; i < m; i++) {
        int u = edges[i].first, v = edges[i].second;

        if (!(g[u].size() >= h + 1 and g[v].size() >= t + 1) and !(g[u].size() >= t + 1 and g[v].size() >= h + 1))
            continue;

        check1(u, v);
        vector<int> I = intersect(u, v);
        check2(u, v, I);
        check2(v, u, I);
    }

    cout << "NO\n";
    return 0;
}