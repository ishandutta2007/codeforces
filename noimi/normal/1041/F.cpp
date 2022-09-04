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
void print(int x,int y){
    printf("%d %d\n",x,y);
    return;
}
main(){
    int n,x;cin>>n>>x;
    int a[N];
    rep(i,n)cin>>a[i];
    int m,y;cin>>m>>y;
    int b[N];
    rep(i,m)cin>>b[i];
    int ans=2;
    rep(iii,31){
        ll t=pow(2,iii);
        t*=2;
        map<int,int> ma;
        int ss=0;
        rep(i,n){
            ma[(a[i]%t+t)%t]++;
            ss=max(ss,ma[(a[i]%t+t)%t]);
        }
        rep(i,m){
            ma[(b[i]%t+t+t/2)%t]++;
            ss=max(ss,ma[(b[i]%t+t+t/2)%t]);
        }
        ans=max(ans,ss);
    }
    cout<<ans;
}