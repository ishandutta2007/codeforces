#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1000010;
const ll mod=1000000007;
const ll inf=(1ll<<60);
ll a[N];
ll b[N];
vector<int>g[N];
vector<int>order;
bool used[N];
ll dp[N];
void dfs(int v,int pr){
    dp[v]=a[v];
    for (int to:g[v]){
        if (to!=pr){
            dfs(to,v);
            dp[v]+=max(0ll,dp[to]);
        }
    }
    order.push_back(v);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++){
        cin>>b[i];
        if (b[i]!=-1){
            g[b[i]].push_back(i);
        }
    }
    for (int i=1;i<=n;i++){
        if (b[i]==-1){
            dfs(i,0);
        }
    }
    vector<int>ans;
    for (int i:order){
        if (dp[i]>0) ans.push_back(i);
    }
    reverse(order.begin(),order.end());
    for (int i:order){
        if (dp[i]<=0) ans.push_back(i);
    }
    ll res=0ll;
    for (int i:ans){
        res+=a[i];
        if (b[i]!=-1) a[b[i]]+=a[i];
    }
    cout<<res<<endl;
    for (int i:ans) cout<<i<<" ";
    cout<<endl;
    return 0;
}