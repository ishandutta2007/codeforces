#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxm = 45;

int n, m, tot, ans, dp[1 << 20];
vector<pair<bool, string>> vec;
set<string> lis;
map<string, int> mmap;
vector<int> G[maxm];
set<int> tmp;
bool vis[1 << 20];

int dfs(int mask, int upp) {
    if (!mask) return 0;
    if (vis[mask]) return dp[mask];
    vis[mask] = true;
    REP(i, upp) if (mask & (1 << i)) dp[mask] = max(dp[mask], dfs(mask ^ (1 << i), upp));
    return dp[mask];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    if (m == 1) {
        cout << 1;
        return 0;
    }
    REP(i, n) {
        int op;
        string s;
        cin >> op;
        if (op == 1) vec.eb(true, "");
        else {
            cin >> s;
            lis.insert(s);
            vec.eb(false, s);
        }
    }
    for (const auto &s : lis) mmap[s] = tot++;
    for (const auto &now : vec) {
        if (now._1) {
            for (const auto &s1 : tmp) for (const auto &s2 : tmp) if (s1 != s2) {
                        G[s1].eb(s2);
                        G[s2].eb(s1);
                    }
            tmp.clear();
        } else tmp.insert(mmap[now._2]);
    }
    for (const auto &s1 : tmp) for (const auto &s2 : tmp) if (s1 != s2) {
                G[s1].eb(s2);
                G[s2].eb(s1);
            }
    REP(i, m) {
        sort(all(G[i]));
        uni(G[i]);
    }
    int upp = m >> 1;
    REP(mask, 1 << upp) {
        bool ok = true;
        int cnt = 0;
        REP(i, upp) {
            if (!ok) break;
            if (mask & (1 << i)) {
                for (auto v : G[i]) {
                    if (!ok) break;
                    if (v >= upp) continue;
                    if (mask & (1 << v)) ok = false;
                }
                cnt++;
            }
        }
        if (ok) dp[mask] = cnt;
    }
    dfs((1 << upp) - 1, upp);
    int rem = m - upp;
    REP(mask, 1 << rem) {
        bool ok = true;
        int cnt = 0, ALL = (1 << upp) - 1;
        REP(i, rem) {
            if (!ok) break;
            if (mask & (1 << i)) {
                for (auto v : G[i + upp]) {
                    if (!ok) break;
                    if (v < upp) {
                        if (ALL & (1 << v)) ALL ^= 1 << v;
                        continue;
                    }
                    if (mask & (1 << v - upp)) ok = false;
                }
                cnt++;
            }
        }
        if (ok) ans = max(ans, cnt + dp[ALL]);
    }
    cout << ans;
}