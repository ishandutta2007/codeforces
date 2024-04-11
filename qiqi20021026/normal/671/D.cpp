#include<bits/stdc++.h>

using namespace std;

#define N 800000
#define P(x,y) make_pair(x,y)

typedef pair<int,int> pii;

long long ans;
int n,m,x,y,z,tot,head[N],dep[N];
struct pq{
	int tag;
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	void ins(int x,int y){
		pq.push(P(x,y));
	}
}f[N];
struct edge{int v,nxt;}e[N];

void add(int x,int y){e[++tot].v=y; e[tot].nxt=head[x]; head[x]=tot;}

void merge(int x,int y){
	if (f[x].pq.size()<f[y].pq.size()){
		swap(f[x].tag,f[y].tag);
		swap(f[x].pq,f[y].pq);
	}
	while (!f[y].pq.empty()){
		int a=f[y].pq.top().first,b=f[y].pq.top().second;
		f[y].pq.pop();
		a+=f[y].tag-f[x].tag;
		f[x].pq.push(P(a,b));
	}
}

void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	for (int i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=fa){
			dfs(v,u);
			merge(u,v);
		}
	bool fl=0;
	while (!f[u].pq.empty()){
		int v=f[u].pq.top().second,c=f[u].pq.top().first;
		if (dep[v]<dep[u]){fl=1; ans+=c+f[u].tag; f[u].tag=-c; break;}
		f[u].pq.pop();
	}
	if (!fl){puts("-1"); exit(0);}
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;++i){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	f[1].ins(0,0);
	for (int i=1;i<=m;++i){
		scanf("%d%d%d",&x,&y,&z);
		f[x].ins(z,y);
	}
	dfs(1,0);
	printf("%lld\n",ans);
	
	return 0;
}