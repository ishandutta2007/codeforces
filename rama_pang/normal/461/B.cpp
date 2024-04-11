#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define ll long long
using namespace std;
const ll MOD=1e9 +7;
ll N,tipe[100005],dp[100005][3];
vector<ll> G[100005];
void dfs (ll n){
    dp[n][tipe[n]]=1;
    dp[n][tipe[n]^1]=0;
    for (ll i:G[n]){
        dfs(i);
        ll one=dp[n][1];
        ll zero=dp[n][0];
        //dipisah
        dp[n][0]=0; dp[n][1]=0;
        dp[n][0]=zero*dp[i][1]; //banyak  0 mungkin= 0 mungkin sekarang*(i valid)
        dp[n][1]=one*dp[i][1]; //sama spt diatas
        dp[n][0]%=MOD;
        dp[n][1]%=MOD;
        //digabung
        dp[n][1]+= one*dp[i][0]%MOD + zero*dp[i][1]%MOD;
        dp[n][0]+= zero*dp[i][0];
        dp[n][0]%=MOD;
        dp[n][1]%=MOD;
    }
    return;
}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=1; i<N; i++){
        ll a; cin>>a;
        G[a].pb(i);
    }
    for (int i=0; i<N; i++){
        cin >> tipe[i];
    }
    dfs(0);
    cout << dp[0][1]%MOD << endl;
}