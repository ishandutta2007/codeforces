#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
vector<pii> T[N];
ll subt[N];
ll w[N];

void dfs(int u, int par){
    subt[u]=0;
    if(par != -1 && T[u].size() == 1){
        subt[u] = 1;
    }
    for(auto x : T[u]){
        if(x.fi==par)continue;
        w[x.fi] = x.se;
        dfs(x.fi,u);
        subt[u] += subt[x.fi];
    }
}

void solve(){
    int n;
    ll s;
    cin >> n >> s;
    for(int i = 1; i <= n; i ++ )
        T[i].clear();
    int u, v;
    ll ww;
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v >> ww;
        T[u].push_back(mp(v,ww));
        T[v].push_back(mp(u,ww));
    }
    dfs(1,-1);
    priority_queue<pii> good;
    ll fs;
    ll S = 0;
    for(int i = 2; i <= n; i ++ ){
        fs=subt[i]*1ll*((w[i]+1)/2ll);
        S += subt[i] * 1ll * w[i];
        good.push(mp(fs,i));
    }
    int ans = 0;
    int id;
    while(S > s){
        id = good.top().se;
        good.pop();
        S -= subt[id] * 1ll * w[id];
        w[id] /= 2;
        S += subt[id] * 1ll * w[id];
        fs = subt[id]*1ll*((w[id]+1)/2ll);
        good.push(mp(fs,id));
        ans ++ ;
    }
    cout << ans << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t =0 ; t < tc; t ++ )
        solve();
    return 0;
}