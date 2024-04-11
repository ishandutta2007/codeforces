#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node{
	int v; ll c;
	node *next,*rev;
}pool[1000005],*h[40005],*cur[40005];

int n,m,src,sink,tot=0,a[1000005],level[4000005],q[4000005];
ll ans;

void addedge(int u,int v,ll c){
	node *p=&pool[++tot],*q=&pool[++tot];
	p->v=v; p->c=c; p->next=h[u]; p->rev=q; h[u]=p;
	q->v=u; q->c=0; q->next=h[v]; q->rev=p; h[v]=q;
}

bool bfs(){
	memset(level,0,sizeof(level));
	int front=0,rear=0;
	level[src]=1,q[rear++]=src;
	while(front<rear){
		int t=q[front++];
		for(node *p=h[t];p;p=p->next){
			if(p->c>0&&!level[p->v]){
				level[p->v]=level[t]+1;
				q[rear++]=p->v;
				if(p->v==sink)
					return true;
			}
		}
	}
	return false;
}

ll dfs(int u,ll low){
	if(u==sink)
		return low;
	ll res=0;
	for(node *&p=cur[u];p;p=p->next){
		if(p->c>0&&level[p->v]==level[u]+1){
			ll flow=dfs(p->v,min(low,p->c));
			res+=flow; p->c-=flow; p->rev->c+=flow; low-=flow;
			if(low<=0)
				break;
		}
	}
	if(res==0) level[u]=0;
	return res;
}

ll dinic(){
	ll maxflow=0;
	while(bfs()){
		for(int i=src;i<=sink;i++)
			cur[i]=h[i];
		maxflow+=dfs(src,1ll<<60);
	}
	return maxflow;
}	

int main() {
    int u,v,w;
    scanf("%d%d",&n,&m); sink=n+m+1;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),addedge(i,sink,a[i]);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
		ans+=w; addedge(src,i+n,w); addedge(i+n,u,1ll<<60); addedge(i+n,v,1ll<<60);
	}
    printf("%lld",ans-dinic());
    return 0;
}