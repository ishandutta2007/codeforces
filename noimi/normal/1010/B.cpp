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
    int m,n;
    cin>>m>>n;
    int a[100]={};
    rep(i,n){
        printf("%d\n",i+1);
        fflush(stdout);
        int s;scanf("%d",&s);
        if(s==0) return 0;
        if(s==1) a[i]=1;
        else a[i]=-1;
    }
    int l=n,r=m;
    while(1){
        rep(i,n){
            printf("%d\n",(l+r)/2);
            fflush(stdout);
            int s;scanf("%d",&s);
            if(s==0) return 0;
            if(a[i]==-1) s*=-1;
            if(s==1){
                l=(l+r)/2+1;
            }
            else r=(l+r)/2;
        }
    }
    return 0;
}