#include <bits/stdc++.h>

using namespace std;

const int N = 510;
const int M = 1000010;
const int MOD = 998244353;

inline int add(int u, int v) {
    return (u += v) >= MOD ? u - MOD : u;
}

inline int sub(int u, int v) {
    return (u -= v) < 0 ? u + MOD : u;
}

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

inline int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) res = mul(res, u);
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}

inline int inv(int u) {
    return power(u, MOD - 2);
}

int n, m;
int c[M];
int l[N], r[N];
int order[N];
vector<int> child[N];
vector<int> pos[N];
int f[N];
int dp[N][N], sum[N][N];

int get(vector<int> &ls) {
    int sz = ls.size() - 1;
    for (int i = 0; i <= sz + 1 ; i++) {
        for (int j = 0; j <= sz + 1; j++) {
            if (i > j) dp[i][j] = sum[i][j] = 1;
            else dp[i][j] = sum[i][j] = 0;
        }
    }
    for (int len = 1; len <= sz; len++) {
        for (int l = 1; l + len - 1 <= sz; l++) {
            int r = l + len - 1;
            int minId = l;
            for (int i = l + 1; i <= r; i++) {
                if (ls[i] < ls[minId]) minId = i;
            }

            dp[l][r] = mul(sum[l][minId - 1], sum[minId + 1][r]);
            for (int i = l; i <= r + 1; i++) {
                sum[l][r] = add(sum[l][r], mul(dp[l][i - 1], dp[i][r]));
            }
        }
    }
    return dp[1][sz];
}

void dfs(int u) {
    f[u] = 1;
    int cur = 0;
    for (int i = 0; i + 1 < pos[u].size(); i++) {
        int ll = pos[u][i];
        int rr = pos[u][i + 1];
        vector<int> ls = {0};
        while (cur < child[u].size() && r[child[u][cur]] < rr) {
            if (l[child[u][cur]] <= ll) {
                cout << 0 << endl;
                exit(0);
            }
            ls.push_back(child[u][cur]);
            cur++;
        }
        if (ls.size() > 1) {
            int foo = get(ls);
            f[u] = mul(f[u], foo);
        }
    }

    for (int v : child[u]) {
        dfs(v);
        f[u] = mul(f[u], f[v]);
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        l[i] = m + 1;
        r[i] = 0;
        order[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> c[i];
        pos[c[i]].push_back(i);
        l[c[i]] = min(l[c[i]], i);
        r[c[i]] = max(r[c[i]], i);
    }
    sort(order + 1, order + n + 1, [&](int u, int v) {
        return l[u] < l[v];
    });
    l[0] = 0;
    r[0] = m + 1;
    pos[0].push_back(0);
    pos[0].push_back(m + 1);
    vector<int> st = {0};
    for (int i = 1; i <= n; i++) {
        int u = order[i];
        while (!st.empty() && r[st.back()] < l[u]) st.pop_back();
        assert(!st.empty());
        if (r[u] > r[st.back()]) {
            cout << 0 << endl;
            exit(0);
        }
        if (u < st.back()) {
            cout << 0 << endl;
            exit(0);
        }
        child[st.back()].push_back(u);
        st.push_back(u);
    }
    dfs(0);
    cout << f[0] << endl;
    return 0;
}