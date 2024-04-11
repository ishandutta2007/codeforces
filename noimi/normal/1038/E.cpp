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
    int n;cin>>n;
    vector<int> G[5][5];
    init(5);
    int num[5]={};
    int m=INF;
    int ans=0;
    pair<int,pii> p[200];
    rep(i,n){
        int a,b,v;
        cin>>a>>v>>b;
        G[min(a,b)][max(a,b)].pb(v);
        p[i]={v,{a,b}};
        unite(a,b);
        num[a]++;num[b]++;
        m=min(m,v);
        ans+=v;
    }
    int t=0;
    rep2(i,1,4){
        if(root(i)==i)t++;
    }
    if(t==1){
        int flag=1;
        rep2(i,1,4){
            flag=flag&(num[i]%2);
        }
        if(flag){
            int M=0;
            rep(i,n){
                if(p[i].second.first==p[i].second.second)continue;
                init(5);
                rep(j,n){
                    if(i==j) continue;
                    unite(p[j].second.first,p[j].second.second);              
                }
                int tt=0;
                rep2(j,1,4)if(root(j)==j)tt++;
                if(tt==1){
                    M=max(M,ans-p[i].first);
                }
                else{
                    int sum[5]={};
                    rep(j,n){
                        if(i==j)continue;
                        sum[root(p[j].second.first)]+=p[j].first;
                    }
                    int an=0;
                    rep2(ii,1,4)an=max(an,sum[ii]);
                    M=max(M,an);
                    
                }
            }
            cout<<M;return 0;
        }
        else{
            cout<<ans;return 0;
        }
    }
    int sum[5]={};
    rep(i,n){
        sum[root(p[i].second.first)]+=p[i].first;
    }
    int M=0;
    rep2(i,1,4)M=max(M,sum[i]);
    cout<<M;
    return 0;

}