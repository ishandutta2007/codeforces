#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#include<bitset>
#include<set>
#include<math.h>
//#include<unordered_map>
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
#define da(x) cout<<"sese:"<<x<<endl;
#define db(x,y) cout<<"???"<<x<<" "<<y<<endl;
#define dc(x,y,z) cout<<"!!!!:"<<x<<" "<<y<<" "<<z<<endl;
#define dd(x,y,z,w) cout<<"yiw:"<<x<<" "<<y<<" "<<z<<" "<<w<<endl;
//#define int long long
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int read(){
	char c=getchar();
	ll x=1,s=0;
	while(c<'0'||c>'9'){
	   if(c=='-')x=-1;c=getchar();
	}
	while(c>='0'&&c<='9'){
	   s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
const int N=50050;
const int inf=1e9;
int n,m,x,y,zh,id[N],bj[N],vis[N],f[N],g[N],siz[N],deep[N],fu[N],top[N],son[N],tot,st,s,t;
vi v[N],l[N],pre[N];
map<pii,int>ma;
void dfs(int u,int fa){
	bj[u]=++zh;
	deep[u]=deep[fa]+1;siz[u]=1;fu[u]=fa;
	for(int i=0;i<v[u].size();i++){
		if(v[u][i]==fa)continue;
	//	id[bj[]]=ma[mp(u,v[u][i])];
		dfs(v[u][i],u);
		id[bj[v[u][i]]]=ma[mp(u,v[u][i])];
		siz[u]+=siz[v[u][i]];
		if(siz[v[u][i]]>siz[son[u]])son[u]=v[u][i];
	}
}
void dfs1(int u,int fa){
	if(u==fa)vis[u]=++tot;
	l[vis[fa]].pb(bj[u]);
	top[u]=fa;
	if(son[u])dfs1(son[u],fa);
	for(int i=0;i<v[u].size();i++){
		if(top[v[u][i]])continue;
		dfs1(v[u][i],v[u][i]);
	}
}
struct node{
	int next,to,dis;
}a[N*50];
int head[N*50],cnt=1;
void add(int e,int r,int t){
	a[++cnt].next=head[e];
	a[cnt].to=r;
	a[cnt].dis=t;
	head[e]=cnt;
}
void link(int e,int r,int t){
	add(e,r,t);add(r,e,0);
//	db(e,r);
}
queue<int>q;
int dis[N*50],cur[N*50];
bool bfs(){
	memset(dis,0,sizeof(dis));
	q.push(s);dis[s]=1;
	while(q.size()){
		int u=q.front();q.pop();
		for(int i=head[u];i;i=a[i].next){
			if(!dis[a[i].to] and a[i].dis){
				dis[a[i].to]=dis[u]+1;
				q.push(a[i].to);
			}
		}
	}
	return (dis[t]>0);
}
int work(int u,int cost){
	if(u==t)return cost;
	int zs=0;
	for(int i=cur[u];i;i=a[i].next){
		cur[u]=i;
		if(dis[a[i].to]==dis[u]+1 and a[i].dis){
			int tmp=work(a[i].to,min(a[i].dis,cost));
			a[i].dis-=tmp;
			a[i^1].dis+=tmp;
			cost-=tmp;
			zs+=tmp;
		}
	}
	if(!zs)dis[u]=0;
	return zs;
}
void dinic(){
	int ans=0;
	while(bfs()){
		for(int i=s;i<=t;i++)cur[i]=head[i];
		ans+=work(s,inf);
	}
	printf("%d",ans);
}
int rt[N],ls[N*50],rs[N*50];
struct SegmentTree{
	#define mid ((ll+rr)>>1)
	void build(int &u,int ll,int rr,int x){
		if(ll>rr)return ;
		if(ll==rr){
			u=l[x][ll];return ;
		}
		u=++st;
		build(ls[u],ll,mid,x);
		build(rs[u],mid+1,rr,x);
		link(u,ls[u],inf);
		link(u,rs[u],inf);
	}
	void query(int u,int ll,int rr,int L,int R,int x){
		if(L>R)return ;
		if(L<=ll and R>=rr){
		//	db(x,u);
			link(x,u,inf);
			return ;
		}
		if(L<=mid)query(ls[u],ll,mid,L,R,x);
		if(R>mid)query(rs[u],mid+1,rr,L,R,x);
	}
}T;
int gg[N],tou,pd[N*50];
void solve(int u){
	pd[u]=1;
	for(int i=head[u];i;i=a[i].next){
		if(!pd[a[i].to] and a[i].dis)solve(a[i].to);
	}
}
int main(){
//	freopen("data.in","r",stdin);
	n=read();m=read();
	for(int i=1;i<n;i++){
		x=read();y=read();
		v[x].pb(y);
		v[y].pb(x);
		ma[mp(x,y)]=i;
		ma[mp(y,x)]=i;
	}
	zh=m;
	dfs(1,0);
	dfs1(1,1);
	st=n+m+1;
	
//	cout<<"0000";
	for(int i=1;i<=tot;i++){
		int pree=0;
	//	cout<<i<<" "<<"ses"<<endl;
	//	db(i);
	//	db(l[i].size());
		for(int k=0;k<l[i].size();k++){
			
			st++;
			link(st,l[i][k],inf);
//			db(st,l[i][k]);
			if(pree)link(st,pree,inf);
			pree=st;
			pre[i].pb(st);//db(k);
		}
		T.build(rt[i],1,l[i].size()-1,i);
	}
	t=st+10;s=0;
//	cout<<"111";
	for(int i=1;i<=m;i++)link(s,i,1);
	for(int i=1;i<=n;i++)link(m+i,t,1);
	for(int i=1;i<=m;i++){
		x=read();y=read();
		while(top[x]!=top[y]){
			if(deep[top[x]]<deep[top[y]])swap(x,y);
			int tmp=deep[x]-deep[top[x]];
			link(i,pre[vis[top[x]]][tmp],inf);
	//		db(x,pre[vis[top[x]]][tmp]);
			x=fu[top[x]];
		}
		if(deep[x]<deep[y])swap(x,y);
		T.query(rt[vis[top[x]]],1,l[vis[top[x]]].size()-1,deep[y]-deep[top[x]]+1,deep[x]-deep[top[x]],i);
	//	dd(top[x],vis[top[x]],deep[y]-deep[top[x]]+1,deep[x]-deep[top[x]]);
	}
//	cout<<"22222";
//	return 0;
	dinic();
	cout<<endl;
	solve(s);
	for(int i=1;i<=m;i++){
		if(!pd[i])gg[++tou]=i;
	}
	cout<<tou<<" ";
	for(int i=1;i<=tou;i++)printf("%d ",gg[i]);
	cout<<endl;
	tou=0;
//	for(int i=1;i<=n;i++)cout<<id[i]<<" ";
/*	for(int i=1;i<=n+m;i++)cout<<pd[i]<<" ";
	return 0;*/
	for(int i=1;i<=n;i++){
		if(pd[m+i]){
		//	cout<<id[i]<<endl;
			gg[++tou]=id[m+i];
		}
	}
	cout<<tou<<" ";
	for(int i=1;i<=tou;i++)printf("%d ",gg[i]);
/*	for(int i=head[t];i;i=a[i].next){
		if(a[i].dis)printf("%d ",a[i].to-m);
	}*/
	return 0;
}