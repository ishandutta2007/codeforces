#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int MOD = 1000000007;

int n;
vector<int> a[N];
int used[N];

void dfs(int u, pair<int, int> &res) {
    res.first++;
    used[u] = 1;
    for (int v : a[u]) {
        res.second++;
        if (!used[v]) {
            dfs(v, res);
        }
    }
}

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

int x[N], y[N];
int dead[N];

void init() {
    queue <int> q;
    for (int i = 1; i <= n * 2; i++) {
        if (dead[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : a[u]) {
            if (!dead[v]) {
                dead[v] = 1;
                q.push(v);
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", x + i, y + i);
        if (x[i] == y[i]) {
            dead[x[i]] = 1;
        } else {
            a[x[i]].push_back(y[i]);
            a[y[i]].push_back(x[i]);
        }
    }
    init();
    int res = 1;
    for (int i = 1; i <= 2 * n; i++) {
        if (used[i] || dead[i]) {
            continue;
        }
        pair<int, int> foo = make_pair(0, 0);
        dfs(i, foo);
        foo.second /= 2;
        if (foo.first == foo.second) {
            res = mul(res, 2);
        } else if (foo.first < foo.second) {
            res = 0;
            break;
        } else {
            res = mul(res, foo.first);
        }
    }
    cout << res << endl;
    return 0;
}