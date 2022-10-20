#include <bits/stdc++.h>

using namespace std;

const int N = 400010;

int n;
pair<int, int> a[2][N];
vector<int> vals;
vector<int> addEvent[N], qEvent[N];

struct IT {
    bool t[N << 2];
    bool has[N << 2];
    void init() {
        memset(t, 0, sizeof t);
        memset(has, 0, sizeof has);
    }

    void add(int node, int l, int r, int x, int y) {
        if (x > r || y < l) return;
        if (x <= l && r <= y) {
            t[node] = has[node] = 1;
            return;
        }
        int m = l + r >> 1;
        add(node << 1, l, m, x, y);
        add(node << 1 | 1, m + 1, r, x, y);
        t[node] = has[node] | t[node << 1] | t[node << 1 | 1];
    }

    int get(int node, int l, int r, int x, int y) {
        if (x > r || y < l) return 0;
        if (x <= l && r <= y) {
            return t[node];
        }
        int m = l + r >> 1;
        int p1 = get(node << 1, l, m, x, y);
        int p2 = get(node << 1 | 1, m + 1, r, x, y);
        return p1 | p2 | has[node];
    }
} t;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vals.push_back(0);
    for (int i = 1; i <= n; i++) {
        cin >> a[0][i].first >> a[0][i].second >> a[1][i].first >> a[1][i].second;
        vals.push_back(a[0][i].first);
        vals.push_back(a[0][i].second);
        vals.push_back(a[1][i].first);
        vals.push_back(a[1][i].second);
    }
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    for (int i = 1; i <= n; i++) {
        a[0][i].first = lower_bound(vals.begin(), vals.end(), a[0][i].first) - vals.begin();
        a[0][i].second = lower_bound(vals.begin(), vals.end(), a[0][i].second) - vals.begin();
        a[1][i].first = lower_bound(vals.begin(), vals.end(), a[1][i].first) - vals.begin();
        a[1][i].second = lower_bound(vals.begin(), vals.end(), a[1][i].second) - vals.begin();
    }
    for (int id = 0; id < 2; id++) {
        t.init();   
        for (int i = 0; i < vals.size(); i++) {
            addEvent[i].clear();
            qEvent[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            addEvent[a[id][i].second].push_back(i);
            qEvent[a[id][i].first].push_back(i);
        }
        for (int i = 1; i < vals.size(); i++) {
            for (int u : qEvent[i]) {
                if (t.get(1, 1, vals.size() - 1, a[id ^ 1][u].first, a[id ^ 1][u].second)) {
                    // cout << id << ' ' << i << ' ' << vals[i] << ' ' << u << endl;
                    cout << "NO\n";
                    return 0;
                }
            }
            for (int u : addEvent[i]) {
                // cout << "added " << id << ' ' << u << endl;
                t.add(1, 1, vals.size() - 1, a[id ^ 1][u].first, a[id ^ 1][u].second);
            }
        }
    }
    cout << "YES\n";
    return 0;
}