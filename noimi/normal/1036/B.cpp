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
#define N 600010
using namespace std;
int gcd(int x,int y){
    if(x==0)return y;
    return gcd(y%x,x);
}
main(){
    int q;
    cin>>q;
    rep(i,q){
        ll n,m,k;cin>>n>>m>>k;
        if(max(n,m)>k) {cout<<-1<<endl;continue;}
        if((n+m)%2) cout<<k-1<<endl;
        else {if((k-max(n,m))%2) cout<<k-2<<endl;
                else cout<<k<<endl;
        }
    }
    return 0;
}