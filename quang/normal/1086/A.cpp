#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int x[3], y[3];
set<pair<int, int> > ans;
int res = N * N;

void go(set<pair<int, int> > &s, int u, int v, int dir) {
    s.insert({x[u], y[u]});
    s.insert({x[v], y[v]});
    if (dir == 0) {
        for (int i = x[u]; i != x[v]; i += (x[u] < x[v] ? 1 : -1)) {
            s.insert({i, y[u]});
        }
        for (int i = y[u]; i != y[v]; i += (y[u] < y[v] ? 1 : -1)) {
            s.insert({x[v], i});
        }
    } else {
        for (int i = y[u]; i != y[v]; i += (y[u] < y[v] ? 1 : -1)) {
            s.insert({x[u], i});
        }
        for (int i = x[u]; i != x[v]; i += (x[u] < x[v] ? 1 : -1)) {
            s.insert({i, y[v]});
        }
    }
}

int get(vector<int> id) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            set<pair<int, int> > s;
            go(s, id[0], id[1], i);
            go(s, id[1], id[2], j);
            if (res > s.size()) {
                res = s.size();
                ans.swap(s);
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> x[0] >> y[0];
    cin >> x[1] >> y[1];
    cin >> x[2] >> y[2];
    vector<int> a = {0, 1, 2};
    while (1) {
        get(a);
        if (!next_permutation(a.begin(), a.end())) break;
    }
    cout << res << endl;
    for (auto u : ans) {
        cout << u.first << ' ' << u.second << '\n';
    }
    return 0;
}