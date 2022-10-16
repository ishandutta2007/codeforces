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
#define mt make_tuple

using namespace std;

const int nax = 111;
const int mod = 998244353;
int x[nax];
int y[nax];
int mini[nax];
const int inf = 1e9;
vector<int> adj[nax];
int n;

vector<int> spojne;

bool vis[nax];
int kraw = 0;
int wie = 0;
bool bad[nax];
bool ok;

void dfs(int v){
    ok &= !bad[v];
    wie++;
    vis[v] = true;
    for(int x : adj[v]){
        kraw++;
        if(!vis[x]) dfs(x);
    }
}

int dp[nax][nax];
ll f[nax];
ll iw[nax];

ll pp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1){
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
        b /= 2;
    }
    return ans;
}

void add(int &a, int b){
    a += b;
    if(a >= mod) a -= mod;
}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> x[i] >> y[i];
    }

    for(int i=1;i<=n;i++){
        mini[i] = inf;
        for(int j=1;j<=n;j++){
            if(i != j) mini[i] = min(mini[i], abs(x[i] - x[j]) + abs(y[i] - y[j]));
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j > i){
                int d = abs(x[i] - x[j]) + abs(y[i] - y[j]);
                if(d == mini[i] && d == mini[j]){
                    adj[i].pb(j);
                    adj[j].pb(i);
                }
                else{
                    if(d == mini[i]) bad[i] = true;
                    if(d == mini[j]) bad[j] = true;
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ok = true;
            wie = 0;
            kraw = 0;
            dfs(i);
            kraw /= 2;
            int musze = wie * (wie - 1) / 2;
            if(musze == kraw && ok) spojne.pb(wie);
            else{
                for(int j=1;j<=wie;j++) spojne.pb(1);
            }
        }
    }

    f[0] = 1;
    iw[0] = 1;
    for(int i=1;i<nax;i++){
        f[i] = (f[i - 1] * i) % mod;
        iw[i] = pp(f[i], mod - 2);
    }

    dp[0][0] = 1;
    for(int i=0;i<spojne.size();i++){
        int sz = spojne[i];
        for(int j=0;j<nax-7;j++){
            add(dp[i + 1][j + 1], dp[i][j]);
            if(sz > 1) add(dp[i + 1][j + sz], dp[i][j]);
        }
    }
    int k = spojne.size();
    ll ans = 0;
    for(int i=0;i<=n;i++){
        ll cur = dp[k][i] * f[n];
        cur %= mod;
        cur *= iw[n - i];
        cur %= mod;
        ans += cur;
        ans %= mod;
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}