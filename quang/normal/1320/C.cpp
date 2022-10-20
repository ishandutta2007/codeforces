#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const long long INF = (1ll << 60);

int n, m, p;
vector<pair<int, int>> a, b;
vector<tuple<int, int, int>> c;
long long res = -INF;

void normalize(vector<pair<int, int>> &u) {
    vector<pair<int, int>> res;
    sort(u.begin(), u.end(), [&](pair<int, int> &u, pair<int, int> &v) {
        if (u.first != v.first) return u.first < v.first;
        return u.second > v.second;
    });
    for (auto val : u) {
        while (!res.empty() && res.back().second >= val.second) res.pop_back();
        res.push_back(val);
    }
    u.swap(res);
}

const int M = (int)1e6 + 10;

struct BIT {
    long long t[M];
    void add(int x, int v) {
        while (x < M) {
            t[x] += v;
            x += x & -x;
        }
    }
    long long get(int x) {
        long long res = 0;
        while (x) {
            res += t[x];
            x -= x & -x;
        }
        return res;
    }
} t;

int getOpt(int id, int optL, int optR) {
    long long ans = -INF;
    int opt = -1;
    for (int i = optL; i <= optR; i++) {
        long long cost = -(a[id].second + b[i].second);
        cost += t.get(b[i].first - 1);
        if (ans < cost) {
            ans = cost;
            opt = i;
        }
    }
    res = max(res, ans);
    return opt;
}

void go(int l, int r, int optL, int optR, vector<tuple<int, int, int>> &c) {
    if (l > r) return;
    int m = l + r >> 1;
    vector<tuple<int, int, int>> smaller, bigger;
    for (auto val : c) {
        if (get<0>(val) >= a[m].first) {
            bigger.push_back(val);
            t.add(get<1>(val), -get<2>(val));
        } else smaller.push_back(val);
    }
    int opt = getOpt(m, optL, optR);
    go(l, m - 1, optL, opt, smaller);
    for (auto val : bigger) {
        t.add(get<1>(val), get<2>(val));
    } 
    go(m + 1, r, opt, optR, bigger);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        a.push_back({u, v});
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        b.push_back({u, v});
    }
    normalize(a);
    normalize(b);
    for (int i = 1; i <= p; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u >= a.back().first) continue;
        c.push_back({u, v, w});
    }
    // sort(c.begin(), c.end(), [&](tuple<int, int, int> &u, tuple<int, int, int> &v) {
    //     return get<1>(u) < get<1>(v);
    // });
    for (auto val : c) {
        t.add(get<1>(val), get<2>(val));
    }
    go(0, a.size() - 1, 0, b.size() - 1, c);
    cout << res << endl;
    return 0;   
}