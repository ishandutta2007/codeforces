#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define mp make_pair
#define pii pair<int,int>
#define ll long long
using namespace std;
const int N=11000;
const int Inf=1e8;
const int maxn=1e7;
struct edge{
    int u,c,nxt;  
}e[5000000];
int cnt,head[N],vis[N],s=N-1,t=N-2;
void addedge(int u,int v,int c){
    e[cnt]=(edge){v,c,head[u]},head[u]=cnt++;
    e[cnt]=(edge){u,0,head[v]},head[v]=cnt++;
}
bool bfs(){
    memset(vis,-1,sizeof vis);
    queue<int> q;
    q.push(s);
    vis[s]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=head[u];~i;i=e[i].nxt){
            int w=e[i].u;
            if(vis[w]==-1&&e[i].c>0){
                vis[w]=vis[u]+1;
                q.push(w);
            }
        }
    }
    return vis[t]!=-1;
}
ll findf(int x,int flow){
    if(x==t)return (ll)flow;
    ll res=0;
    for(int i=head[x];~i;i=e[i].nxt){
        int w=e[i].u;
        if(vis[w]==vis[x]+1&&e[i].c>0){
            int ff=findf(w,min(e[i].c,flow));
            if(!ff)continue;
         //   cout<<x<<' '<<ff<<"??\n"; 
            e[i].c-=ff;
            e[i^1].c+=ff;
            res+=ff;
            flow-=ff; 
        }
    }
    if(!res)vis[x]=-1;
    return res;
}
ll ans;
void dinic(){
    while(bfs())ans+=findf(s,Inf);
}
map<pii,int> id;
int a[N],b[N],c[N],_,l[N],r[N];
int getid(pii x){
    if(id.count(x))return id[x];
    return id[x]=++_;
}
int cal(const int &i,const int &x){
    return a[i]*x*x+b[i]*x+c[i];
}
int main(){
    memset(head,-1,sizeof head);
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,n+1){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    }
    rep(i,1,n+1){
        scanf("%d%d",&l[i],&r[i]);
        addedge(s,getid(mp(i,l[i])),Inf);
        rep(j,l[i],r[i])addedge(getid(mp(i,j)),getid(mp(i,j+1)),maxn-cal(i,j));
        addedge(getid(mp(i,r[i])),t,maxn-cal(i,r[i]));
    }
    rep(i,0,m){
        int u,v,d;
        scanf("%d%d%d",&u,&v,&d);
        rep(j,l[u],r[u]+1){
            int k=j-d;
            if(k>r[v]){
                addedge(getid(mp(u,j)),t,Inf);
                continue;
            }
            if(k<l[v])k=l[v];
            addedge(getid(mp(u,j)),getid(mp(v,k)),Inf);
        }
    }
    dinic();
    ans=1ll*maxn*n-ans;
    printf("%lld\n",ans);
} 
/*
3 6
0 1 0
0 -1 1
1 1 2
0 3
1 2
-100 100
1 2 3
2 3 3
3 1 3
2 1 3
3 2 3
1 3 3

1 0
0 1 0
0 3
*/