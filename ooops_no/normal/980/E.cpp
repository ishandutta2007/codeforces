#include <bits/stdc++.h>
using namespace std;

#define pb push_back

#pragma GCC target("avx,avx2,sse3,ssse3,sse4.1,sse4.2,tune=native")
#pragma GCC optimize(3)
#pragma GCC optimize("O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e6 + 10;
vector<int> g[N];
vector<int> d(N);
vector<bool> used(N);
int po[30][N];

void dfs(int v, int p){
    for (auto to : g[v]){
        if (to != p){
            d[to] = d[v] + 1;
            po[0][to] = v;
            dfs(to, v);
        }
    }
}

int lca(int a, int b){
    if (d[a] < d[b]) swap(a, b);
    for (int i = 28; i >= 0; --i){
        if (d[po[i][a]] >= d[b]){
            a = po[i][a];
        }
    }
    if (a == b) return a;
    for (int i = 28; i >= 0; --i){
        if (po[i][a] != po[i][b]){
            a = po[i][a];
            b = po[i][b];
        }
    }
    return po[0][a];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    k = n - k;
    for (int i = 0; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 0; i < 30; ++i){
        po[i][n] = n;
    }
    dfs(n, -1);
    for (int i = 1; i < 30; ++i){
        for (int j = 1; j <= n; ++j){
            po[i][j] = po[i - 1][po[i - 1][j]];
        }
    }
    vector<int> ans;
    ans.pb(n);
    used[n] = 1;
    k--;
    for (int i = n - 1; i >= 1; --i){
        if (used[i]){
            ans.pb(i);
            continue;
        }
        int u = lca(i, ans.back()), last = ans.back();
        if (u == i){
            for (int j = 28; j >= 0; --j){
                if (used[po[j][last]]){
                    last = po[j][last];
                }
            }
            if (k >= d[last] - d[i]){
                k -= d[last] - d[i];
                while(last != i){
                    used[last] = 1;
                    last = po[0][last];
                }
                used[i] = 1;
                ans.pb(i);
            }
            continue;
        }
        if (last == u){
            int now = i;
            for (int j = 28; j >= 0; --j){
                if (d[po[j][now]] > d[u] && !used[po[j][now]]){
                    now = po[j][now];
                }
            }
            if (k >= abs(d[now] - d[i]) + 1){
                k -= abs(d[now] - d[i]) + 1;
                int j = i;
                while(j != now){
                    used[j] = 1;
                    j = po[0][j];
                }
                used[j] = 1;
                ans.pb(i);
            }
            continue;
        }
        for (int j = 28; j >= 0; --j){
            if (used[po[j][last]]){
                last = po[j][last];
            }
        }
        if (d[last] > d[u]){
            if (k >= (d[last] - d[u]) + (d[i] - d[u])){
                k -= (d[last] - d[u]) + (d[i] - d[u]);
                while(last != u){
                    used[last] = 1;
                    last = po[0][last];
                }
                used[last] = 1;
                int j = i;
                while(j != u){
                    used[j] = 1;
                    j = po[0][j];
                }
                used[j] = 1;
                ans.pb(i);
            }
            continue;
        }
        if (d[last] <= d[u]){
            int now = i;
            for (int j = 28; j >= 0; --j){
                if (d[po[j][now]] > d[u] && !used[po[j][now]]){
                    now = po[j][now];
                }
            }
            if (k >= abs(d[now] - d[i]) + 1){
                k -= abs(d[now] - d[i]) + 1;
                int j = i;
                while(j != now){
                    used[j] = 1;
                    j = po[0][j];
                }
                used[j] = 1;
                ans.pb(i);
            }
        }
    }
    vector<int> was(n + 1);
    for (auto to : ans) was[to] = 1;
    for (int i = 1; i <= n; ++i){
        if (!was[i]){
            cout << i << " ";
        }
    }
    return 0;
}