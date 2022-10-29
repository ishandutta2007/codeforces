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
const int N=5e5+9;
const ll mod=998244353;
int n,m;
vi g[N];
namespace dsu{
	int fa[N],v[N];
	int find(int x){
		if(fa[x]==x)return x;
		int f=fa[x];
		fa[x]=find(f);
		v[x]^=v[f];
		return fa[x];
	}
	void build(){
		rep(i,1,n+1)fa[i]=i,v[i]=0;
	}
	void merge(int x,int y,int vv){
		int px=find(x),py=find(y);
		if(px==py){
			if(v[x]^v[y]^vv){
				printf("-1");
				exit(0);
			}
		} 
		else{
			fa[px]=py;
			v[px]=v[x]^v[y]^vv;
		}
	}
} 
namespace TR{
	int fa[N],S[N],SS[N],sz[N],top[N],dfn[N],pos[N],dep[N];
	void dfs(int u){
		sz[u]=1;
		for(auto v:g[u]){
			if(v==fa[u])continue;
			dep[v]=dep[u]+1,fa[v]=u;
			dfs(v);sz[u]+=sz[v];
		}
	}
	void dfs2(int u,int tp){
		top[u]=tp;dfn[u]=++*dfn;pos[*dfn]=u;
		int k=0;
		for(auto v:g[u]){
			if(v==fa[u])continue;
			if(sz[v]>sz[k])k=v;
		}
		if(k)dfs2(k,tp);
		for(auto v:g[u]){
			if(v==fa[u]||v==k)continue;
			dfs2(v,v);
		}
	}
	void build(){
		dfs(1);dfs2(1,1);
	}
	int LCA(int u,int v){
		for(;top[u]!=top[v];u=fa[top[u]]){
			if(dep[top[u]]<dep[top[v]])swap(u,v);
		}
		return dep[u]<dep[v]?u:v;
	}
	int jmp(int x,int f){
		for(;;){
			if(dep[top[x]]==dep[top[f]])return pos[dfn[f]+1];
			if(dep[top[x]]==dep[f]+1)return top[x];
			x=fa[top[x]];
		}
	}
	void cont(int u,int v){
		int f=LCA(u,v);
		++S[u],++S[v],S[f]-=2;
		if(u^f)++SS[u],--SS[u=jmp(u,f)];
		if(v^f)++SS[v],--SS[v=jmp(v,f)];
		if((u^f)&&(v^f))dsu::merge(u,v,1);
	}
	void build2(){
		per(i,1,n+1){
			int u=pos[i];
			S[fa[u]]+=S[u];
			SS[fa[u]]+=SS[u];
			if(SS[u])dsu::merge(u,fa[u],0);
		}
	}
}
int q[N],dp[N],v0[N],v1[N],T,vis[N],tag[N],c[N];
bool check(int K){
	per(i,1,n+1){
		int u=TR::pos[i],f=TR::fa[u];
		*q=0;++T;
		for(auto v:g[u]){
			if(v==f||!TR::S[v])continue;
			int x=dsu::find(v);
			if(vis[x]!=T)vis[x]=T,v0[x]=0,v1[x]=0,q[++*q]=x;
			if(!dsu::v[v])v0[x]=max(v0[x],dp[v]);
			else v1[x]=max(v1[x],dp[v]);
		} 
		int vl=0,vr=0;
		if(T==vis[dsu::fa[u]]){
			int x=dsu::fa[u];
			vl=v0[x],vr=v1[x];
			if(dsu::v[u])swap(vl,vr);
		}
		int vmn=0,vmx=0;
		rep(j,1,(*q)+1){
			if(dsu::fa[u]!=q[j]){
				if(v0[q[j]]>v1[q[j]])swap(v0[q[j]],v1[q[j]]);
				vmn=max(vmn,v0[q[j]]);
				vmx=max(vmx,v1[q[j]]);
			}
		}
		if(max(vmn,min(vl,vr))+max(vmx,max(vl,vr))>=K)return 0;
		dp[u]=(max(vmn,vl)+max(vmx,vr)>=K?max(vmx,vl):max(vmn,vl))+1;
	}
	return 1;
}
void construct(int K){
	rep(i,1,n+1){
		int u=TR::pos[i],f=TR::fa[u];
		*q=0;++T;
		for(auto v:g[u]){
			if(v==f||!TR::S[v])continue;
			int x=dsu::fa[v];
			if(vis[x]!=T)vis[x]=T,v0[x]=0,v1[x]=0,q[++*q]=x;
			if(!dsu::v[v])v0[x]=max(v0[x],dp[v]);
			else v1[x]=max(v1[x],dp[v]); 
		}
		rep(j,1,(*q)+1){
			c[q[j]]=tag[u];
			if(q[j]!=dsu::fa[u])c[q[j]]^=(v0[q[j]]>dp[u]-1||v1[q[j]]+dp[u]>K);
			else c[q[j]]^=dsu::v[u];
		}
		for(auto v:g[u]){
			if(v==f||!TR::S[v])continue;
			tag[v]=c[dsu::fa[v]]^dsu::v[v];
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v);g[v].pb(u);
	}
	TR::build();dsu::build();
	rep(i,0,m){
		int u,v;
		scanf("%d%d",&u,&v);
		TR::cont(u,v);
	}
	TR::build2();
	rep(i,1,n+1)dsu::find(i);
	int l=1,r=n;
	while(l<r){
		int mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	check(l);
	construct(l);
	printf("%d\n",l);
	rep(i,1,n+1)printf("%d ",!tag[i]?dp[i]:l+1-dp[i]);
}