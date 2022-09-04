#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define ti3 tuple<int,int,int>
ll int MOD=998244353;
int INF=1e6;
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    ll int n,k;
    cin>>n>>k;
    vector<pii> v;
    rep(i,n){
        ll int a;
        cin>>a;
        v.push_back({a,i});
    }
    ll int c[110000];
    rep(i,n){
        cin>>c[i];
    }
    sort(v.begin(),v.end());
    ll int ans[110000]={};
    ll int temp=0;
    ll int d[11]={};
    rep(i,n){
        ll int temp=c[v[i].second];
        ans[v[i].second]+=temp;
        rep(j,k){
            ans[v[i].second]+=d[j];
        }
        rep(j,k){
            ll int ttemp=min(temp,d[j]);
            d[j]=max(d[j],temp);
            temp=ttemp;
        }
    }
    rep(i,n){
        cout<<ans[i]<<" ";
    }
    return 0;
}