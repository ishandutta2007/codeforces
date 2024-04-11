#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
vector<pair<int, int>> g[N];
int p[N], mask[N], ans[N], ptr[N], sub[N], h[N];
vector<pair<int, int>> v[N];
int maxHeight[(1 << ('v' - 'a' + 1))];

void pre(int i) {
    sub[i] = 1;
    for (auto &j : g[i]) {
        h[j.first] = h[i] + 1;
        mask[j.first] = (mask[i] ^ j.second);
        pre(j.first);
        sub[i] += sub[j.first];
    }
}


void dfs(int i, bool isHeavy) {
    pair<int, int> heavy = { -1, -1};
    for (auto &j : g[i]) {
        heavy = max(heavy, {sub[j.first], j.first});
    }
    for (auto &j : g[i]) {
        if (j.first != heavy.second)
            dfs(j.first, 0);
    }
    if (heavy.second != -1) {
        dfs(heavy.second, 1);
        ptr[i] = ptr[heavy.second];
    }
    ans[i] = max(ans[i], maxHeight[mask[i]] - h[i]);
    for (int b = 0; b <= 'v' - 'a'; ++b) {
        ans[i] = max(ans[i], maxHeight[mask[i] ^ (1 << b)] - h[i]);
    }
    v[ptr[i]].push_back({mask[i], h[i]});
    maxHeight[mask[i]] = max(maxHeight[mask[i]], h[i]);

    for (auto &j : g[i]) {
        if (j.first != heavy.second) {
            for (auto & x : v[ptr[j.first]]) {
                ans[i] = max(ans[i], x.second + maxHeight[x.first] - 2 * h[i]);
                for (int b = 0; b <= 'v' - 'a'; ++b) {
                    ans[i] = max(ans[i], x.second + maxHeight[x.first ^ (1 << b)] - 2 * h[i]);
                }
            }
            for (auto & x : v[ptr[j.first]]) {
                maxHeight[x.first] = max(maxHeight[x.first], x.second);
                v[ptr[i]].push_back(x);
            }
        }
    }

    if (not isHeavy) {
        for (auto & x : v[ptr[i]]) {
            maxHeight[x.first] = -1e9;
        }
    }

    for (auto &j : g[i]) {
        ans[i] = max(ans[i], ans[j.first]);
    }

}

int main()
{
    ios_base::sync_with_stdio(false);    cin.tie(NULL);

    int n; cin >> n;
    for (int i = 2; i <= n; ++i) {
        int u; char ch;
        cin >> u >> ch;
        p[i] = u;
        g[u].push_back({i, 1 << (ch - 'a')});
    }
  
    for (int i = 1; i <= n; ++i) ptr[i] = i;

    fill(maxHeight, maxHeight + sizeof(maxHeight) / sizeof(int), -1e9);
    pre(1);
    
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";

    return 0;
}