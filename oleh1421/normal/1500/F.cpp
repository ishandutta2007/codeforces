//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=1000010;
const int mod=1000000007;
ll w[N];
ll diff[N];
ll ans[N];
ll h[N];


bool used[N];
int pr[N][2];
int type[N][2];
void solve(){
    int n;
    ll C;
    cin>>n>>C;
//    for (int i=1;i<=n-2;i++) cin>>w[i];
//    for (int i=1;i<=n;i++) h[i]=rand();
//    for (int i=2;i<=n;i++) cout<<h[i]-h[i-1]<<" ";
//    cout<<endl;
//
//    for (int i=1;i<=n-2;i++) {
//        w[i]=max({h[i],h[i+1],h[i+2]})-min({h[i],h[i+1],h[i+2]});
//        cout<<w[i]<<" ";
//    }
//    cout<<endl;
    for (int i=1;i<=n-2;i++){
        cin>>w[i];
    }
    for (int i=1;i<n;i++) {
        pr[i][0]=pr[i][1]=-1;
    }
    for (int i=n-2;i>=1;i--){
        ll L=0,R=w[i];
        for (int j=i+1;j<=n-1;j++){
            if (j==n-1 || (L<=w[j] && w[j]<=R)){
                pr[i][0]=j;
                type[i][0]=0;
                break;
            }
            if (w[j]<L) break;
            if (pr[j][1]!=-1){
                pr[i][0]=j;
                type[i][0]=1;
                break;
            }
            ll nwL=w[j]-R;
            ll nwR=w[j]-L;
            L=nwL;
            R=nwR;
        }
        if (pr[i][0]==-1) break;
        ///calc pr[i][1]
        ll cur=w[i];
        for (int j=i+1;j<=n-1;j++){
            if (j==n-1 || cur==w[j]){
                pr[i][1]=j;
                type[i][1]=0;
                break;
            }
            if (cur>w[j]) break;
            if (pr[j][1]!=-1){
                pr[i][1]=j;
                type[i][1]=1;
                break;
            }
            cur=w[j]-cur;
        }
    }
    if (pr[1][0]==-1){
        cout<<"NO"<<endl;
        return;
    }
    vector<pair<int,int> >v;
    int cur_i=1;
    int cur_t=0;
    while (cur_i<n-1){
        used[cur_i]=true;
        v.push_back({cur_i,cur_t});
        int nw_i=pr[cur_i][cur_t];
        int nw_t=type[cur_i][cur_t];
        cur_i=nw_i;
        cur_t=nw_t;
    }
    diff[v[0].first]=w[v[0].first];
    for (int i=1;i<v.size();i++){
        if (v[i].second==1){
            diff[v[i-1].first+1]=w[v[i-1].first];
            for (int j=v[i-1].first+2;j<=v[i].first;j++) diff[j]=w[j-1]-diff[j-1];
        } else if (v[i-1].second==1){
            diff[v[i-1].first+1]=w[v[i-1].first];
            for (int j=v[i-1].first+2;j<=v[i].first;j++) diff[j]=w[j-1]-diff[j-1];

        } else {
            diff[v[i].first]=w[v[i].first];
            for (int j=v[i].first-1;j>=v[i-1].first+1;j--){
                diff[j]=(w[j]-diff[j+1]);
            }
        }
    }
    diff[v.back().first+1]=w[v.back().first];
    for (int i=v.back().first+2;i<=n-1;i++){
        diff[i]=(w[i-1]-diff[i-1]);
    }
    ll mult=1;
    for (int i=1;i<=n-1;i++){
        diff[i]*=mult;
        if (used[i]) mult=-mult;
    }
    ans[1]=0ll;
    for (int i=1;i<n;i++){
        ans[i+1]=ans[i]+diff[i];
    }
    ll mn=0ll;
    for (int i=1;i<=n;++i) mn=min(mn,ans[i]);
    cout<<"YES\n";
    for (int i=1;i<=n;i++) cout<<ans[i]-mn<<" ";
    cout<<endl;

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}
/*

*/