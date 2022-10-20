#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int l, r;
    cin >> l >> r;

    if (l == r) {
        cout << "YES\n";
        cout << 2 << ' ' << 1 << endl;
        cout << 1 << ' ' << 2 << ' ' << l << endl;
        return 0;
    }

    int n = r - l;
    vector<vector<pair<int, int>>> adj;
    adj.push_back(vector<pair<int, int>>());
    adj.push_back(adj.back());
    adj.back().push_back({0, 1});


    const int LOG = 20;

    // i -> 2 ^ i-1
    for (int i = 1; i <= LOG; i++) {
        adj.push_back(adj.back());
        adj.back().push_back({i, 1 << i - 1});
    }

    vector<pair<int, int>> last;
    int cur = 1;
    for (int i = LOG; i >= 0; i--) {
        if (n >> i & 1) {
            last.push_back({i + 1, cur});
            cur += (1 << i);
        }
    }

    last.push_back({0, 1});

    adj.push_back(last);
    if (l > 1) {
        adj.push_back(vector<pair<int, int>>());
        adj.back().push_back({adj.size() - 2, l - 1});
    }
    int sz = adj.size();
    int m = 0;
    for (auto u : adj) {
        m += u.size();
    }
    cout << "YES\n";
    cout << sz << ' ' << m << '\n';
    for (int i = adj.size() - 1; i >= 0; i--) {
        for (auto u : adj[i]) {
            cout << sz - i << ' ' << sz - u.first << ' ' << u.second << '\n';
        }   
    }
    return 0;
}