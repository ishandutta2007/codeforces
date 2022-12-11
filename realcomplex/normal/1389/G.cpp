#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 10;
bool sp[N];
vector<pii> G[N];

int tin[N];
int low[N];
int c[N];
int w[N];
int ti = 0;

int u[N], v[N];

bool edg[N];

void dfs(int u, int par){
    ti ++ ;
    tin[u]=ti;
    low[u]=ti;
    for(auto x : G[u]){
        if(x.fi == par) continue;
        if(tin[x.fi] == 0){
            dfs(x.fi, u);
            low[u]=min(low[u],low[x.fi]);
            if(tin[u] < low[x.fi]){
                edg[x.se]=true;
            }
        }
        else{
            low[u]=min(low[u],tin[x.fi]);
        }
    }
}

int idx[N];
int cid;
int need[N];

ll vl[N];
vector<pii> E[N];

void dfs1(int u){
    idx[u]=cid;
    vl[cid] += c[u];
    need[cid] += sp[u];
    for(auto y : G[u]){
        if(idx[y.fi] == 0 && edg[y.se]==false)
            dfs1(y.fi);
    }
}

ll dp[N];
int cnt[N];
int k;

void dfs2(int u, int pp){
    cnt[u] += need[u];
    dp[u]=vl[u];
    for(auto x : E[u]){
        if(x.fi != pp){
            dfs2(x.fi, u);
            cnt[u] += cnt[x.fi];
            if(cnt[x.fi] == 0 || cnt[x.fi] == k)
                dp[u] += dp[x.fi];
            else
                dp[u] += max(0ll, dp[x.fi]-w[x.se]);
        }
    }
}

ll res[N];

void dfs3(int u, int pp){
    res[u]=dp[u];
    ll d0, d1;
    int v0, v1;
    for(auto x : E[u]){
        if(x.fi == pp) continue;
        d0 = dp[u];
        d1 = dp[x.fi];
        v0 = cnt[u];
        v1 = cnt[x.fi];
        if(cnt[x.fi] == 0 || cnt[x.fi] == k)
            dp[u] -= d1;
        else
            dp[u] -= max(0ll, dp[x.fi]-w[x.se]);
        cnt[x.fi]=k;
        cnt[u]=k-v1;
        if(cnt[u] == 0 || cnt[u] == k)
            dp[x.fi] += dp[u];
        else
            dp[x.fi] += max(0ll, dp[u]-w[x.se]);
        dfs3(x.fi, u);
        dp[u]=d0;
        dp[x.fi]=d1;
        cnt[u]=v0;
        cnt[x.fi]=v1;
    }
}

int main(){
    fastIO;
    int n, m;
    cin >> n >> m >> k;
    int id;
    for(int i = 1; i <= k ; i ++ ){
        cin >> id;
        sp[id] = true;
    }
    for(int i = 1; i <= n; i ++ ){
        cin >> c[i];
    }
    for(int i = 1; i <= m; i ++ ){
        cin >> w[i];
    }
    for(int i = 1; i <= m; i ++ ){
        cin >> u[i] >> v[i];
        G[u[i]].push_back(mp(v[i], i));
        G[v[i]].push_back(mp(u[i], i));
    }
    dfs(1, -1);
    for(int i = 1; i <= n; i ++ ){
        if(idx[i] == 0){
            cid ++ ;
            dfs1(i);
        }
    }
    int aa, bb;
    for(int i = 1; i <= m; i ++ ){
        if(edg[i]){
            aa = idx[u[i]];
            bb = idx[v[i]];
            E[aa].push_back(mp(bb, i));
            E[bb].push_back(mp(aa, i));
        }
    }
    dfs2(1, -1);
    dfs3(1, -1);
    for(int i = 1; i <= n; i ++ ){
        cout << res[idx[i]] << " ";
    }
    cout << "\n";
    return 0;
}