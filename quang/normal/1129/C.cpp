#include <bits/stdc++.h>

using namespace std;

const int N = 3010;
const int MOD = 1000000007;

inline int add(int u, int v) {
    u += v;
    if (u >= MOD) {
        u -= MOD;
    }
    return u;
}

inline int sub(int u, int v) {
    u -= v;
    if (u < 0) {
        u += MOD;
    }
    return u;
}

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

inline int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) {
            res = mul(res, u);
        }
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}

inline int inv(int u) {
    return power(u, MOD - 2);
}

int n;
char a[N];
int dp[N][N];
set<string> s;
int f[N];

struct SuffixAutomaton {
    static const int M = 10000;
    static const int CHARACTER = 2;
    int suf[M * 2], nxt[M * 2][CHARACTER], cnt, last, len[M * 2], pos[M * 2];
    vector<int> adj[M * 2];

    SuffixAutomaton() {
        memset(suf, -1, sizeof suf);
        memset(nxt, -1, sizeof nxt);
        memset(len, 0, sizeof len);
        memset(pos, 0, sizeof pos);
        last = cnt = 0;
    }

    int getNode(int last, int u, int p) {
        int q = nxt[last][u];
        if (len[last] + 1 == len[q]) {
            return q;
        }
        int clone = ++cnt;
        len[clone] = len[last] + 1;
        pos[clone] = p;
        for (int i = 0; i < CHARACTER; i++) {
            nxt[clone][i] = nxt[q][i];
        }
        while (last != -1 && nxt[last][u] == q) {
            nxt[last][u] = clone;
            last = suf[last];
        }
        suf[clone] = suf[q];
        return suf[q] = clone;
    }

    void add(int u, int p) {
        if (nxt[last][u] == -1) {
            int newNode = ++cnt;
            len[newNode] = len[last] + 1;
            pos[newNode] = p;
            while (last != -1 && nxt[last][u] == -1) {
                nxt[last][u] = newNode;
                last = suf[last];
            }
            if (last == -1) {
                suf[newNode] = 0;
                last = newNode;
                return;
            }
            suf[newNode] = getNode(last, u, p);
            last = newNode;
        } else {
            last = getNode(last, u, p);
        }
    }

    void dfs(int u) {
        for (int v : adj[u]) {
            dfs(v);
            pos[u] = min(pos[u], pos[v]);
        }
        int l = len[u];
        int r = len[suf[u]];
        int res = 0;
        for (int j = r + 1; j <= l; j++) {
            int ll = pos[u] - j + 1;
            int rr = pos[u];
            res = ::add(res, dp[ll][rr]);
        }
        f[pos[u]] = ::add(f[pos[u]], res);
    }

    void solve() {
        // for (int i = 1; i <= cnt; i++) cout << i << ' ' << pos[i] << ' ' << len[i] << ' ' << suf[i] << endl;
        for (int i = 1; i <= cnt; i++) adj[suf[i]].push_back(i);
        dfs(0);   
    }
} ac;



bool valid(int k, int j) {
    string u = "";
    for (int i = k + 1; i <= j; i++) {
        u += a[i];
    }
    return s.count(u) == 0;
}

int getDp(int i, int j, int k) {
    if (!valid(k, j)) return 0;
    return i <= k ? dp[i][k] : 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    s.insert("0011");
    s.insert("0101");
    s.insert("1110");
    s.insert("1111");
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char u;
        cin >> u;
        ac.add(u - '0', i);
        a[i] = u;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = max(i - 1, j - 4); k < j; k++) {
                dp[i][j] = add(dp[i][j], getDp(i, j, k));
            }
            // cout << i << ' ' << j << ' ' << dp[i][j] << endl;
        }
    }
    ac.solve();
    for (int i = 1; i <= n; i++) {
        f[i] = add(f[i], f[i - 1]);
        cout << f[i] << '\n';
    }
    return 0;
}