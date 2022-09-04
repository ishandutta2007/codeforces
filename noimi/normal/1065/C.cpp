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
#define N 400000
#define MAX_V 900010
#define vec vector<int>
using namespace std;

main(){
    ll n,k;cin>>n>>k;
    ll s[N];
    int m=INF;
    rep(i,n){
        s[0]++;
        int t;cin>>t;
        m=min(m,t);
        s[t+1]--;
    }
    ll ans=0;
    rep(i,300000){
        s[i+1]+=s[i];
    }
    for(int i=300000;i>m;i--){
        int temp=0;
        temp=s[i];
        while(i>m+1&&temp+s[i-1]<=k){
            i--;
            temp+=s[i];
        }
        ans++;
        if(temp==0)ans--;
    }
    cout<<ans;
    return 0;
}