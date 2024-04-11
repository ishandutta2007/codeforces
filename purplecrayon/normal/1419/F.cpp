#include<bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<int, int>

const int INF = 2e9 + 1;

vector<vector<int>> g;
vector<int> usd;

void dfs(int v, int col) {
    usd[v] = col;
    for (auto &to : g[v]) {
        if (!usd[to]) dfs(to, col);
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    map<int, vector<pii>> same_x, same_y;
    for (int i = 0; i < n; i++) {
        same_x[x[i]].pb(y[i], i);
        same_y[y[i]].pb(x[i], i);
    }
    for (auto &c : same_x) sort(all(c.se));
    for (auto &c : same_y) sort(all(c.se));
    ll left = -1, right = INF;
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        g.clear();
        g.resize(n);
        for (auto &c : same_x) {
            for (int i = 1; i < (int)c.se.size(); i++) {
                if (c.se[i].fi - c.se[i - 1].fi <= mid) {
                    g[c.se[i].se].pb(c.se[i - 1].se);
                    g[c.se[i - 1].se].pb(c.se[i].se);
                }
            }
        }
        for (auto &c : same_y) {
            for (int i = 1; i < (int)c.se.size(); i++) {
                if (c.se[i].fi - c.se[i - 1].fi <= mid) {
                    g[c.se[i].se].pb(c.se[i - 1].se);
                    g[c.se[i - 1].se].pb(c.se[i].se);
                }
            }
        }
        int cur = 1;
        usd.assign(n, 0);
        for (int i = 0; i < n; i++) {
            if (usd[i]) continue;
            dfs(i, cur);
            cur++;
        }
        cur--;
        if (cur > 4) {
            left = mid;
            continue;
        }
        bool ok = false;
        if (cur == 1) {
            ok = true;
        } else if (cur == 2) {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (usd[i] == usd[j]) continue;
                    if (x[i] == x[j] && abs(y[i] - y[j]) <= 2 * mid) ok = true;
                    if (y[i] == y[j] && abs(x[i] - x[j]) <= 2 * mid) ok = true;
                    if (abs(x[i] - x[j]) <= mid && abs(y[i] - y[j]) <= mid) ok = true;
                }
            }
        } else if (cur == 3) {
            vector<pii> seg;
            for (auto &c : same_x) {
                for (int i = 1; i < (int)c.se.size(); i++) {
                    if (usd[c.se[i].se] != usd[c.se[i - 1].se]) {
                        seg.pb(c.se[i].se, c.se[i - 1].se);
                    }
                }
            }
            for (auto &c : same_y) {
                for (int i = 1; i < (int)c.se.size(); i++) {
                    if (usd[c.se[i].se] != usd[c.se[i - 1].se]) {
                        seg.pb(c.se[i].se, c.se[i - 1].se);
                    }
                }
            }
            for (auto &c : seg) {
                int i = c.fi, j = c.se;
                for (int k = 0; k < n; k++) {
                    if (usd[k] == usd[i] || usd[k] == usd[j]) continue;
                    if (x[i] == x[j]) {
                        if (min(y[i], y[j]) >= y[k] || max(y[i], y[j]) <= y[k]) continue;
                        if (abs(x[i] - x[k]) > mid) continue;
                        if (abs(y[i] - y[k]) <= mid && abs(y[j] - y[k]) <= mid) ok = true;
                    } else {
                        if (min(x[i], x[j]) >= x[k] || max(x[i], x[j]) <= x[k]) continue;
                        if (abs(y[i] - y[k]) > mid) continue;
                        if (abs(x[i] - x[k]) <= mid && abs(x[j] - x[k]) <= mid) ok = true;
                    }
                }
            }
        } else {
            vector<pii> segx, segy;
            for (auto &c : same_x) {
                for (int i = 1; i < (int)c.se.size(); i++) {
                    if (usd[c.se[i].se] != usd[c.se[i - 1].se]) {
                        segx.pb(c.se[i].se, c.se[i - 1].se);
                    }
                }
            }
            for (auto &c : same_y) {
                for (int i = 1; i < (int)c.se.size(); i++) {
                    if (usd[c.se[i].se] != usd[c.se[i - 1].se]) {
                        segy.pb(c.se[i].se, c.se[i - 1].se);
                    }
                }
            }
            for (auto &c : segx) {
                for (auto &l : segy) {
                    int i = c.fi, j = c.se, k = l.fi, p = l.se;
                    if (usd[i] == usd[k] || usd[i] == usd[p] || usd[j] == usd[p] || usd[j] == usd[k]) continue;
                    if (min(y[i], y[j]) >= y[k]) continue;
                    if (max(y[i], y[j]) <= y[k]) continue;
                    if (min(x[k], x[p]) >= x[i]) continue;
                    if (max(x[k], x[p]) <= x[i]) continue;
                    int x0 = x[i], y0 = y[k];
                    if (abs(y[i] - y0) <= mid && abs(y[j] - y0) <= mid && abs(x[p] - x0) <= mid && abs(x[k] - x0) <= mid) ok = true;
                }
            }
        }
        if (ok) right = mid;
        else left = mid;
    }
    cout << (right == INF ? -1 : right);
    return 0;
}