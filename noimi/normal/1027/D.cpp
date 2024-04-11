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
#define N 220000
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");
int par[N],grade[N];
void init(int n){
    rep(i,n){
        par[i]=i;
        grade[i]=0;
    }
}
int root(int x){
    return par[x]==x?x:par[x]=root(par[x]);
}
bool same(int x,int y){
    return root(x)==root(y);
}
void unite(int x,int y){
    x=root(x); y=root(y);
    if(x==y)return;
    if(grade[x]<grade[y]){
        par[x]=y;
    }
    else{
        par[y]=x;
        if(grade[x]==grade[y]) grade[x]++;
    }
}
main(){
    int n;
    cin>>n;
    init(n+1);
    int c[N];
    rep2(i,1,n){
        scanf("%d",&c[i]);
    }
    int a[N];
    rep2(i,1,n){
        scanf("%d",&a[i]);
        unite(i,a[i]);
    }
    int used[N]={};
    int ans=0;
    rep2(i,1,n){
        if(root(i)!=i)continue;
        int t=i;
        while(!used[t]){
            used[t]++;
            t=a[t];
        }
        int m=c[t];
        while(used[t]!=2){
            used[t]++;
            t=a[t];
            m=min(m,c[t]);
        }
        ans+=m;
    }
    cout<<ans;
    return 0;
}