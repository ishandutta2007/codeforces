//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll mod=998244353;
const int N=500000;
vector<int> dp[N+10];
int mex(vector<int>v){
    sort(v.begin(),v.end());
    if (v.empty()) return 0;
    if (v[0]!=0) return 0;
    for (int i=1;i<v.size();i++){
        if (v[i]>v[i-1]+1) return v[i-1]+1;
    }
    return v.back()+1;
}
map<vector<vector<int> >,int>mp;
int len=-1;
int last=-1;
int f(ll x,int k){
    if (x<=last) return dp[x][k];
    x-=last+1;
    x%=len;
    x+=last+1;
    return dp[x][k];
}
ll a[N+10];
void solve(){
    len=last=-1;
    mp.clear();
    int n,x,y,z;cin>>n>>x>>y>>z;
    for (int i=1;i<=n;i++) cin>>a[i];
    swap(x,z);
    for (int i=0;i<=N;i++) dp[i].clear(),dp[i].resize(3);
    dp[0][0]=dp[0][1]=dp[0][2]=0;
    for (int i=1;i<=N;i++){
//        cout<<i<<endl;
        dp[i][0]=mex({dp[max(0,i-y)][1],dp[max(0,i-z)][2]});
        dp[i][1]=mex({dp[max(0,i-x)][0],dp[max(0,i-z)][2]});
        dp[i][2]=mex({dp[max(0,i-x)][0],dp[max(0,i-y)][1],dp[max(0,i-z)][2]});
        if (i>=4){
            if (mp.find({dp[i],dp[i-1],dp[i-2],dp[i-3],dp[i-4]})!=mp.end()){

//                cout<<"OK\n";
                len=i-mp[{dp[i],dp[i-1],dp[i-2],dp[i-3],dp[i-4]}];
                last=mp[{dp[i],dp[i-1],dp[i-2],dp[i-3],dp[i-4]}]-5;
                break;
            }
            mp[{dp[i],dp[i-1],dp[i-2],dp[i-3],dp[i-4]}]=i;
        }
    }
//    cout<<last<<endl;
    int cnt=0;
    ll xr=0ll;
    for (int i=1;i<=n;i++) xr^=f(a[i],2);
    for (int i=1;i<=n;i++){
        ll l=a[i];
        xr^=f(l,2);
        a[i]=max(0ll,l-x);
        if ((xr^f(a[i],0))==0) cnt++;
        a[i]=max(0ll,l-y);
        if ((xr^f(a[i],1))==0) cnt++;
        a[i]=max(0ll,l-z);
        if ((xr^f(a[i],2))==0) cnt++;
        xr^=f(l,2);
        a[i]=l;
    }
    cout<<cnt<<endl;
}
int32_t main(){
//    freopen("accounts.in","r",stdin);
//    freopen("accounts.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}