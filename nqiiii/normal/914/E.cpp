#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=200000,maxc=1<<20,lgn=18;
vector<int> g[maxn+10];
int n; bool in[maxn+10];
int sz[maxn+10],minv,minid; char s[maxn+10];
int dp[maxn+10];
vector<int> nd[maxc+10]; bool vis[maxc+10]; int used[maxc+10],uscnt;
ll val[maxn+10]; int f[maxn+10][lgn+1],dep[maxn+10];
void dfsgetfa(int x){
	dep[x]=dep[f[x][0]]+1;
	for(int i=1;i<=lgn;++i) f[x][i]=f[f[x][i-1]][i-1];
	for(int i=0;i<g[x].size();++i){
		int e=g[x][i]; if(e!=f[x][0]){
			f[e][0]=x; dfsgetfa(e);
		}
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=lgn,t=dep[x]-dep[y];i>=0;--i) if(t>>i&1) x=f[x][i];
	if(x==y) return x;
	for(int i=lgn;i>=0;--i) if(f[x][i]!=f[y][i]){
		x=f[x][i]; y=f[y][i];
	}
	return f[x][0];
}
void addin(int x,int y,ll v){
	val[x]+=v; val[y]+=v;
	int p=lca(x,y); val[p]-=v; val[f[p][0]]-=v;
}
void dfssz(int x){
	in[x]=1; sz[x]=1;
	for(int i=0;i<g[x].size();++i){
		int e=g[x][i]; if(in[e]) continue;
		dfssz(e); sz[x]+=sz[e];
	}
	in[x]=0;
}
void findrt(int x,int tot){
	in[x]=1; int maxsz=tot-sz[x];
	for(int i=0;i<g[x].size();++i){
		int e=g[x][i]; if(in[e]) continue;
		findrt(e,tot); maxsz=max(maxsz,sz[e]);
	}
	if(maxsz<minv) minv=maxsz,minid=x; in[x]=0;
}	
void getdp(int x){
	in[x]=1; dp[x]^=1<<s[x];
	for(int i=0;i<g[x].size();++i){
		int e=g[x][i]; if(in[e]) continue;
		dp[e]=dp[x]; getdp(e);
	}
	in[x]=0;
}
void adddp(int x){
	in[x]=1; nd[dp[x]].push_back(x);
	if(!vis[dp[x]]) vis[dp[x]]=1,used[++uscnt]=dp[x];
	for(int i=0;i<g[x].size();++i){
		int e=g[x][i]; if(in[e]) continue;
		adddp(e);
	}
	in[x]=0;
}
ll addans(int x,int v,int d){
	uscnt=0; adddp(x); ll pathnum=0;
	for(int i=1;i<=uscnt;++i){
		int ee=used[i],e=ee^(1<<s[v]); ll sz=nd[e].size();
		for(int j=0;j<20;++j) sz+=nd[e^(1<<j)].size();
		for(int j=0;j<nd[ee].size();++j){
			addin(nd[ee][j],v,d*sz);
		}
		pathnum+=nd[ee].size()*sz;
	}
	for(int i=1;i<=uscnt;++i){
		vis[used[i]]=0; nd[used[i]].clear();
	}
	uscnt=0; return pathnum;
}
void dfs(int x){
	dfssz(x); minv=0x3f3f3f3f; findrt(x,sz[x]); x=minid;
	dp[x]=0; getdp(x); ll pthnum=addans(x,x,1); in[x]=1;
	for(int i=0;i<g[x].size();++i){
		int e=g[x][i]; if(!in[e]) pthnum-=addans(e,x,-1);
	}
	addin(x,x,-pthnum/2);
	for(int i=0;i<g[x].size();++i){
		int e=g[x][i]; if(!in[e]) dfs(e);
	}
}
void dfsans(int x){
	for(int i=0;i<g[x].size();++i){
		int e=g[x][i]; if(e!=f[x][0]){
			dfsans(e); val[x]+=val[e];
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		int l,r; scanf("%d%d",&l,&r);
		g[l].push_back(r); g[r].push_back(l);
	}
	dfsgetfa(1);
	scanf("%s",s+1); for(int i=1;i<=n;++i) s[i]-='a';
	dfs(1); dfsans(1);
	for(int i=1;i<=n;++i) printf("%lld ",val[i]); return 0;
}