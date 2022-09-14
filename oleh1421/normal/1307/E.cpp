//#pragma GCC opitmize ("trapv")
//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int N=5010;
const int mod=1000000007;
int a[N];
int l[N];
int r[N];
vector<int>g[N];
pair<int,ll>combine(pair<int,ll>a,pair<int,ll>b){
    if (a.first==b.first) return {a.first,(a.second+b.second)%mod};
    return max(a,b);
}
int cntl[N];
int cntr[N];
int cntlr[N];
int f[N];
int h[N];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i],g[a[i]].push_back(i);
    for (int i=1;i<=m;i++){
        cin>>f[i]>>h[i];
        if (g[f[i]].size()<h[i]){
            l[i]=n+1;
            r[i]=0;
            continue;
        }
        l[i]=g[f[i]][h[i]-1];
        r[i]=g[f[i]][(int)g[f[i]].size()-h[i]];
    }
    pair<int,ll>ans={0,1};
    for (int i=1;i<=m;i++){

        if (r[i]==0) continue;
        pair<int,ll>cur={0,1};
        memset(cntl,0,sizeof(cntl));
        memset(cntr,0,sizeof(cntr));
        memset(cntlr,0,sizeof(cntlr));
        for (int j=1;j<=m;j++){
            if (r[j]==0 || i==j) continue;
            if (l[j]<l[i] && r[j]>l[i]) cntlr[f[j]]++;
            else if (l[j]<l[i]) cntl[f[j]]++;
            else if (r[j]>l[i]) cntr[f[j]]++;
        }
        for (int j=1;j<=n;j++){
            if (j==f[i]) continue;
            cur.first+=2;
            ll mult=(cntl[j]+cntlr[j])*(cntr[j]+cntlr[j])-cntlr[j];
            if (mult==0){
                cur.first--;
                mult=cntl[j]+cntr[j]+cntlr[j]*2ll;
            }
            if (mult==0){
                cur.first--;
                mult=1ll;
            }
            cur.second*=mult;
            cur.second%=mod;
        }
        cur.first++;
        if (cntlr[f[i]]+cntr[f[i]]>0){
            cur.first++;
            cur.second*=cntlr[f[i]]+cntr[f[i]];
            cur.second%=mod;
        }
//        cout<<cur.first<<" "<<cur.second<<endl;
        ans=combine(ans,cur);
    }
    pair<int,ll>cur={0,1};
    memset(cntr,0,sizeof(cntr));
    for (int i=1;i<=m;i++){
        if (r[i]){
            cntr[f[i]]++;
        }
    }
    for (int i=1;i<=n;i++){
        if (cntr[i]){
            cur.first++;
            cur.second*=cntr[i];
            cur.second%=mod;
        }
    }
    ans=combine(ans,cur);
    if (ans.first==0) ans.second=1;
    if (ans.first==0) ans.second=1;
    cout<<ans.first<<" "<<ans.second;
    return 0;
}