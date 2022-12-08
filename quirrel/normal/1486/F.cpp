#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll p[900009][21], h[900009], F[900009],S[900009];
vector<ll> v[900009];
vector<pair<ll,ll> > q[900009];
ll t = 0;
void dfs(ll x, ll P){
    p[x][0] = P;
    h[x] = h[P] + 1;
    for(ll y : v[x]){
        if(y == P) continue;
        dfs(y, x);
    }

}
ll n;
ll ans = 0;
ll fn(ll y, ll x){
    if(y > n) return y;
    for(ll i = 19; i >= 0; i--)
        if(h[p[y][i]] > h[x]) y = p[y][i];

    return y;
}
void dfs2(ll x){
    if(x <= n){
        for(ll y : v[x]){
            if(y == p[x][0]) continue;
            dfs2(y);
            F[x] += F[y];
            S[x] += S[y];
        }
    }
    vector<ll> U;
    vector<pair<ll,ll> > W;
    for(auto Q : q[x]){
        ll a = Q.first, b = Q.second;
        ll a1 = fn(a, x), b1 = fn(b, x);
        if(a1 > b1) swap(a1, b1);
        ans += S[x] - S[a1] - S[b1] -
            2*(F[x] - q[x].size() - F[a1] - F[b1]);
        U.push_back(a1);
        U.push_back(b1);
        
        W.push_back({a1, b1});
    }
    ll m = U.size()/2, cnt1 = 0, cnt2 = 0;
    sort(U.begin(), U.end());
    sort(W.begin(), W.end());
    ll k = 1;
    for(ll i = 1; i < U.size(); i++){
        if(U[i] == U[i-1]) k++;
        else cnt1 += k*(k-1)/2, k =1;
    }
    cnt1 += k*(k-1)/2;
    k = 1;
    for(ll i = 1; i < W.size(); i++){
        if(W[i] == W[i-1]) k++;
        else cnt2 += k*(k-1)/2, k =1;
    }
    cnt2 += k*(k-1)/2;
    cnt1 -= 2*cnt2;
    ll cnt3 = m*(m-1)/2 - cnt1 - cnt2;
   ans = ans - 3*cnt3 - 2*cnt1;


}
ll lca(ll x, ll y){
    if(h[x] > h[y]) swap(x, y);
    for(ll i = 19; i >= 0; i--){
        if(h[p[y][i]] >= h[x]) y = p[y][i];
    }

    if(y == x) return x;
    for(ll i= 19; i >= 0; i--){
        if(p[x][i] != p[y][i])
            x = p[x][i],
            y = p[y][i];
    }
    return p[x][0];
}
main(){
    cin >> n;
    for(ll i = 1; i < n; i++){
        ll a, b;
        cin >> a>> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,0);

    for(ll j = 1; j< 20; j++){
        for(ll i = 1; i <= n; i++){
            p[i][j] = p[p[i][j-1]][j-1];
        }
    }
    ll m;
    cin >> m;
    ll N = n;
    for(ll i = 1; i <= m; i++){
        ll a, b;
        cin >> a>>b;
        ll c = lca(a,b);
        if(c == a) {
            a = ++N;
            v[c].push_back(N);
        }
        if(c == b){
            b = ++N;
            v[c].push_back(N);
        }
        S[a]++;
        S[b]++;
        F[c]++;
        q[c].push_back({a,b});
    }
    dfs2(1);
    cout<<ans<<endl;

}