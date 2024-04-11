#include<bits/stdc++.h>
using namespace std;
const int MAXN=505;
const int MAXM=2005;
const int INF=0x3f3f3f3f;
int N, M, S, T, lnk[MAXN], flow;
int dis[MAXN], sum, cost;
struct Edge { int nxt, v, w, c; } e[MAXM << 1 | 1];
bool vis[MAXN];
void addEdge(int u, int v, int w, int c) {
    e[M] = (Edge){lnk[u], v, w, c}; lnk[u] = M++;
    e[M] = (Edge){lnk[v], u, 0, -c}; lnk[v] = M++;
}
bool SPFA() {
    int L = 0, R = 0; static int que[MAXN];
    for(int i=0;i<N;i++)
        dis[i]=INF,vis[i]=0;
    dis[T] = 0, vis[T] = 1, que[R++] = T;
    while(L != R) {
        int u = que[L++]; vis[u] = 0;
        L == MAXN && (L = 0);
        for(int it = lnk[u]; it != -1; it = e[it].nxt) {
            if(!e[it ^ 1].w) continue;
            int v = e[it].v, tp = dis[u] + e[it ^ 1].c;
            if(tp < dis[v]) {
                dis[v] = tp;
                if(!vis[v]) {
                    que[R++] = v; vis[v] = 1;
                    R == MAXN && (R = 0);
                }
            }
        }
    }
    if(dis[S] == INF) return 0;
    for(int u = 0; u < N; ++u)
        for(int it = lnk[u]; it != -1; it = e[it].nxt)
            e[it].c += dis[e[it].v] - dis[u];
    return sum += dis[S], 1;
}
bool Dijkstra() {
    priority_queue<pair<int, int> > Q;
    for(int i=0;i<N;i++)
        dis[i]=INF,vis[i]=0;
    dis[T] = 0; Q.push(make_pair(-dis[T], T));
    while(!Q.empty()) {
        int u = Q.top().second; Q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int it = lnk[u]; it != -1; it = e[it].nxt) {
            if(!e[it ^ 1].w) continue;
            int v = e[it].v;
            int tp = dis[u] + e[it ^ 1].c;
            if(tp < dis[v]) {
                dis[v] = tp;
                Q.push(make_pair(-dis[v], v));
            }
        }
    }
    if(dis[S] == INF) return 0;
    for(int u = 0; u < N; ++u)
        for(int it = lnk[u]; it != -1; it = e[it].nxt)
            e[it].c += dis[e[it].v] - dis[u];
    return sum += dis[S], 1;
}
int dfs(int u, int upp) {
    if(u == T) return upp;
    vis[u] = 1;
    int ret = 0, tmp;
    for(int it = lnk[u]; it != -1; it = e[it].nxt)
        if(!e[it].c && !vis[e[it].v] && e[it].w
        && (tmp = dfs(e[it].v, min(upp - ret, e[it].w))) > 0) {
            e[it].w -= tmp; e[it ^ 1].w += tmp;
            if((ret += tmp) == upp)
                break;
        }
    return ret;
}
void minCost(int upp = ~0u >> 1) {
    SPFA();
    do while(upp > 0) {
        memset(vis, 0, N * sizeof(bool));
        int adt = dfs(S, upp);
        if(!adt) break;
        upp -= adt; flow += adt;
        cost += adt * sum;
    } while(Dijkstra());
}

char col[MAXN];
int tot[MAXN],idx[MAXN];
int main()
{
    int n1,n2,m,r,b;
    scanf("%d%d%d%d%d",&n1,&n2,&m,&r,&b);
    int s=n1+n2,t=n1+n2+1;
    N=n1+n2+4,S=N-2,T=N-1;
    M=sum=flow=cost=0;
    memset(lnk, -1, N * sizeof(int));
    scanf("%s",col);
    for(int i=0;i<n1;i++)
    {
        if(col[i]=='R')
        {
            addEdge(s,i,INF,0);
            tot[i]++,tot[s]--;
        }
        else if(col[i]=='B')
        {
            addEdge(i,t,INF,0);
            tot[t]++,tot[i]--;
        }
        else
        {
            addEdge(s,i,INF,0);
            addEdge(i,t,INF,0);
        }
    }
    scanf("%s",col);
    for(int i=0;i<n2;i++)
    {
        if(col[i]=='B')
        {
            addEdge(s,n1+i,INF,0);
            tot[n1+i]++,tot[s]--;
        }
        else if(col[i]=='R')
        {
            addEdge(n1+i,t,INF,0);
            tot[t]++,tot[n1+i]--;
        }
        else
        {
            addEdge(s,n1+i,INF,0);
            addEdge(n1+i,t,INF,0);
        }
    }
    int need=0;
    for(int i=0;i<n1+n2+2;i++)
    {
        if(tot[i]>0)addEdge(S,i,tot[i],0),need+=tot[i];
        else if(tot[i]<0)addEdge(i,T,-tot[i],0);
    }
    addEdge(t,s,INF,0);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        u--,v--;
        idx[i<<1]=M;
        addEdge(u,n1+v,1,r);
        idx[i<<1|1]=M;
        addEdge(n1+v,u,1,b);
    }
    minCost();
    if(flow<need)return 0*printf("-1\n");
    printf("%d\n",cost);
    for(int i=0;i<m;i++)
    {
        if(e[idx[i<<1]].w==0)printf("R");
        else if(e[idx[i<<1|1]].w==0)printf("B");
        else printf("U");
    }
    return 0*printf("\n");
}