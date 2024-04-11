#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int nn,n,m,x,y,u,start,end,dist,tot,d[150030],t[150030],head[150030],q[150030][3];
bool p[150030],p1[150030],p2[150030];
struct edge{
	int v,next;
}e[300030];

void add(int x,int y){
	tot++;
	e[tot].v=y;
	e[tot].next=head[x];
	head[x]=tot;
}

int dfs(int u){
	int sum=0;
	if (t[u]==1) sum++;
	p[u]=1;
	for (int i=head[u];i;i=e[i].next){
		int v=e[i].v;
		if (!p[v]){
			p[v]=1;
			sum+=dfs(v);
		}
	}
	if (sum==0){
		t[u]=-1;
		nn--;
	}
		
	return sum;
}

void bfs(int x){
	int tt=0,w=1,dis=0;
	q[1][1]=x; q[1][2]=0;
	p1[x]=1; d[x]=0;
	while (tt<w){
		tt++;
		u=q[tt][1];
		dis=q[tt][2];
		for (int i=head[u];i;i=e[i].next){
			int v=e[i].v;
			if (t[v]!=-1 && p1[v]==0){
				p1[v]=1;
				w++;
				q[w][1]=v;
				q[w][2]=dis+1;
				d[v]=dis+1;
			}
		}
	}
	
	x=1;
	for (int i=2;i<=n;i++)
		if (d[i]>d[x]) x=i;
	start=x;
	
	tt=0; w=1; dis=0;
	q[1][1]=x; q[1][2]=0;
	p2[x]=1; d[x]=0;
	while (tt<w){
		tt++;
		u=q[tt][1];
		dis=q[tt][2];
		for (int i=head[u];i;i=e[i].next){
			int v=e[i].v;
			if (t[v]!=-1 && p2[v]==0){
				p2[v]=1;
				w++;
				q[w][1]=v;
				q[w][2]=dis+1;
				d[v]=dis+1;
			}
		}
	}
	
	dist=0;
	for (int i=1;i<=n;i++)
		if (t[i]!=-1 && dist<d[i]){
			dist=d[i];
			end=i;
		}
}
			
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for (int i=1;i<=m;i++){
		scanf("%d",&x);
		t[x]=1;
	}
	
	nn=n;
	for (int i=1;i<=n;i++)
		if (t[i]){
			u=i;
			dfs(u);
			break;
		}
	if (nn==1){
		printf("%d\n%d\n",u,0);
		return 0;
	}
	
	bfs(u);
	
	printf("%d\n%d\n",min(start,end),(nn-1)*2-dist);
	
	return 0;
}