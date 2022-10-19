#include<bits/stdc++.h>

using namespace std;

#define N 12000
#define M (N<<3)
#define INF 0x3f3f3f3f

int n,m,a[N],b[N],A[N],B[N],d[N],pos[N];

int head[N],iter[N],lvl[N],tot;
struct edge{int v,c,r,lab,nxt;}e[M];
int add(int x,int y,int c,int lab=0){
    e[++tot].v=y; e[tot].c=c; e[tot].lab=lab; e[tot].r=tot+1; e[tot].nxt=head[x]; head[x]=tot;
    e[++tot].v=x; e[tot].c=0; e[tot].lab=0; e[tot].r=tot-1; e[tot].nxt=head[y]; head[y]=tot;
    return tot-1;
}
void bfs(int s){
    memset(lvl,-1,sizeof lvl);
    queue<int> q; lvl[s]=0; q.push(s);
    while (!q.empty()){
        int u=q.front(); q.pop();
        for (int i=head[u],v;i;i=e[i].nxt){
            if (e[i].c&&lvl[v=e[i].v]<0){
                lvl[v]=lvl[u]+1;
                q.push(v);
            }
        }
    }
}
int dfs(int u,int ff,int t){
    if (u==t) return ff;
    for (int &i=iter[u],v;i;i=e[i].nxt){
        if (e[i].c&&lvl[v=e[i].v]>lvl[u]){
            int d=dfs(v,min(ff,e[i].c),t);
            if (d){
                e[i].c-=d; e[e[i].r].c+=d;
                return d;
            }
        }
    }
    return 0;
}
int dinic(int s,int t){
    int flow=0;
    while (1){
        bfs(s);
        if (lvl[t]<0) break;
        memcpy(iter,head,sizeof iter);
        for (int ff=dfs(s,INF,t);ff;ff=dfs(s,INF,t)) flow+=ff;
    }
    return flow;
}

int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i) cin>>a[i];
    for (int i=1;i<=n;++i) cin>>b[i];
    for (int i=1;i<=m;++i){
        cin>>A[i]>>B[i];
        ++d[A[i]]; --d[B[i]];
        pos[i]=add(A[i],B[i],1,i);
    }
    int s=n+1,t=n+2,ss=n+3,tt=n+4;
    add(t,s,INF);
    int extra=0;
    for (int i=1;i<=n;++i){
        if (a[i]==0){
            add(s,i,INF);
            add(i,t,INF);
        }
        else{
            if ((d[i]-b[i])&1){
                cout<<"NO\n";
                exit(0);
            }
            if (d[i]>b[i]){
                extra+=(d[i]-b[i])/2;
                add(ss,i,(d[i]-b[i])/2);
                add(s,tt,(d[i]-b[i])/2);
            }
            else{
                extra+=(b[i]-d[i])/2;
                add(i,tt,(b[i]-d[i])/2);
                add(ss,t,(b[i]-d[i])/2);
            }
        }
    }
    if (dinic(ss,tt)==extra){
        cout<<"YES\n";
        for (int i=1;i<=m;++i){
            if (e[pos[i]].c==0){
                cout<<A[i]<<' '<<B[i]<<'\n';
            }
            else{
                cout<<B[i]<<' '<<A[i]<<'\n';
            }
        }
    }
    else{
        cout<<"NO\n";
    }

    return 0;
}