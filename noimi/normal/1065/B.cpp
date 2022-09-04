#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll MOD=1e9+7;
#define INF 2*1e9
#define N 1100000
#define MAX_V 900010
#define vec vector<int>
using namespace std;

main(){
    ll n,m;
    cin>>n>>m;
    cout<<max((ll)0,n-2*m)<<" ";
    if(m==0)cout<<n;
    else
    for(ll i=1;i<=n;i++){
        if(i*(i-1)/2>=m){
            cout<<n-i;
            break;
        }
    }
    return 0;
}