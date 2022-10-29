#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ld double
#define pb push_back
#define vi vector<int>
using namespace std;
const ld Inf=1e18;
const int N=3e5+9;
ld ans=Inf;
ld x;
const ld eps=1e-10;
struct line{
	ld lx,rx,ly,ry,k;
	line(ld lx=0,ld ly=0,ld rx=0,ld ry=0,ld k=0):lx(lx),ly(ly),rx(rx),ry(ry),k(k){}
	ld cal(ld x){
		return ly+(x-lx)*k;
	}
}q[N]; 
struct cmp{
	bool operator ()(const int &a,const int &b){
		return q[a].cal(x)<q[b].cal(x);
	}
};
struct query{
	ld x;
	int id;
	query(ld x=0,int id=0):x(x),id(id){}
	bool operator < (const query &o) const {
		if(fabs(x-o.x)<eps)return id>o.id;
		return x<o.x;
	}
}que[N];
void upd(int idx,int idy){
	if(q[idx].lx>q[idy].lx)swap(idx,idy);
	if(q[idx].rx+eps<q[idy].lx)return;
	ld y=q[idx].cal(q[idy].lx);
	if(fabs(q[idx].k-q[idy].k)<eps){
		if(fabs(y-q[idy].ly)<eps)ans=min(ans,q[idy].lx);
		return;
	} 
	ld px=(q[idy].ly-y)/(q[idx].k-q[idy].k);
	if(px<-eps||px+q[idy].lx>min(q[idx].rx,q[idy].rx)+eps)return;
	ans=min(ans,px+q[idy].lx);
}
set<int,cmp> S;
void erase(int id){
	S.erase(id);
	set<int,cmp>::iterator pre,nxt;
	pre=nxt=S.lower_bound(id);
	if(pre!=S.begin()&&nxt!=S.end())upd(*(--pre),*nxt);
}
void insert(int id){
	set<int,cmp>::iterator pre,nxt;
	pre=nxt=S.lower_bound(id);
	if (pre!=S.begin())upd(*(--pre),id);
	if (nxt!=S.end())upd(*(nxt),id);
	S.insert(id);
}
void solve(const vector<line> &vec){
	int top=0;
	rep(i,0,vec.size()){
		q[i+1]=vec[i];
		que[++top]=query(q[i+1].lx,i+1);
		que[++top]=query(q[i+1].rx,-i-1);
	}
	S.clear();
	sort(que+1,que+top+1);
	rep(i,1,top+1){
		x=que[i].x;
		if (x+eps>=ans) break;
		if (que[i].id<0) erase(-que[i].id);
		else insert(que[i].id);
	}
}
vector<line> G[N];

vi g[N];
int sz[N],top[N],fa[N],dep[N];
void dfs(int u,int f){
	fa[u]=f;
	dep[u]=dep[f]+1;
	sz[u]=1;
	for(auto v:g[u]){
		if(v==f)continue;
		dfs(v,u);
		sz[u]+=sz[v];
	} 
}
void dfs2(int u,int tp){
	int p=0;
	top[u]=tp;
	for(auto v:g[u]){
		if(v==fa[u])continue;
		if(sz[v]>sz[p])p=v;
	}
	if(p)dfs2(p,tp);
	for(auto v:g[u]){
		if(v==fa[u]||v==p)continue;
		dfs2(v,v);
	}
}
int LCA(int u,int v){
	for(;top[u]!=top[v];u=fa[top[u]]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
	}
	if(dep[u]<dep[v])return u;
	return v;
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[LCA(x,y)];
}
void add(int u,int v,ld S,ld T,ld k){
	int L=LCA(u,v);
	for(;top[u]!=top[L];u=fa[top[u]]){
		int len=dep[u]-dep[top[u]]+1;
		G[top[u]].pb(line(S,len,S+1.0*len/k,0,-k));
		S+=1.0*len/k;
	}
	for(;top[v]!=top[L];v=fa[top[v]]){
		int len=dep[v]-dep[top[v]]+1;
		G[top[v]].pb(line(T-1.0*len/k,0,T,len,k));
		T-=1.0*len/k;
	}
	int px=dep[u]-dep[top[u]]+1;
	int py=dep[v]-dep[top[v]]+1;
	if (dep[u]>dep[v])G[top[u]].pb(line(S,px,T,py,-k));
	else G[top[u]].pb(line(S,px,T,py,k));
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v),g[v].pb(u);
	}
	dfs(1,0);
	dfs2(1,1);
	rep(i,0,m){
		int u,v,k,t;
		scanf("%d%d%d%d",&t,&k,&u,&v);
		add(u,v,t,t+1.0*dis(u,v)/k,k);
	}
	rep(i,1,n+1)if(top[i]==i)solve(G[i]);
	if(ans>1e6)return printf("-1"),0;
	printf("%.10lf\n",ans);
}