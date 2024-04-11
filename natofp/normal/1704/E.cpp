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

const int nax = 1005;
const int mod = 998244353;
int n, m;
ll a[nax];
ll b[nax];
vector<int> adj[nax];
int indeg[nax];
int dp[nax];

void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) indeg[i] = 0;
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=m;i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        indeg[y]++;
    }
    vector<int> ord;
    for(int i=1;i<=n;i++){
        if(indeg[i] == 0) ord.pb(i);
    }
    int wsk = 0;
    while(wsk < ord.size()){
        int cur = ord[wsk++];
        for(int x : adj[cur]){
            indeg[x]--;
            if(indeg[x] == 0) ord.pb(x);
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) dp[i] = 0;
    for(int x : ord){
        dp[x] += a[x];
        dp[x] %= mod;
        for(int y : adj[x]){
            dp[y] += dp[x];
            dp[y] %= mod;
        }
    }
    ans = dp[ord.back()];

    for(int i=1;i<=n+1;i++){
        ll sum = 0;
        for(int j=1;j<=n;j++){
            sum += a[j];
        }
        if(sum == 0){
            break;
        }
        if(a[ord.back()] == 0) ans++;
        for(int j=1;j<=n;j++) b[j] = a[j];
        for(int j=1;j<=n;j++){
            if(a[j] > 0){
                b[j] -= 1;
                for(int y : adj[j]){
                    b[y] += 1;
                }
            }
        }
        for(int j=1;j<=n;j++) a[j] = b[j];
    }
    cout << ans % mod << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}