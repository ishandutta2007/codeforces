#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, k;
int a[N];
set<pair<int, int> > s;
int r[N], l[N];
int res[N];

int getL(int u) {
    if (u == 0) return u;
    return res[u] != -1 ? l[u] = getL(l[u]) : u;
}

int getR(int u) {
    if (u == n + 1) return u;
    return res[u] != -1 ? r[u] = getR(r[u]) : u;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s.insert({a[i], i});
        l[i] = i - 1;
        r[i] = i + 1;
    }
    memset(res, -1, sizeof res);
    int cur = 0;
    while (!s.empty()) {
        int id = s.rbegin()->second;
        // cout << " start " << endl;
        // cout << id << endl;
        res[id] = cur;
        s.erase(s.find({a[id], id}));
        int now = id;
        for (int i = 1; i <= k; i++) {
            now = getR(now);
            if (now == n + 1) break;
            res[now] = cur;
            s.erase(s.find({a[now], now}));
            // cout << now << endl;
        }
        now = id;
        for (int i = 1; i <= k; i++) {
            now = getL(now);
            if (now == 0) break;
            res[now] = cur;
            s.erase(s.find({a[now], now}));
            // cout << now << endl;
        }

        cur ^= 1;
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] + 1;
    }
    cout << endl;
    return 0;
}