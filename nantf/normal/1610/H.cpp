#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=333333,mod=998244353;
#define MP make_pair
#define PB push_back
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,m,el,head[maxn],to[maxn],nxt[maxn],dep[maxn],fa[20][maxn],lft[maxn],rig[maxn],cnt,U[maxn],V[maxn],ans,b[maxn],sz[maxn];
vector<int> vec[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
inline void update(int p,int v){
	for(int i=p;i<=n;i+=i&-i) b[i]+=v;
}
inline int query(int p){
	int s=0;
	for(int i=p;i;i-=i&-i) s+=b[i];
	return s;
}
inline int query(int l,int r){
	return query(r)-query(l-1);
}
void dfs1(int u){
	lft[u]=++cnt;
	FOR(i,1,19) fa[i][u]=fa[i-1][fa[i-1][u]];
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		dfs1(v);
	}
	rig[u]=cnt;
}
void dfs2(int u){
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		dfs2(v);
		sz[u]+=sz[v];
	}
	bool flag=false;
	FOR(i,0,(int)vec[u].size()-1){
		int v=vec[u][i];
		if(query(lft[u],rig[u])==query(lft[v],rig[v])){flag=true;break;}
	}
	if(flag) update(lft[u],1),ans++,sz[u]++;
}
int main(){
	n=read();m=read();
	FOR(i,2,n) add(fa[0][i]=read(),i),dep[i]=dep[fa[0][i]]+1;
	dfs1(1);
	FOR(i,1,m){
		int x=read(),y=read();
		if(dep[x]>dep[y]) swap(x,y);
		U[i]=x;V[i]=y;
		if(lft[x]<=lft[y] && rig[x]>=lft[y]){
			if(fa[0][y]==x) return puts("-1"),0;
			int z=y;
			ROF(j,19,0) if(dep[fa[j][z]]>dep[x]) z=fa[j][z];
//			printf("z=%d\n",z);
			vec[z].PB(y);
		}
	}
	dfs2(1);
	FOR(i,1,m){
		int x=U[i],y=V[i];
		if(lft[x]<=lft[y] && rig[x]>=lft[y]) continue;
		if(sz[x]+sz[y]==ans){ans++;break;}
	}
	printf("%d\n",ans);
}