#include<bits/stdc++.h>
//#undef _GLIBCXX_HAVE_ICONV
//#include<bits/extc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pr(x) {for(auto v:x)cout<<v<<' ';cout<<#x<<endl;}
using namespace std;
//using namespace __gnu_pbds;
const int N=1<<21;
const int mod=998244353;
const int inf=1e9;
const int M=2000;
struct edge{
	int u,c,nxt;
}e[N];
int head[M],h[M],s,t,vis[M],cnt,ans; 
void addedge(int u,int v,int c){
	e[cnt]=(edge){v,c,head[u]},head[u]=cnt++;
	e[cnt]=(edge){u,0,head[v]},head[v]=cnt++;
}
bool bfs(){
	copy(head,head+M,h);
	memset(vis,-1,sizeof(vis));
	queue<int> q;
	q.push(s);
	vis[s]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=h[u];~i;i=e[i].nxt){
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
	for(int &i=h[x];~i;i=e[i].nxt){
		int w=e[i].u;
		if(vis[w]==vis[x]+1&&e[i].c>0){
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
void dinic(){while(bfs())ans+=findf(s,inf);}
int id[20][20];
int a[20],edge[20][20];
int main(){
	memset(head,-1,sizeof head);
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,0,m){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		edge[v][u]=1;
		a[u]+=w;
		a[v]-=w;
	}
	s=M-1,t=s-1;
	rep(i,1,n+1){
		int last=s;
		rep(j,1,n+1){
			int now=i*(n+10)+j;
			id[i][j]=cnt;
			addedge(last,now,a[i]*j+10000000);
			rep(k,1,n+1)if(edge[i][k])addedge(last,k*(n+10)+j,inf);
			last=now;
		}
		addedge(last,t,inf);
	}
	dinic();
	rep(i,1,n+1){
		int last=s;
		rep(j,1,n+1){
			int now=i*(n+10)+j;
			if(vis[last]>=0&&vis[now]<0){
				printf("%d ",j);
			}
			last=now;
		}
	}
}