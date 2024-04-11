#include<bits/stdc++.h>
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl 
using namespace std; 
typedef long long ll;
typedef double db;

const int maxn=1e5+50;
const int maxw=1e9+50;
const int inf=0x3f3f3f3f;
int L,W,n;
ll ans;
int val[maxn];
int head[maxn],nxt[maxn<<1],to[maxn<<1],cost[maxn<<1],edge_tot;
void add_edge(int u,int v,int c){nxt[++edge_tot]=head[u];head[u]=edge_tot;to[edge_tot]=v;cost[edge_tot]=c;}
int root;
bool vis[maxn];
int mxson[maxn],siz[maxn];
void init(){mxson[0]=inf;}
void get_root(int u,int f,int sum){
	mxson[u]=0,siz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f||vis[v])continue;
		get_root(v,u,sum);
		siz[u]+=siz[v];
		if(siz[v]>mxson[u])mxson[u]=siz[v];
	}
	if(sum-siz[u]>mxson[u])mxson[u]=sum-siz[u];
	if(mxson[u]<mxson[root])root=u;
}
void get_simple(int u,int f,int w,int l){
	if(l&&w<=W&&l<=L)ans++;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f||vis[v])continue;
		get_simple(v,u,w+cost[i],l+1);
	}
}
struct node{
	int l,w;
	bool operator < (const node&_)const{
		return w<_.w;
	}
};
vector<node>tw;
void get_dis(int u,int f,int w,int l){
	if(l)tw.push_back((node){l,w});
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f||vis[v])continue;
		get_dis(v,u,w+cost[i],l+1);
	}
}
struct bit{
	int sum[maxn];
	int lowbit(int x){return x&(-x);}
	void clear(){memset(sum,0,sizeof(sum));}
	int query(int x){
		if(x<=0)return 0;
		int res=0;
		while(x){
			res+=sum[x];
			x-=lowbit(x);
		}
		return res;
	}
	void update(int x,int a){
		while(x<maxn){
			sum[x]+=a;
			x+=lowbit(x);
		}
	}
}bit;
ll calc(int x,int w,int l){
	//bug(x),bug(w),bug(l);
	ll res=0;
	tw.clear();
	get_dis(x,0,w,l);
	if(tw.size()<2)return res;
	sort(tw.begin(),tw.end());
	//puts("");
	//for(int i=0;i<tw.size();i++)bug(tw[i].l),debug(tw[i].w);
	bit.clear();
	for(int i=0;i<tw.size();i++)bit.update(tw[i].l,1);
	int s=0,t=tw.size()-1;
	while(s<t){
		bit.update(tw[s].l,-1);
		while(s<t&&tw[s].w+tw[t].w>W)bit.update(tw[t--].l,-1);
		if(s==t){bit.update(tw[s].l,1);break;}
		res+=bit.query(L-tw[s++].l);
	}
	//bug(s),debug(t);
	bit.update(tw[s].l,-1);
	//debug(res);
	return res;
}
void solve(int x=1,int sum=n){
	root=0;get_root(x,0,sum);vis[root]=1;
	//bug(root),bug(ans);
	get_simple(root,0,0,0);
	//debug(ans);
	ans+=calc(root,0,0);
	int root_sz=siz[root];
	for(int i=head[root];i;i=nxt[i]){
		int v=to[i];
		if(vis[v])continue;
		ans-=calc(v,cost[i],1);
		solve(v,siz[v]>root_sz?sum-root_sz:siz[v]);
	}
}
int main(){
	scanf("%d%d%d",&n,&L,&W);
	for(int i=2;i<=n;i++){
		int f,v;
		scanf("%d%d",&f,&v);
		add_edge(f,i,v),add_edge(i,f,v);
	}
	init();
	solve();
	printf("%lld\n",ans);
	return 0;
}