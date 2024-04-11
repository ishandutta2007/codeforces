#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll int MOD=1e9+7;
#define INF 2*1e9
#define N 310000 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    int n;
    cin>>n;
    int a[N];
    rep(i,n){
        cin>>a[i];
    }
    sort(a,a+n);
    int t=0;
    int ans=0;
    rep(i,n){
        int s=upper_bound(a+t,a+n,a[i])-a;
        if(a[s]>a[i]){
            ans++;t=s+1;
        }
    }
    cout<<ans;
}