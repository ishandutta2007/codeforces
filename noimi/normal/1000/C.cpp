#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define ti3 tuple<int,int,int>
ll int MOD=1e9+7;
#define N 600000
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    ll int n;
    vector<pair<ll int,ll int>> v;
    cin>>n;
    rep(i,n){
        ll int a,b;
        cin>>a>>b;
        v.push_back({a,0}); v.push_back({b,1});
    }
    sort(v.begin(),v.end());
    ll int ans[210000]={};
    ll int pre=v[0].first;
    ll int num=0;
    rep2(i,1,v.size()){
        if(num>=0)
        ans[num]+=v[i].first-v[i-1].first;
        if(v[i].second){
            if(num>=0)ans[num]++; num--; 
        }
        else{
            if(num>=0)ans[num]--; num++;
        }
    }
    rep(i,n){
        cout<<ans[i]<<" ";
    }
    return 0;
}