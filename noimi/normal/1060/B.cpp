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
#define N 1000010
#define MAX_V 900010
#define vec vector<int>
using namespace std;

void print(ll x){
    printf("%lld",&x);return;
}

int sum(ll n){
    int res=0;
    while(n){
        res+=n%10;
        n/=10;
    }
    return res;
}
main(){
    ll n;
    cin>>n;
    ll t=1;
    while(t*10<=n){
        t*=10;
    }
    cout<<sum(t-1)+sum(n+1-t);
}