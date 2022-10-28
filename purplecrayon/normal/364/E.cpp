#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2.5e3+10, MOD = 1e9+7;
const int K = 7;

const int M = N * K;
struct LinkedList {
    int prv[M], nxt[M];
    int val[M];

    void clear() {
        memset(prv, -1, sizeof(prv));
        memset(nxt, -1, sizeof(nxt));
    }
    void add(pair<int, int> cv, int p) {
        auto [v, c] = cv;
        val[c] = v;
        prv[c] = p;
        if (p != -1) nxt[c] = nxt[p];
        if (prv[c] != -1) nxt[prv[c]] = c;
        if (nxt[c] != -1) prv[nxt[c]] = c;
    }
    pair<int, int> prev(pair<int, int> c) {
        int p = prv[c.second];
        return {val[p], p};
    }
    pair<int, int> next(pair<int, int> c) {
        int p = nxt[c.second];
        return {val[p], p};
    }
} ls;

int n, m, k;
string g[N];
int nxt[N][N];
vector<int> use[N];
int me[N];
int cnt[N];


int up[N], prv_one[N], nxt_one[N];
void zero() {
    memset(up, -1, sizeof(up));
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (g[i][j] == '1')
            up[j] = i;

        {
            vector<int> stk;
            for (int j = 0; j < m; j++) {
                while (sz(stk) && up[stk.back()] <= up[j]) stk.pop_back();
                if (sz(stk)) prv_one[j] = stk.back();
                else prv_one[j] = -1;
                stk.push_back(j);
            }
        }
        {
            vector<int> stk;
            for (int j = m-1; j >= 0; j--) {
                while (sz(stk) && up[stk.back()] < up[j]) stk.pop_back();
                if (sz(stk)) nxt_one[j] = stk.back();
                else nxt_one[j] = m;
                stk.push_back(j);
            }
        }
        for (int j = 0; j < m; j++) {
            ans += (long long) (i - up[j]) * (j - prv_one[j]) * (nxt_one[j] - j);
        }
    }
    cout << ans << '\n';
}
void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> g[i];

    if (k == 0) {
        zero();
        return;
    }

    memset(nxt, -1, sizeof(nxt));
    for (int i = 0; i < n; i++) {
        for (int j = m-1; j >= 0; j--) {
            nxt[i][j] = nxt[i][j+1];
            if (g[i][j] == '1') nxt[i][j] = j;
        }
    }
    ll ans = 0;
    for (int l = 0; l < m; l++) {
        for (int r = 0; r < m; r++) use[r].clear();

        for (int i = 0; i < n; i++) {
            int c = l;
            for (int rep = 0; rep <= k; rep++) {
                c = nxt[i][c];
                if (c == -1) break;
                use[c].push_back(i);

                c++;
            }
        }
        memset(me, 0, sizeof(me));


        ls.clear();

        memset(cnt, -1, sizeof(cnt));

        int tt = 0;
        set<pair<int, int>> s;
        auto ins = [&](pair<int, int> p) {
            if (cnt[p.first + 1] == -1) {
                auto [it, _] = s.insert(p);
                if (it != s.begin()) ls.add(p, cnt[prev(it)->first + 1]);
                else ls.add(p, -1);
             } else {
                ls.add(p, cnt[p.first + 1]);
            }
            cnt[p.first + 1] = p.second;
        };

        for (int rep = 0; rep <= k; rep++) ins({-1, tt++});
        ins({n, tt++});
        
        ll cur = 0;
        auto add = [&](int x) {
            pair<int, int> it = {x, tt++};
            ins(it);
            if (ls.prev(it).first != -1) it = ls.prev(it);
            auto p = it;
            for (int rep_p = 0; rep_p < k - 1; rep_p++) {
                p = ls.prev(p);
            }
            for (int rep = 0; rep <= k + 1 && it.first < n; rep++, it = ls.next(it), p = ls.next(p)) { // k * log
                if (ls.next(it).first == it.first) continue;

                cur -= me[it.first];

                bool bad = 0;
                if (!bad) {
                    me[it.first] = (p.first - ls.prev(p).first) * (ls.next(it).first - it.first);
                } else {
                    me[it.first] = 0;
                }
                cur += me[it.first];
            }
        };
        for (int r = l; r < m; r++) {
            for (int i : use[r]) { // n * k
                add(i);
            }
            ans += cur;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}