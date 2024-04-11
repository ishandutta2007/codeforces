#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int NN=210;
const int N=2*NN*NN+2;
const int M=8*NN*NN;
const int inf=(int)1e9;
struct EDGE { int adj, w, next; } edge[M<<1];
int top=1, gh[N], nrl[N],S,T;
void addedge(int x, int y, int w) {
    edge[++top].adj = y;
    edge[top].w = w;
    edge[top].next = gh[x];
    gh[x] = top;
    edge[++top].adj = x;
    edge[top].w = 0;
    edge[top].next = gh[y];
    gh[y] = top;
}
int dist[N], q[N];
int bfs() {
    memset(dist, 0, sizeof(dist));
    q[1] = S; int head = 0, tail = 1; dist[S] = 1;
    while (head != tail) {
        int x = q[++head];
        for (int p=gh[x]; p; p=edge[p].next)
            if (edge[p].w && !dist[edge[p].adj]) {
                dist[edge[p].adj] = dist[x] + 1;
                q[++tail] = edge[p].adj;
            }
    }
    return dist[T];
}
int dinic(int x, int delta) {
    if (x==T) return delta;
    for (int& p=nrl[x]; p && delta; p=edge[p].next)
        if (edge[p].w && dist[x]+1 == dist[edge[p].adj]) {
            int dd = dinic(edge[p].adj, min(delta, edge[p].w));
            if (!dd) continue;
            edge[p].w -= dd;
            edge[p^1].w += dd;
            return dd;
        }
    return 0;
}
int work() {
    int ans = 0;
    while (bfs()) {
        memcpy(nrl, gh, sizeof(gh));
        int t; while (t = dinic(S, inf)) ans += t;
    }
    return ans;
}
char s[NN][NN];
int id[NN][NN][4],n,m,tot,ans;
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,n){scanf("%s",s[i]+1);rep(j,m)if(s[i][j]=='#')ans++;}
	rep(i,n)rep(j,m)if(s[i][j]=='#')
	{
		if(i>1&&s[i-1][j]=='#')id[i][j][0]=id[i-1][j][2]=++tot;
		if(j>1&&s[i][j-1]=='#')id[i][j][3]=id[i][j-1][1]=++tot;
	}
	S=++tot;T=++tot;
	rep(i,n)rep(j,m)
	{
		if(id[i][j][0])addedge(S,id[i][j][0],1);
		if(id[i][j][3])addedge(id[i][j][3],T,1);
		if(id[i][j][0]&&id[i][j][1])addedge(id[i][j][0],id[i][j][1],1);
		if(id[i][j][0]&&id[i][j][3])addedge(id[i][j][0],id[i][j][3],1);
		if(id[i][j][2]&&id[i][j][1])addedge(id[i][j][2],id[i][j][1],1);
		if(id[i][j][2]&&id[i][j][3])addedge(id[i][j][2],id[i][j][3],1);
	}
	printf("%d\n",ans-(tot-2-work()));
	return 0;
}