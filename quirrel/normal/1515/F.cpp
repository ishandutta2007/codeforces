#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> v[300009],v1[300009];
ll f[300009];
void gett(ll x){
    f[x] = 1;
    for(ll y: v1[x]){
        if(f[y] == 0){
            gett(y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
    }
}
ll sz[300009];
void dfs(ll x, ll p){
    sz[x] = 1;
    for(ll y : v[x]){
        if(y == p || f[y] == 1) continue;
        dfs(y, x);
        sz[x] += sz[y];
    }
}
ll N, X;
ll fc(ll x, ll p){
    for(ll y : v[x]){
        if(y == p || f[y] == 1) continue;
        if(2*sz[y] > N) return fc(y, x);
    }
    return x;
}
ll A[300009];
ll dfs2(ll x, ll p){
    sz[x] = 1;
    ll ans = A[x];
    for(ll y : v[x]){
        if(y == p || f[y] == 1) continue;
        ans += dfs2(y, x);
        sz[x] += sz[y];
    }
    return ans;
}
vector<pair<ll,ll> > ans;
void fc(ll x){
    dfs(x, -1);
    N = sz[x];
    ll C = fc(x, -1);
    vector<pair<ll,ll> > adj;
    f[C] = 1;
    for(ll x : v[C]){
        if(f[x]) continue;
        adj.push_back({dfs2(x, C) - (sz[x] - 1) * X, x});
    }
    sort(adj.rbegin(), adj.rend());
   // cout<<C<<endl;
    for(auto E : adj){
        ll x = E.second;
       // cout<<C<<" "<<x<<" "<<A[C] +A[x]<<" "<<X<<endl;
        if(A[C] + A[x] >= X){
            ans.push_back({C, x});
            A[x] += A[C]- X;
            fc(x);
        }
        else{
            fc(x);
            ans.push_back({C,x});
        }
        A[C] += E.first - X;
      //  cout<<endl;
    }


}
map<pair<ll,ll>,ll> M;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m >> X;
    ll s = 0;
    for(ll i = 1; i <= n; i++){
        cin >> A[i];
        s += A[i];
    }
    if(s < (n - 1) * X){
        cout << "NO" <<endl;
        return 0;
    }
    for(ll i = 1; i <= m; i++){
        ll a,b;
        cin >> a >> b;
        v1[a].push_back(b);
        v1[b].push_back(a);
        M[make_pair(a,b)] = i;

        M[make_pair(b,a)] = i;
    }
    cout<<"YES"<<endl;
    gett(1);
    for(ll i= 1; i <= n; i++){
        f[i] = 0;
    }
    fc(1);
    for(auto E : ans){
        cout << M[E] << endl;
    }

}
/*








*/