#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[200009],scc[200009];
ll G[200009];
vector<pair<ll,ll> > v[200009],w[200009];
vector<ll> T;
void dfs(ll x){
    f[x] = 1;
    for(auto E : v[x]){
        ll y = E.first;
        if(f[y] == 0)
            dfs(y);
    }
    T.push_back(x);
}
void dfs1(ll x){

     for(auto E : w[x]){
        ll y = E.first;
        if(scc[y] == 0){
            scc[y] = scc[x];
            dfs1(y);
        }
    }
}
ll D[200009], rD[200009];
void dfs2(ll x){
    f[x] = 1;
    for(auto E : v[x]){
        ll y = E.first, l = E.second;
        if(f[y]) continue;
        if(scc[y] == scc[x]){
            D[y] = D[x] + l;
            dfs2(y);
        }
    }
}
void dfs3(ll x){
    f[x] = 1;
    for(auto E : w[x]){
        ll y = E.first, l = E.second;
        if(f[y]) continue;
        if(scc[y] == scc[x]){
            rD[y] = rD[x] + l;
            dfs3(y);
        }
    }
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        w[b].push_back({a,c});

    }
    for(ll i = 1; i <= n; i++){
        if(f[i] == 0){
            dfs(i);
        }
    }

    ll c = 0;
    reverse(T.begin(), T.end());
    for(ll i : T){
        if(scc[i] == 0){
            scc[i] = ++c;
            dfs1(i);
        }
    }
    for(ll i = 1; i <= n; i++)
        f[i] = 0;
    for(ll i = 1; i <= n; i++){
        if(f[i] == 0){
            dfs2(i);
        }
    }
    for(ll i = 1; i <= n; i++)
        f[i] = 0;
    for(ll i = 1; i <= n; i++){
        if(f[i] == 0){
            dfs3(i);
        }
    }
    for(ll i = 1; i <= n; i++){
        for(auto E : v[i]){
            ll j = E.first;
            ll l = E.second;
            if(scc[i] != scc[j]) continue;
            G[scc[i]] = __gcd(G[scc[i]], D[i] + l + rD[j]);
        }
    }
    ll q;
    cin >> q;
    while(q--){
        ll v,s,t;
        cin >> v >> s >> t;
        ll g = __gcd(s, t);
        if(g % __gcd(G[scc[v]],t) == 0){
            cout << "YES"<<endl;
        }
        else cout <<"NO"<<endl;
    }
}
/*








*/