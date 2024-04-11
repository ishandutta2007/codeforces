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
const int maxn=2e5+5;
int n,a[maxn],p[maxn];
vector<int> g[maxn];
int fa[maxn],dep[maxn],size[maxn],hson[maxn];
void dfs1(int u){
	dep[u]=dep[fa[u]]+1;
	size[u]=1;
	for(int v:g[u]){
		if(v==fa[u]) continue;
		fa[v]=u;
		dfs1(v);
		size[u]+=size[v];
		if(size[v]>size[hson[u]]) hson[u]=v;
	}
}
int cnt=0,pos[maxn],top[maxn];
void dfs2(int u){
	pos[u]=cnt++;
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
int mf[maxn];
vector<int> pr;
int mu[maxn],phi[maxn];
typedef long long ll;
const ll mod=1e9+7;
ll ksm(ll a,ll b){
	ll ans=1;
	while(b){
		if(b%2==1) ans=ans*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ans;
}
ll f[maxn];
vector<int> ch[maxn];
int w[maxn];
ll sum[maxn],res;
void dfs3(int u){
	sum[u]=w[u];
	ll s=0;
	for(int v:ch[u]){
		dfs3(v);
		s=(s+sum[u]*sum[v]%mod)%mod;
		sum[u]=(sum[u]+sum[v])%mod;
	}
	s=(s*2%mod+1ll*w[u]*w[u]%mod)%mod;
	res=(res-s*dep[u]%mod+mod)%mod;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<=n;i++) p[a[i]=readint()]=i;
	for(int i=1;i<n;i++){
		int x,y;
		x=readint();
		y=readint();
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs1(1);
	top[1]=1;
	dfs2(1);
	for(int i=2;i<=n;i++){
		if(!mf[i]) pr.push_back(i);
		for(int j=0;j<(int)pr.size()&&i*pr[j]<=n;j++){
			mf[i*pr[j]]=pr[j];
			if(i%pr[j]==0) break;
		}
	}
	mu[1]=phi[1]=1;
	for(int i=2;i<=n;i++)
		if(!mf[i]){
			mu[i]=-1;
			phi[i]=i-1;
		}
		else{
			if(i/mf[i]%mf[i]==0){
				mu[i]=0;
				phi[i]=mf[i]*phi[i/mf[i]];
			}
			else{
				mu[i]=mu[mf[i]]*mu[i/mf[i]];
				phi[i]=phi[mf[i]]*phi[i/mf[i]];
			}
		}
	for(int i=1;i<=n;i++){
		ll tmp=i*ksm(phi[i],mod-2)%mod;
		for(int j=1;i*j<=n;j++)
			f[i*j]=(f[i*j]+(mu[j]+mod)%mod*tmp%mod)%mod;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		vector<int> s;
		for(int j=1;i*j<=n;j++) s.push_back(p[i*j]);
		sort(s.begin(),s.end(),[](int a,int b){
			return pos[a]<pos[b];
		});
		for(int j=1;j<n/i;j++) s.push_back(lca(s[j],s[j-1]));
		sort(s.begin(),s.end(),[](int a,int b){
			return pos[a]<pos[b];
		});
		s.resize(unique(s.begin(),s.end())-s.begin());
		for(int j:s) vector<int>().swap(ch[j]);
		for(int j=1;j<(int)s.size();j++){
			int fa=lca(s[j],s[j-1]);
			ch[fa].push_back(s[j]);
		}
		for(int j:s) w[j]=a[j]%i==0?phi[a[j]]:0;
		ll s1=0,s2=0;
		for(int j:s){
			s1=(s1+w[j])%mod;
			s2=(s2+1ll*w[j]*dep[j]%mod)%mod;
		}
		res=s1*s2%mod;
		dfs3(s[0]);
		ans=(ans+res*f[i]%mod*2%mod)%mod;
	}
	printf("%lld\n",ans*ksm(1ll*n*(n-1)%mod,mod-2)%mod);
	return 0;
}