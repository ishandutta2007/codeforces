#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#define y2 y_2
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
//#define int ll
typedef long long ll;
typedef long double ld;
const int N=2100;
const int inf=2e9;
const int Lg=30;
mt19937_64 rnd(time(NULL));
vector<int>g[N];
ll mod;
ll binpow(ll a,ll b){
    ll res=1;
    while (b){
        if (b&1) res=(res*a)%mod;
        b/=2;
        a=(a*a)%mod;
    }
    return res;
}
ll dp[N][N];
ll pref[N][N];
int n;
ll ans[N];
ll add[N][N];
ll M[N];
void dfs(int v,int pr){
    for (int to:g[v]){
        if (to==pr) continue;
        dfs(to,v);
    }
    if (v==1){
        for (int i=1;i<=n;i++){
            ans[i]=1;
            for (int to:g[v]){
                if (to==pr) continue;
                ans[i]*=pref[to][i];
                ans[i]%=mod;
            }
        }
    }
    for (int x=1;x<=n;x++){
        ll mult=1;
        vector<int>go;
        int ind=0;
        for (int to:g[v]){
            if (to==pr) continue;
            go.push_back(to);
            mult*=pref[to][x];
            mult%=mod;
            M[ind++]=mult;
        }
        dp[v][x]+=mult;
        dp[v][x]%=mod;
        mult=1;
        for (int i=(int)go.size()-1;i>=0;i--){
            ll cur=mult;
            if (i) cur=(cur*M[i-1])%mod;
            add[go[i]][x+1]+=cur;
            add[go[i]][x+1]%=mod;
            mult*=pref[go[i]][x];
            mult%=mod;
        }

    }
    for (int to:g[v]){
        if (to==pr) continue;
        for (int i=1;i<=n;i++){
            add[to][i]+=add[to][i-1];
            if (add[to][i]>=mod) add[to][i]-=mod;
            dp[v][i]+=dp[to][i]*add[to][i];
            dp[v][i]%=mod;
        }
    }


    pref[v][0]=0;
    for (int i=1;i<=n;i++){
        pref[v][i]=(pref[v][i-1]+dp[v][i])%mod;
    }
}
ll C[N][N];
void solve(){
    cin>>n>>mod;
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    C[0][0]=1;
    for (int i=1;i<=n;i++){
        C[i][0]=1;
        for (int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
    for (int i=2;i<=n;i++){
        for (int j=1;j<i;j++){
            ans[i]-=ans[j]*C[i][j];
            ans[i]%=mod;
        }
        ans[i]+=mod;
        ans[i]%=mod;
    }
    for (int i=1;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;




}
int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
//    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

/**
2 998244353
1 2

**/