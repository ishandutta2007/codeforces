#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
const int N=60+9;
const ll mod=998244353;
const int inf=1e9;
int head[N],vis[N],pre[N],s,t,cnt;
ll cost,flow[N],dis[N];
vector<pair<int,ll>> ans;
struct edge{
	ll u,c,d,nxt;
}e[(int)1e6];
void addedge(ll u,ll v,ll c,ll d){
	e[cnt]=(edge){v,c,d,head[u]},head[u]=cnt++;
	e[cnt]=(edge){u,0,-d,head[v]},head[v]=cnt++;
}
bool bfs(){
	queue<int> q;q.push(s);
	rep(i,0,t+1)dis[i]=inf,vis[i]=0;
	vis[s]=1;dis[s]=0;flow[s]=inf;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u];~i;i=e[i].nxt) {
			int w=e[i].u;
			ll d=e[i].d;
			if(e[i].c>0&&dis[w]>dis[u]+d){
				dis[w]=dis[u]+d;
				pre[w]=i;
				flow[w]=min(flow[u],e[i].c);
				if(!vis[w]){
					vis[w]=1;
					q.push(w);
				}
			}
		}
	}
	return dis[t]!=inf;
}
void costflow(){
	pre[s]=-1;
	int f=0;
	while(bfs()){
		for(int i=pre[t];~i;i=pre[e[i^1].u]){
			e[i].c-=flow[t];e[i^1].c+=flow[t];
		}
		cost+=dis[t]*flow[t];
		f+=flow[t];
		ans.pb({f,cost});
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof head);
	s=1,t=n;
	rep(i,0,m){
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		addedge(u,v,1,d); 
	}
	costflow();
	int q;
	scanf("%d",&q);
	while(q--){
		int x;
		scanf("%d",&x);
		double res=1e9;
		for(auto v:ans)res=min(res,1.*(v.se+x)/v.fi);
		printf("%.10lf\n",res);
	}
}