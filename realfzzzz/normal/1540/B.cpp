#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=200+5;
int n;
vector<int> g[maxn];
typedef long long ll;
const ll mod=1e9+7,inv2=5e8+4;
ll ksm(ll a,ll b){
	ll ans=1;
	while(b){
		if(b%2==1) ans=ans*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ans;
}
ll dp[maxn][maxn];
int fa[maxn],dep[maxn],size[maxn],hson[maxn];
void dfs1(int u){
	dep[u]=dep[fa[u]]+1;
	size[u]=1;
	hson[u]=0;
	for(int v:g[u]){
		if(v==fa[u]) continue;
		fa[v]=u;
		dfs1(v);
		size[u]+=size[v];
		if(size[v]>size[hson[u]]) hson[u]=v;
	}
}
int top[maxn];
void dfs2(int u){
	if(!hson[u]) return;
	top[hson[u]]=top[u];
	dfs2(hson[u]);
	for(int v:g[u]){
		if(v==fa[u]||v==hson[u]) continue;
		top[v]=v;
		dfs2(v);
	}
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]<dep[y]) swap(x,y);
	return y;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<n;i++){
		int x,y;
		x=readint();
		y=readint();
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=1;i<n;i++) dp[0][i]=1;
	for(int i=1;i<n;i++) for(int j=1;j<n;j++)
		dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod*inv2%mod;
	ll ans=0;
	for(int i=1;i<=n;i++){
		fa[i]=0;
		dfs1(i);
		top[i]=i;
		dfs2(i);
		for(int j=1;j<=n;j++) for(int k=1;k<j;k++){
			int l=lca(j,k);
			ans=(ans+dp[dep[j]-dep[l]][dep[k]-dep[l]])%mod;
		}
	}
	printf("%lld\n",ans*ksm(n,mod-2)%mod);
	return 0;
}