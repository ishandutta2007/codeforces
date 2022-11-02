#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#define int long long
using namespace std;
const int N=5e3+55;
int n,m,v[N],x[N],y[N],z[N],s,t,tot;
struct node{
	int next,to,dis;
}a[N*2*2];
int head[N*2],cnt=1,ans;
void add(int e,int r,int t){
	a[++cnt].next=head[e];
	a[cnt].to=r;
	a[cnt].dis=t;
	head[e]=cnt;
	a[++cnt].next=head[r];
	a[cnt].to=e;
	a[cnt].dis=0;
	head[r]=cnt;
}
int dis[N],cur[N];
bool bfs(){
	queue<int>q;
	for(int i=s;i<=t;i++)dis[i]=0;
	dis[s]=1;
	q.push(s);
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=a[i].next){
			if(!dis[a[i].to] and a[i].dis){
				dis[a[i].to]=dis[u]+1;
				q.push(a[i].to);
			}
		}
	}
	return (dis[t]>0);
}
int dfs(int u,int flow){
	if(u==t || !flow)return flow;
	int tem=0;
	for(int &i=cur[u];i;i=a[i].next){
		if(dis[a[i].to]==dis[u]+1 and a[i].dis){
			int g=dfs(a[i].to,min(flow,a[i].dis));
			a[i].dis-=g;
			a[i^1].dis+=g;
			flow-=g;
			tem+=g;
			if(!flow)break;
		}
	}
	return tem;
}
int dinic(){
	int ans=0;
	while(bfs()){
		for(int i=s;i<=t;i++)cur[i]=head[i];
		ans+=dfs(s,1e18+7);
	}
	return ans;
}
signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&v[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&x[i],&y[i],&z[i]);
	}
	s=0;
	t=n+m+1;
	for(int i=1;i<=n;i++){
		add(s,i,v[i]);
	}
	for(int i=1;i<=m;i++){
		add(i+n,t,z[i]);
		ans+=z[i];
		add(x[i],i+n,1e18+7);
		add(y[i],i+n,1e18+7);
	}
	cout<<ans-dinic();
	return 0;
}