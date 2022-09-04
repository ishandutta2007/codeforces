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
ll MOD=1e9+7;
#define INF 2*1e9
#define N 310000 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");


main(){
    ll int n;
    cin>>n;
    ll int a[N];
    rep(i,2*n){
        cin>>a[i];
    }
    sort(a,a+(2*n));
    ll m=(a[n-1]-a[0])*(a[2*n-1]-a[n]);
    rep2(i,1,n-1){
        m=min(m,(a[2*n-1]-a[0])*(a[i+n-1]-a[i]));
    }
    cout<<m;
    return 0;
}