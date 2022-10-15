// ./e-fib-tree.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

struct ed {
    int i, v;
};

using pii = pair<int, int>;
const int MN = 2e5 + 1;
const pii bad = {-1, -1};
int N,
    sz[MN], A[MN], B[MN];
vector<ed> g[MN];
bool f[MN], block[MN];
int fp[MN];

void dfs(int c, int p) {
    sz[c] = 1;
    for (auto to : g[c]) {
        if (to.v != p && !block[to.i]) {
            dfs(to.v, c);
            sz[c] += sz[to.v];
        }
    }
}
// edge, which one is large
pii geted(int c, int p, int tot) {
    for (auto to : g[c]) {
        if (to.v != p && !block[to.i]) {
            auto chr = geted(to.v, c, tot);
            if (chr != bad) return chr;
            int fa = fp[tot], fb = tot - fa; // fa = large, fb = small
            if (sz[to.v] == fa) return {to.i, to.v};
            if (sz[to.v] == fb) return {to.i, c};
        }
    }
    return bad;
}
bool solve(int c, int tot) {
    if (tot == 1) return true;
    dfs(c, -1);
    auto e = geted(c, -1, tot);
    if (e == bad) return false;

    block[e.first] = true;

    int oth = -1;
    if (A[e.first] == e.second) oth = B[e.first];
    else oth = A[e.first];

    bool ans = solve(e.second, fp[tot]) && solve(oth, tot-fp[tot]);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a = 0, b = 1;
    while (a+b < MN) {
        f[a+b] = true;
        fp[a+b] = b;
        // printf("f=%d fp=%d\n", a+b,fp[a+b]);
        b = a+b;
        a = b-a;
    }
    
    cin >> N;
    if (!f[N]) {
        cout << "NO\n";
        return 0;
    }
    for (auto i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        A[i] = a; B[i] = b;
        g[a].push_back({i, b});
        g[b].push_back({i, a});
    }

    bool ans = solve(1, N);
    cout << (ans ? "YES\n" : "NO\n");

    return 0;
}