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
    int a[11],b[11]={};
    int n,m;
    cin>>n>>m;
    rep(i,n){
        cin>>a[i];
    }
    rep(i,m){
        int t;
        cin>>t;
        b[t]=1;
    }
    rep(i,n){
        if(b[a[i]]) cout<<a[i]<<" ";
    }
    return 0;
}