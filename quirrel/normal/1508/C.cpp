#include<bits/stdc++.h>
#define ll long long
using namespace std;
set<ll> S;
map<ll,ll> M[200009];
vector<pair<ll,pair<ll,ll> > > E, E1;
void dfs(ll x, ll y){
    vector<ll> v;
    if(y != -1) {E.push_back({0, {x, y}}); M[x][y] = 2; M[y][x] =2; }

    for(auto it = S.begin(); it != S.end(); it++){

        if(M[x][*it] != 1) v.push_back(*it);
    }
    for(ll y : v){
        S.erase(y);
    }
    for(ll y : v){
        dfs(y, x);
    }
}
ll ans = 1e18;
    ll n, m;
ll p[200009],s[200009];
ll P(ll x){
    if(p[x] == x) return x;
    p[x] = P(p[x]);
    return p[x];
}
void un(ll a, ll b){
    if(s[a] > s[b]) swap(a,b);
    p[a] = b;
    s[b] += s[a];
}
void MST(ll x){
    if(x == 0) E1 = E;
    sort(E.begin(), E.end());
    for(ll i = 1; i <= n; i++){
        s[i] = 1;
        p[i] = i;
    }
    ll mst = 0;
    for(auto e : E){
        ll a = e.second.first, b = e.second.second, c = e.first;
        a = P(a); b = P(b);
        if(a == b) continue;
        mst += c;
        un(a,b);
        if(x == 1) E1.push_back(e);
    }
    E = E1;
    ans = min(ans, mst);
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll X = 0;
    cin >> n>> m;
    for(ll i = 1; i <= m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        M[a][b] = 1;
        M[b][a] = 1;
        X ^= c;
        E.push_back({c, {a,b}});
    }
    MST(1);
    for(ll i = 1; i <= n; i++){
        S.insert(i);
    }
    for(ll i = 1; i <= n; i++){
        if(S.find(i) != S.end()){
            S.erase(i);
            dfs(i,  -1);
        }
    }
    ll ok = 0;
    if(n*(n-1)/2 - m > n)
        ok = 1;
    else{
        for(ll i = 1; i <= n; i++){
            for(ll j = 1; j <= n; j++){
                if(i != j && M[i][j] == 0) ok = 1;
            }
        }
    }
    if(ok){
        MST(0);
        cout << ans << endl;
        return 0;
    }
    else{
        for(ll i = 0; i < E.size(); i++){
            if(E[i].first == 0){
                E[i].first = X;
                MST(0);
                E[i].first = 0;
            }
        }
        cout << ans << endl;
        return 0;
    }


}
/*

*/