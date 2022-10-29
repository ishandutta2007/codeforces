#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e5+50;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
int n;
ll ans;
int val[maxn];
int head[maxn],nxt[maxn<<1],to[maxn<<1],edge_tot;
void add_edge(int u,int v){nxt[++edge_tot]=head[u];head[u]=edge_tot;to[edge_tot]=v;}
int root;
bool vis[maxn];
int siz[maxn],mxson[maxn];
void ndc_init(){mxson[0]=inf;}
void add(ll &a,ll b){(a+=b)%=mod;}
void del(ll &a,ll b){(a-=b)%=mod;if(a<0)a+=mod;}
void mul(ll &a,ll b){a=a*b%mod;}
void get_root(int u,int f,int sum){
	siz[u]=1;mxson[u]=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(vis[v]||v==f)continue;
		get_root(v,u,sum);
		siz[u]+=siz[v];
		if(mxson[u]<siz[v])mxson[u]=siz[v];
	}
	if(mxson[u]<sum-siz[u])mxson[u]=sum-siz[u];
	if(mxson[u]<mxson[root])root=u;
}
ll ret[2];
void add(int u,int f,int dep,ll sum,int op){
	//printf("val=%d\n",val[u]);
	if(dep&1)add(sum,val[u]);
	else del(sum,val[u]);
	add(ret[1],op*sum);
	add(ret[0],op*(-sum));
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(vis[v]||v==f)continue;
		add(v,u,dep+1,sum,op);
	}
}
void calc(int u,int f,ll sum,int dep,int rot_val,int cnt){
	if(dep&1)add(ans,1ll*cnt*(sum-rot_val)%mod+ret[1]);
	else add(ans,1ll*cnt*(-sum+rot_val)%mod+ret[0]);
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(vis[v]||v==f)continue;
		ll res=sum;
		if(dep&1)del(res,val[v]);
		else add(res,val[v]);
		calc(v,u,res,dep+1,rot_val,cnt);
	}
}
void get_ans(int u,int f,int dep,ll sum){
	if(dep&1)add(sum,val[u]);
	else del(sum,val[u]);
	add(ans,sum);
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(vis[v]||v==f)continue;
		get_ans(v,u,dep+1,sum);
	}
}
void solve(int u=1,int sum=n){
	root=0;get_root(u,0,sum);
	vis[root]=1;
	get_ans(root,0,1,0);
	for(int i=head[root];i;i=nxt[i]){
		int v=to[i];
		if(vis[v])continue;
		add(v,root,1,0,1);
	}
	for(int i=head[root];i;i=nxt[i]){
		int v=to[i];
		if(vis[v])continue;
		add(v,root,1,0,-1);
		int cnt=0;
		if(siz[root]>siz[v])cnt=sum-siz[v];
		else cnt=siz[root];
		calc(v,root,val[v],1,val[root],cnt);
		add(v,root,1,0,1);
	}
	for(int i=head[root];i;i=nxt[i]){
		int v=to[i];
		if(vis[v])continue;
		add(v,root,1,0,-1);
	}
	int root_sz=siz[root];
	for(int i=head[root];i;i=nxt[i]){
		int v=to[i];
		if(vis[v])continue;
		solve(v,root_sz>siz[v]?siz[v]:sum-root_sz);
	}
}
int main(){
	ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&val[i]);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	ndc_init();
	solve();
	printf("%lld\n",(ans%mod+mod)%mod);
	return 0;
}