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
ll MOD=998244353;
#define INF 2*1e9
#define N 15000100
#define MAX_V 900010
using namespace std;

int gcd(int x,int y){
    if(x==0)return y;
    return gcd(y%x,x);
}
main(){
    int n;
    cin>>n;
    int a[N];
    rep(i,n)scanf("%d",&a[i]);
    int g=a[0];
    rep(i,n)g=gcd(g,a[i]);
    int t[N]={};
    rep(i,n){
        a[i]/=g;
        t[a[i]]++;
    }
    if(t[1]==n){cout<<-1;return 0;}
    bool prime[N]={};
    int ans=1;
    rep2(i,2,15000000){
        if(prime[i]==0){
            int s=0;
            for(int j=i;j<=15000000;j+=i){
                prime[j]=1;
                s+=t[j];
            }
            ans=max(s,ans);
        }
    }
    cout<<n-ans;
}