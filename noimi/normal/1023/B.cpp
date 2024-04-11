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
#define N 200000
using namespace std;
main(){
    ll n,k;
    cin>>n>>k;
    if(n>=k-1){
        cout<<(k-1)/2;return 0;
    }
    else if(2*n+1<k){
        cout<<0; return 0;
    }
    else{
        cout<<(n-(k/2));return 0;
    }
    return 0;
}