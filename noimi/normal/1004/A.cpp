#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define ti3 tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
ll int MOD=998244353;
#define N 300000
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    int n,d;
    cin>>n>>d;
    int a[110];
    rep(i,n){
        cin>>a[i];
    }
    int ans=2;
    rep(i,n-1){
        if(a[i+1]-a[i]==d*2) ans++;
        else if(a[i+1]-a[i]>2*d) ans+=2;
    }
    cout<<ans;
    return 0;
}