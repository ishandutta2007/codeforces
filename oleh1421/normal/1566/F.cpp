#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
const int N=300010;
const ll mod=998244353;
ll l[N],r[N];
ll a[N];
vector<pair<ll,ll> >g[N];
ll dp[N][2];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n+1;i++) g[i].clear();
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) cin>>l[i]>>r[i];
    sort(a+1,a+n+1);
    a[0]=-1000000000000000000ll;
    a[n+1]=1000000000000000000ll;
    vector<pair<int,int> >v;
    for (int i=1;i<=m;i++){
        int cnt=upper_bound(a+1,a+n+1,r[i])-lower_bound(a+1,a+n+1,l[i]);
        if (cnt==0){
            v.push_back({r[i],l[i]});
        }
    }
    sort(v.begin(),v.end());
    vector<pair<ll,ll> >u;
    ll mx=-1000000001;
    for (auto cur:v){
        if (cur.second<=mx) continue;
        mx=cur.second;
        u.push_back({cur.second,cur.first});
    }
    for (auto cur:u){
        int ind=upper_bound(a+1,a+n+1,cur.second)-a;
        g[ind].push_back(cur);
    }
    dp[0][0]=0;
    dp[0][1]=0;
    for (int i=1;i<=n+1;i++){
        if (g[i].empty()){
            dp[i][0]=dp[i][1]=dp[i-1][0];
            continue;
        }
        dp[i][0]=min(g[i].back().first-a[i-1]+dp[i-1][1],(g[i].back().first-a[i-1])*2+dp[i-1][0]);
        dp[i][0]=min(dp[i][0],dp[i-1][0]+a[i]-g[i][0].second);
        for (int j=1;j<g[i].size();j++){
            dp[i][0]=min(dp[i][0],g[i][j-1].first-a[i-1]+dp[i-1][1]+a[i]-g[i][j].second);
            dp[i][0]=min(dp[i][0],(g[i][j-1].first-a[i-1])*2+dp[i-1][0]+a[i]-g[i][j].second);
        }
        dp[i][1]=min(g[i].back().first-a[i-1]+dp[i-1][1],(g[i].back().first-a[i-1])*2+dp[i-1][0]);
        dp[i][1]=min(dp[i][1],dp[i-1][0]+(a[i]-g[i][0].second)*2);
        for (int j=1;j<g[i].size();j++){
            dp[i][1]=min(dp[i][1],g[i][j-1].first-a[i-1]+dp[i-1][1]+(a[i]-g[i][j].second)*2);
            dp[i][1]=min(dp[i][1],(g[i][j-1].first-a[i-1])*2+dp[i-1][0]+(a[i]-g[i][j].second)*2);
        }
    }

    cout<<dp[n+1][0]<<endl;
    for (int i=1;i<=n+1;i++) g[i].clear();


}
int32_t main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}