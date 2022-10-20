#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

int n;
vector<int> adj[N];
vector<int> maxLenChild[N];
int maxLenPar[N], maxLen[N];
int maxRes[N], maxResEven[N];

struct BIT {
    int t[N];
    vector<int> ls;
    bool used[N];
    void reset() {
        for (auto u : ls) {
            used[u] = 0;
            t[u] = 0;
        }
        ls.clear();
    }
    void add(int x, int v) {
        x++;
        while (x < N) {
            if (!used[x]) {
                used[x] = 1;
                ls.push_back(x);
            }
            t[x] += v;
            x += x & -x;
        }
    }
    int get(int x) {
        x++;
        int res = 0;
        while (x) {
            res += t[x];
            x -= x & -x;
        }
        return res;
    }
    int get(int l, int r) {
        return get(r) - (l ? get(l - 1) : 0);
    }
} t;

void dfsInit(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dfsInit(v, u);
        maxLenChild[u].push_back(maxLen[v] + 1);
    }
    sort(maxLenChild[u].begin(), maxLenChild[u].end());
    if (!maxLenChild[u].empty()) maxLen[u] = *maxLenChild[u].rbegin();
    else maxLen[u] = 0;
}

int num[N];

void dfsDown(int u, int p, int top) {
    maxLenPar[u] = top;
    
    int secondMaxLen = 0;
    if (maxLenChild[u].size() > 1) secondMaxLen = maxLenChild[u][maxLenChild[u].size() - 2];
    

    for (int v : adj[u]) {
        if (v == p) continue;
        int here = (maxLen[u] == maxLen[v] + 1) ? secondMaxLen + 1 : maxLen[u] + 1;
        dfsDown(v, u, max(maxLenPar[u] + 1, here));
    }

    t.reset();
    t.add(maxLenPar[u], 1);
    for (int v : adj[u]) {
        if (v == p) continue;
        t.add(maxLen[v] + 1, 1);
    }

    // for even only event from v;
    for (int v : adj[u]) {
        if (v == p) continue;
        t.add(maxLen[v] + 1, -1);
        for (int i = 0; i < maxLenChild[v].size(); i++) {
            int num = maxLenChild[v].size() - i;
            int tot = t.get(maxLenChild[v][i], N - 2);
            if (tot == 0) continue;
            maxResEven[maxLenChild[v][i] * 2] = max(maxResEven[maxLenChild[v][i] * 2], num + tot);
        }
        t.add(maxLen[v] + 1, 1);
    }
//    for even: event from u;
    int maxNum = 0;
    vector<pair<int, int>> ls;
    for (int v : adj[u]) {
        if (v == p) continue;
        num[v] = 0;
        for (int dist : maxLenChild[v]) {
            ls.push_back({dist, v});
        }
    }
    int curId = (int)ls.size() - 1;
    sort(ls.begin(), ls.end());
    for (int l = (int)maxLenChild[u].size() - 1, r; l >= 0; l = r) {
        r = l;
        while (curId >= 0 && ls[curId].first >= maxLenChild[u][l]) {
            num[ls[curId].second]++;
            maxNum = max(maxNum, num[ls[curId].second]);
            curId--;
        }
        while (r >= 0 && maxLenChild[u][l] == maxLenChild[u][r]) r--;
        int now = maxLenChild[u].size() - r - 1 + (maxLenPar[u] >= maxLenChild[u][l]);
        maxResEven[maxLenChild[u][l] * 2] = max(maxResEven[maxLenChild[u][l] * 2], now + maxNum - 1);
    }

    // even from par u
    int numChild = 1;
    int maxChild = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        numChild += ((maxLen[v] + 1) >= maxLenPar[u]);
        int id = lower_bound(maxLenChild[v].begin(), maxLenChild[v].end(), maxLenPar[u]) - maxLenChild[v].begin();
        maxChild = max(maxChild, (int)maxLenChild[v].size() - id);
    }
    maxResEven[maxLenPar[u] * 2] = max(maxResEven[maxLenPar[u] * 2], numChild + maxChild - 1);

    // for all
    vector<int> cur = maxLenChild[u];
    cur.push_back(maxLenPar[u]);
    sort(cur.begin(), cur.end());
    for (int i = 0; i < cur.size(); i++) {
        int num = cur.size() - i;
        maxRes[cur[i] * 2] = max(maxRes[cur[i] * 2], num);
        if (i + 1 < cur.size() && cur[i] != cur[i + 1]) {
            maxRes[cur[i] * 2 + 1] = max(maxRes[cur[i] * 2 + 1], num);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfsInit(1, 0);
    dfsDown(1, 0, 0);
    for (int i = n - 1; i >= 1; i--) {
        maxRes[i] = max(maxRes[i], maxRes[i + 1]);
        if (i % 2 == 0) maxResEven[i] = max(maxResEven[i], maxResEven[i + 2]);
    }
    for (int i = 1; i <= n; i++) {
        maxRes[1] = max(maxRes[1], (int)adj[i].size() + 1);
    }
    for (int i = 1; i <= n; i++) cout << max(1, max(maxRes[i], maxResEven[i])) << ' ';
        cout << endl;
    return 0;
}