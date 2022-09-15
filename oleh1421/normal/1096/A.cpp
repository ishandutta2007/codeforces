#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<ll>g[100001];
vector<ll>a[100001];
ll dp[100001];
ll n;
ll score[100001];
bool cmp(ll cur1,ll cur2){
     return dp[cur1]>dp[cur2];
}
ll ans=-1000000000000000ll;
void dfs1(ll v,ll pr){
    for (ll i=0;i<a[v].size();i++){
        if (a[v][i]!=pr) {
                g[v].push_back(a[v][i]);
                dfs1(a[v][i],v);
        }
    }
}
void dfs(ll v){
    for (ll i=0ll;i<g[v].size();i++){
        dfs(g[v][i]);
    }
    if (g[v].size()==0ll){
        dp[v]=score[1ll];
        return;
    }
    sort(g[v].begin(),g[v].end(),cmp);
    ll sum=0ll;
    for (ll i=1;i<=g[v].size();i++){
        ll to=g[v][i-1];
        sum+=dp[to];
        dp[v]=max(dp[v],sum+score[i+1ll]);
        ans=max(ans,sum+score[i]);
        cout<<ans<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while (t--){
        ll l,r;cin>>l>>r;
        cout<<l<<" "<<l*2ll<<'\n';
    }
    return 0;
}