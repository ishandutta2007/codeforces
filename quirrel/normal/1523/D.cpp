#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> V[200009], W[200009];
ll F[200009], B[200009];
void solve(){
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n, m, p;
    cin >> n >> m >> p;
    for(ll i = 1; i <= n; i++){
        string s;
        cin >> s;
        for(ll j = 0; j < m; j++){
            if(s[j] == '1'){
                W[i].push_back(j);
                V[j].push_back(i);
            }
        }
    }
    long long ans = 0;
    for(ll ii = 0; ii < 100; ii++){
        int x = uniform_int_distribution<int>(0, n-1)(rng) + 1;
        for(ll j = 1; j <= n; j++){
            B[j] = 0;
        }
        ll M = W[x].size();
        for(ll j = 0; j < W[x].size(); j++){
            ll ind = W[x][j];
            for(ll y : V[ind]){
                B[y] |= (1ll << j);
            }
        }
 
        for(ll j = 0; j < (1ll << M); j++)
            F[j] = 0;
        for(ll j = 1; j <= n; j++){
            F[B[j]]++;
        }
        for(ll i = 0; i < M; i++){
            for(ll j = 0; j < (1ll << M); j++){
                if(!(j & (1ll << i))) F[j] += F[j ^ (1ll << i)];
            }
        }
        ll u = 0;
        for(ll j =0; j < (1ll << M); j++){
            if(F[j] >= (n+1)/2 &&
               __builtin_popcountll(j) >= __builtin_popcountll(u)){
                    u = j;
            }
        }
        if(__builtin_popcountll(u) >= __builtin_popcountll(ans)){
            ans = 0;
           for(ll j = 0; j < W[x].size(); j++){
                ll ind = W[x][j];
                if(u & (1ll << j)) ans += (1ll<< ind);
           }
        }
    }
    for(ll i = 0; i < m; i++){
        if((1ll << i) & ans) cout <<'1'; else cout<<'0';
    }
    cout<<endl;
}
main(){
    ios_base::sync_with_stdio(false);
 
    cin.tie(0);
    ll t = 1;
    //cin >> t;
 
    while(t--){
        solve();
    }
 
}