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
    ll int n,m;
    cin>>n>>m;
    ll int sum=0,t=0,a[N];
    rep2(i,1,n){
        cin>>a[i];
    }
    a[n+1]=m;
    rep2(i,1,n+1){
        if(i%2){
            sum+=a[i]-a[i-1];
        }
    }
    ll int sum2=0;
    rep2(i,1,n+1){
        if(i%2){
            sum2+=a[i]-a[i-1];
            t=max(t,m-a[i]-(sum-sum2)*2-1);
        }
    }
    cout<<sum+t;
    return 0;
}