#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define f0r(a, b) for (int i = (a); i < (b); ++i)
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

void my_assert(bool value) {
    if (!value) exit(0);
}


void solve() {
    int n, m;
    cin >> n >> m;
    vpi start(m), finish(m);
    rep(i, m) cin >> start[i].first >> start[i].second;
    rep(i, m) cin >> finish[i].first >> finish[i].second;
    rep(i, m) start[i].first--;
    rep(i, m) start[i].second--;
    rep(i, m) finish[i].first--;
    rep(i, m) finish[i].second--;
    {
        bool ok = true;
        rep(i, m) ok &= (start[i] == finish[i]);
        if (ok) {
            cout << "0\n";
            return;
        }
    }
    my_assert(n >= 2);
    vec<ar<int, 4>> ans;
    vvi a(n, vi(n, -1));
    rep(i, m) a[start[i].first][start[i].second] = i;
    vvi ban(n, vi(n, 0));
    int T = 0;
    vi dx = {0, 0, 1, -1};
    vi dy = {1, -1, 0, 0};
    auto bfs = [&](int sx, int sy) {
        queue<pair<int, int>> q;
        q.push({sx, sy});
        vvi pred(n, vi(n, -1));
        pred[sx][sy] = -2;
        int fx = -1, fy = -1;
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (ban[x][y]) continue;
            if (a[x][y] != -1) {
                fx = x;
                fy = y;
                break;
            }
            rep(w, 4) {
                int x2 = x + dx[w];
                int y2 = y + dy[w];
                if (x2 < 0 || y2 < 0 || x2 >= n || y2 >= n) continue;
                if (pred[x2][y2] != -1) continue;
                pred[x2][y2] = w;
                q.push({x2, y2});
            }
        }
        assert(fx != -1 && fy != -1);
        int c = a[fx][fy];
        a[fx][fy] = -1;
        while(fx != sx || fy != sy) {
            int t = pred[fx][fy];
            ans.push_back({fx, fy, -1, -1});
            fx -= dx[t];
            fy -= dy[t];
            ans.back()[2] = fx;
            ans.back()[3] = fy;
        }
        a[fx][fy] = c;
    };
    rep(i, m) {
        T++;
        bfs(0, i);
        ban[0][i] = 1;
    }
    auto op = [&] (int x1, int y1, int x2, int y2) {
        my_assert(a[x2][y2] == -1);
        my_assert(a[x1][y1] != -1);
        ans.push_back({x1, y1, x2, y2});
        swap(a[x1][y1], a[x2][y2]);
    };
    vi ord(m);
    iota(all(ord), 0);
    sort(all(ord), [&] (const int &x, const int &y) {
        return finish[x].second < finish[y].second;
    });
    vi pos(m);
    rep(i, m) pos[a[0][i]] = i;
    rep(e, m) {
        int val = ord[e];
        int to = e;
        int cur = pos[val];
        if (cur == to) continue;
        my_assert(cur >= to);
        op(0, cur, 1, cur);
        for(int t = cur - 1; t >= to; --t) {
            pos[a[0][t]]++;
            op(0, t, 0, t + 1);
            op(1, t + 1, 1, t);
        }
        op(1, to, 0, to);
        pos[val] = to;
    }
    rep(i, m) {
        int c = a[0][i];
        int x = 0;
        while(finish[c].first > x) {
            op(x, i, x + 1, i);
            x++;
        }
    }
    rep(i, n) {
        int emp = 0;
        rep(j, n) {
            if (a[i][j] != -1) {
                int t = j;
                while(t > emp) {
                    op(i, t, i, t - 1);
                    t--;
                }
                emp++;
            }
        }
        for(int j = emp - 1; j >= 0; --j) {
            int c = a[i][j];
            int t = j;
            while(t < finish[c].second) {
                op(i, t, i, t + 1);
                t++;
            }
        }
    }
    cout << ans.size() << '\n';
    assert(ans.size() <= 10800);
    for(auto &[x1, y1, x2, y2] : ans) {
        cout << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}