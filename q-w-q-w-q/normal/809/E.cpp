#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int mod=1e9+7;
int n,a[200001],mp[200001],x,y;
vector<int> to[200001],t2[200001];
int fa[200001],d[200001],sz[200001],son[200001];
int top[200001],dfn[200001],cnt;
int f[200001],v[200001],p[200001],g[200001];
int st[200001],tp,s,sum,ans;
bool in[200001];
inline int add(int x,int y){
	return x+y<mod?x+y:x+y-mod;
}
inline int sub(int x,int y){
	return x<y?x+mod-y:x-y;
}
inline int power(int a,int n){
	int tp=1;
	while(n){
		if(n&1) tp=1ll*tp*a%mod;
		a=1ll*a*a%mod,n>>=1;
	}
	return tp;
}
inline bool cmp(int i,int j){
	return dfn[i]<dfn[j];
}
inline void dfs1(int i){
	sz[i]=1;
	dfn[i]=++cnt;
	for(int j:to[i]){
		if(j==fa[i]) continue;
		fa[j]=i,d[j]=d[i]+1;
		dfs1(j);
		sz[i]+=sz[j];
		if(sz[son[i]]<sz[j]) son[i]=j;
	}
}
inline void dfs2(int i){
	if(son[i]) top[son[i]]=top[i],dfs2(son[i]);
	for(int j:to[i]) if(j!=fa[i]&&j!=son[i]) top[j]=j,dfs2(j);
}
inline int lca(int x,int y){
	while(top[x]!=top[y]){
		if(d[top[x]]<d[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	return d[x]<d[y]?x:y;
}
inline int dfs(int i){
	g[i]=0;
	if(in[i]) g[i]=v[i];
	int ans=0;
	for(int j:t2[i]){
		ans=add(ans,dfs(j)),g[i]=add(g[i],g[j]);
		ans=(ans+1ll*(d[j]-d[i])*g[j]%mod*sub(sum,g[j]))%mod;
	}
	return ans;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",a+i),mp[a[i]]=i;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		to[x].push_back(y),to[y].push_back(x);
	}
	dfs1(1),top[1]=1,dfs2(1);
	f[1]=1;
	for(int i=2;i<=n;i++){
		if(f[i]) continue;
		f[i]=i-1;
		for(int j=2*i;j<=n;j+=i){
			if((j/i)%i) f[j]=f[i]*f[j/i];
			else f[j]=i*f[j/i];
		}
	}
	for(int i=1;i<=n;i++) v[i]=f[a[i]];
	for(int i=1;i<=n;i++) f[i]=1ll*i*power(f[i],mod-2)%mod;
	for(int i=1;i<=n;i++)
		for(int j=2*i;j<=n;j+=i)
			f[j]=sub(f[j],f[i]);
	for(int t=1;t<=n;t++){
		sum=s=0;
		for(int i=t;i<=n;i+=t) p[++s]=mp[i],sum=add(sum,v[mp[i]]),in[mp[i]]=1;
		sort(p+1,p+s+1,cmp);
		st[tp=1]=p[1],t2[p[1]].clear();
		for(int i=2;i<=s;i++){
			int x=lca(p[i],st[tp]),lt=0;
			while(d[st[tp]]>d[x]){
				if(lt) t2[st[tp]].push_back(lt);
				lt=st[tp--];
			}
			if(st[tp]!=x) st[++tp]=x,t2[x].clear();
			if(lt) t2[x].push_back(lt);
			st[++tp]=p[i],t2[p[i]].clear();
		}
		while(tp>1) t2[st[tp-1]].push_back(st[tp]),tp--;
		ans=(ans+1ll*dfs(st[1])*f[t])%mod;
		for(int i=1;i<=s;i++) in[p[i]]=0;
	}
	cout<<2ll*ans*power(1ll*n*(n-1)%mod,mod-2)%mod;
}