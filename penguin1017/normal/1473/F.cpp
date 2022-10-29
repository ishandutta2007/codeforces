#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long 
using namespace std;
const int N=3e4+9;
const int inf=1e9;
int a[N],b[N];
struct edge{
	int u,c,nxt;
}e[N<<2];
int head[N],vis[N],s,t,cnt;
void add(int u,int v,int c){
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
	//	cout<<u<<"check\n";
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
ll ans;
ll findf(int x,int flow){
	if(x==t)return (ll)flow;
	ll res=0;
	for(int i=head[x];~i;i=e[i].nxt){
		int w=e[i].u;
		if(vis[w]==vis[x]+1&&e[i].c){
			int ff=findf(w,min(e[i].c,flow));
			if(!ff)continue;
			e[i].c-=ff;e[i^1].c+=ff;
			res+=ff;
			flow-=ff;
			if(!flow)break;
		}
	}
	if(!res)vis[x]=-1;
	return res;
}
void dinic(){
	while(bfs())ans-=findf(s,inf);
}
int main(){
	memset(head,-1,sizeof head);
	int n;
	s=N-1,t=N-2;
	scanf("%d",&n);
	rep(i,1,n+1)scanf("%d",&a[i]); 
	rep(i,1,n+1){	
		scanf("%d",&b[i]);
		if(b[i]>0)add(s,i,b[i]);
		else add(i,t,-b[i]);
		ans+=max(b[i],0);
	}
	//cout<<ans<<"ans\n";
	rep(i,1,n+1){
		per(j,1,i){
			if(a[i]%a[j]==0){
				if(!vis[a[j]]){
					vis[a[j]]=1;
					add(i,j,inf);
				}
			}
		}
		rep(j,1,101)vis[j]=0;
	}
	dinic();
	printf("%lld\n",ans);
}