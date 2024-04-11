#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

const int nax = 2e5 + 5;
vector<tuple<int, int, int> > adj[nax];
const int mod = 998244353;
int n;

int d[nax];
void prep(){
    for(int i=2;i<nax;i++) d[i] = i;
    for(int i=2;i<nax;i++){
        if(d[i] == i){
            for(int j=i;j<nax;j+=i) d[j] = min(d[j], i);
        }
    }
}

int mx[nax];
int cur[nax];

vector<int> primes(int x){
    vector<int> res;
    while(x > 1){
        res.pb(d[x]);
        x /= d[x];
    }
    return res;
}

void dfs(int v, int p){
    for(auto [b, c, d] : adj[v]){
        if(b == p) continue;
        auto g1 = primes(d); // mno
        auto g2 = primes(c); // dziel

        for(int x : g1){
            cur[x] -= 1;
        }
        for(int x : g2){
            cur[x] += 1;
            mx[x] = max(mx[x], cur[x]);
        }
        dfs(b, v);
        for(int x : g2){
            cur[x] -= 1;
        }
        for(int x : g1){
            cur[x] += 1;
        }
    }
}

ll ans;
ll total;

ll pp(ll a, ll b){
    if(b == 0) return 1;
    ll ans = pp(a,b/2);
    ans*=ans;
    ans%=mod;
    if(b&1){
        ans*=a;
        ans%=mod;
    }
    return ans;
}

ll iv(ll a){
    return pp(a,mod-2);
}

void dfs2(int v, int p, ll mam){
    ans += mam;
    ans %= mod;
    for(auto [b, c, d] : adj[v]){
        if(b != p){
            ll licz = mam;
            licz *= d;
            licz %= mod;
            licz *= iv(c);
            licz %= mod;
            dfs2(b, v, licz);
        }
    }
}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<=n;i++){
        mx[i] = 0;
        cur[i] = 0;
    }
    for(int i=1;i<n;i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        adj[a].pb(make_tuple(b, c, d));
        adj[b].pb(make_tuple(a, d, c));
    }
    dfs(1, 1);
    //for(int i=2;i<15;i++) cout << i << " " << mx[i] << "\n";
    ans = 0;
    total = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<mx[i];j++){
            total *= i;
            total %= mod;
        }
    }
    //cout << total << "\n";
    dfs2(1, 1, total);
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    prep();
    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}