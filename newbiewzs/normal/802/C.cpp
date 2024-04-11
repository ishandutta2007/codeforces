#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define vi vector<int>
#define vl vector<long long>
#define ci ios::sync_with_stdio(false)
//#define int long long
using namespace std;
typedef long long ll;
const int N=5e4+55;
int n,m,s,t,x,y,z,w,q[N],c[N];
struct node{
	int next,to,dis,val;
}a[N*2];
int head[N],cnt=1;
void link(int e,int r,int t,int w){
	a[++cnt].next=head[e];
	a[cnt].to=r;
	a[cnt].dis=t;
	a[cnt].val=w;
	head[e]=cnt;
}
void add(int e,int r,int t,int v){
	link(e,r,t,v);
	link(r,e,0,-v);
}
int dis[N],summ,maxx;
int pd[N];
bool vis[N];
bool spfa(){
	queue<int>q;
	for(int i=s;i<=t;i++){
		dis[i]=1e9+7;
	}
	q.push(s);
	dis[s]=0;
	while(q.size()){
		int u=q.front();
		pd[u]=0;
		q.pop();
		for(int i=head[u];i;i=a[i].next){
			if(dis[a[i].to]>dis[u]+a[i].val && a[i].dis){
				dis[a[i].to]=dis[u]+a[i].val;
				if(!pd[a[i].to]){
					q.push(a[i].to);
					pd[a[i].to]=1;
				}
			}
		}
	}
	return (dis[t]<1e9);
}
int ans=0;
int dfs(int u,int flow){
	if(u==t || !flow)return flow;
	int s=0;
	if(u==3){
		new char;
	}
	vis[u]=1;
	for(int i=head[u];i;i=a[i].next){
		if(dis[a[i].to]==dis[u]+a[i].val and a[i].dis and !vis[a[i].to]){
			int w=dfs(a[i].to,min(flow,a[i].dis));
			a[i].dis-=w;
			a[i^1].dis+=w;
			flow-=w;
			s+=w;
			ans+=(w*a[i].val);
		}
	}
	return s;
}
void dinic(){
	
	while(spfa()){
		int gg=dfs(s,1e9);
		memset(vis,0,sizeof(vis));
	}
}
int pre[N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&q[i]);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	t=n+n+1;
	for(int i=1;i<=n;i++)add(i,i+n,1,0);
	for(int i=1;i<=n;i++)add(i+n,t,1,0);
	for(int i=1;i<=n;i++)add(s,i,1,c[q[i]]);
	for(int i=1;i<=n;i++){
		if(pre[q[i]]){
			add(i-1,pre[q[i]]+n,1,-c[q[i]]);
		}
		pre[q[i]]=i;
	}
	for(int i=1;i<n;i++){
		add(i,i+1,m-1,0);
	}
	dinic();
	cout<<ans;
	return 0;
}