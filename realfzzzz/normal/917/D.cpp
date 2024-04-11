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
const int maxn=100+5;
int n;
vector<int> g[maxn];
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
int size[maxn];
ll f[2][maxn][maxn];
void dfs(int u,int fa){
	size[u]=1;
	f[0][u][1]=1;
	f[1][u][1]=n;
	for(int v:g[u]){
		if(v==fa) continue;
		dfs(v,u);
		vector<ll> tmp[2];
		tmp[0].resize(size[u]+size[v]+1);
		tmp[1].resize(size[u]+size[v]+1);
		for(int i=1;i<=size[u];i++) for(int j=1;j<=size[v];j++){
			tmp[0][i+j]=(tmp[0][i+j]+f[0][u][i]*f[1][v][j]%mod)%mod;
			tmp[1][i+j]=(tmp[1][i+j]+f[1][u][i]*f[1][v][j]%mod)%mod;
			tmp[0][i+j-1]=(tmp[0][i+j-1]+f[0][u][i]*f[0][v][j]%mod)%mod;
			tmp[1][i+j-1]=(tmp[1][i+j-1]+f[0][u][i]*f[1][v][j]%mod+f[1][u][i]*f[0][v][j]%mod)%mod;
		}
		size[u]+=size[v];
		for(int i=1;i<=size[u];i++){
			f[0][u][i]=tmp[0][i];
			f[1][u][i]=tmp[1][i];
		}
	}
}
ll fac[maxn],ifac[maxn];
ll C(int n,int m){
	return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<n;i++){
		int u,v;
		u=readint();
		v=readint();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	ifac[n]=ksm(fac[n],mod-2);
	for(int i=n-1;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
	ll inv=ksm(1ll*n*n%mod,mod-2);
	for(int i=0;i<n;i++){
		ll ans=0;
		for(int j=i;j<n;j++)
			ans=(ans+f[1][1][n-j]*inv%mod*C(j,i)%mod*((j-i)%2==0?1:mod-1)%mod)%mod;
		printf("%lld ",ans);
	}
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}