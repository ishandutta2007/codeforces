#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
#define pr(x) {for(auto v:x)cout<<v<<' ';cout<<#x<<endl;}
using namespace std;
const int N=200;
const ll mod=998244353;
const ll Inf=1e18;
const ll inf=1e18;
/*
inline int add(int a,const int &b){
	a+=b;
	if(a>=mod)a-=mod;
	return a;
}
inline int sub(int a,const int &b){
	a-=b;
	if(a<0)a+=mod;
	return a;
}
inline int mul(const int &a,const int &b){return 1ll*a*b%mod;}
int jie[N],inv[N];
ll quick(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
inline int C(int m,int n){
	if(n>m||m<0||n<0)return 0;
	return mul(mul(jie[m],inv[n]),inv[m-n]);
}
void pre(){
	inv[0]=inv[1]=1,jie[0]=1;
	rep(i,2,N)inv[i]=-1ll*mod/i*inv[mod%i]%mod+mod;
	rep(i,1,N)inv[i]=mul(inv[i],inv[i-1]),jie[i]=mul(jie[i-1],i);
}
*/
int head[N],vis[N],pre[N],s,t,cnt,dd[N];
ll cost,flow[N],dis[N];
struct edge{
	ll u,c,d,nxt;
}e[(int)1e6];
void addedge(ll u,ll v,ll c,ll d){
	e[cnt]=(edge){v,c,d,head[u]},head[u]=cnt++;
	e[cnt]=(edge){u,0,-d,head[v]},head[v]=cnt++;
}
void addlim(ll u,ll v,ll L,ll R,ll d){
	addedge(u,v,R-L,d);
	dd[u]-=L;dd[v]+=L;
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
	while(bfs()){
		for(int i=pre[t];~i;i=pre[e[i^1].u]){
			e[i].c-=flow[t];e[i^1].c+=flow[t];
		}
		cost+=dis[t]*flow[t];
	}
}
int n,m;
void solve(){
	addedge(n,1,inf,0);
	rep(i,1,N){
		if(dd[i]>0)addedge(s,i,dd[i],0);
		else if(dd[i]<0)addedge(i,t,-dd[i],0);
	}
	costflow();
}

int main(){
	//pre();
	memset(head,-1,sizeof head);
	scanf("%d%d",&n,&m);
	s=N-1,t=s-1;
	ll ans=0;
	rep(i,0,m){
		int u,v,c,f;
		scanf("%d%d%d%d",&u,&v,&c,&f);
		addlim(u,v,f,f,0);
		if(c>=f){
			addedge(u,v,c-f,1);
			addedge(u,v,Inf,2);
			addedge(v,u,f,1);
		}
		else{
			ans+=f-c;
			addedge(v,u,c,1);
			addedge(v,u,f-c,0);
			addedge(u,v,Inf,2);
		}
	} 
	solve();
	printf("%lld\n",ans+cost);
}