#include <bits/stdc++.h>

using namespace std;
#define int long long

const int K = 15;
const int INF = 2e9;

int k;
map<int, int> type;
vector<int> a[K];
vector<int> vals;
pair<int, int> can[1 << K];
map<int, int> pre;
map<int, int> used;
set<int> dead;

long long sum;
long long tot[K];
long long delta[K];
int dp[1 << K];
pair<int, int> res[K];

void go(int root) {
    vector<int> ls;
    ls.push_back(root);
    used[root] = 0;
    while (1) {
        int u = ls.back();
        if (!pre.count(u)) break;
        int v = pre[u];
        if (dead.count(v)) break;
        if (!used.count(v)) {
            used[v] = ls.size();
            ls.push_back(v);
            continue;
        }
        int mask = 0;
        int f = 0;
        for (int i = used[v]; i < ls.size(); i++) {
            int id = type[ls[i]];
            if (mask >> id & 1) f = 1;
            mask |= (1 << id);
        }
        if (!f) can[mask] = {type[v], v};
        break;
    }
    for (int u : ls) dead.insert(u);
}

void trace(int mask) {
    assert(can[mask].first != -1);  
    int sz = __builtin_popcount(mask);
    int u = can[mask].second; 
    for (int i = 0; i < sz; i++) {
        int v = pre[u];
        int id = type[v];
        res[id] = {v, type[u]};
        u = v;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    for (int i = 0; i < k; i++) {
        int sz;
        cin >> sz;
        a[i].resize(sz);
        tot[i] = 0;
        for (int &u : a[i]) {
            cin >> u;
            type[u] = i;
            tot[i] += u;
            vals.push_back(u);
        }
        sum += tot[i];
    }
    long long need = sum / k;
    for (int i = 0; i < k; i++) {
        delta[i] = need - tot[i];
    }
    memset(can, -1, sizeof can);
    for (int val : vals) {
        int id = type[val];
        long long now = delta[id] + val;
        if (type.count(now)) {
            pre[val] = now;
        }
    }
    for (int val : vals) {
        if (dead.count(val)) continue;
        go(val);
    }
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    for (int mask = 1; mask < (1 << k); mask++) {
        for (int subMask = mask; subMask > 0; subMask = (subMask - 1) & mask) {
            int preMask = mask ^ subMask;
            if (can[subMask].first != -1 && dp[preMask] != -1) {
                dp[mask] = preMask;
            }
        }
    }
    int curMask = (1 << k) - 1;
    if (dp[curMask] == -1) {
        cout << "No" << endl;
        return 0;
    }
    while (curMask > 0) {
        int mask = dp[curMask];
        trace(mask ^ curMask);

        curMask = mask;
    }
    cout << "Yes\n";
    for (int i = 0; i < k; i++) {
        cout << res[i].first << ' ' << res[i].second + 1 << '\n';
    }
    return 0;
}