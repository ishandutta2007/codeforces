#include <bits/stdc++.h>

using namespace std;

const int N = 4010;
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

char s[N];
int n;
vector<pair<int, int> > adj[N];
int used[N];

int go(int root, int l) {
    vector<int> id[2];
    queue<int> q;
    q.push(root);
    used[root] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        id[used[u]].push_back(u);
        for (auto v : adj[u]) {
            if (used[v.first] == -1) {
                used[v.first] = used[u] ^ v.second;
                q.push(v.first);
            } else {
                if (used[v.first] != used[u] ^ v.second) return 0;
            }
        }
    }
    int color = -1;
    for (int u : id[0]) {
        int now = -1;
        if (u > n + l) {
            now = 0;
        } else if (u == n + l) {
            now = 1;
        }
        if (now == -1) continue;
        if (color == -1) color = now;
        else if (color != now) return 0;
    }
    for (int u : id[1]) {
        int now = -1;
        if (u > n + l) {
            now = 0;
        } else if (u == n + l) {
            now = 1;
        }
        if (now == -1) continue;
        if (color == -1) color = now ^ 1;
        else if (color == now) return 0;
    }
    if (color == -1) return 2;
    return 1;
}

int get(int l) {
    for (int i = 1; i <= n * 2; i++) adj[i].clear();

    for (int i = 1; i <= n; i++) {
        int j = n - i + 1;
        if (i < j) {
            adj[i].push_back({j, 0});
            adj[j].push_back({i, 0});
        } else break;
    }

    for (int i = 1; i <= l; i++) {
        int j = l - i + 1;
        if (i < j) {
            adj[i + n].push_back({j + n, 0});
            adj[j + n].push_back({i + n, 0});
        } else break;
    }

    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            adj[i].push_back({i + n, 1});
            adj[i + n].push_back({i, 1});
        } else if (s[i] == '0') {
            adj[i].push_back({i + n, 0});
            adj[i + n].push_back({i, 0});
        }
    }

    int res = 1;
    memset(used, -1, sizeof used);
    for (int i = 1; i <= n * 2; i++) {
        if (used[i] == -1) {
            res = mul(res, go(i, l));
            if (!res) return 0;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> (s + 1);
    n = strlen(s + 1);
    int res = 0;
    for (int i = 1; i < n; i++) {
        res = add(res, get(i));
    }
    cout << res << endl;
    return 0;
}