#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e3+5;
int n;
vector<int> g[maxn];
ll p;
ll ksm(ll a,ll b){
	ll s=1;
	while(b){
		if(b%2==1) s=s*a%p;
		a=a*a%p;
		b/=2;
	}
	return s;
}
ll fac[maxn],ifac[maxn];
ll C(int n,int m){
	return fac[n]*ifac[m]%p*ifac[n-m]%p;
}
ll f[maxn][maxn],s[maxn][maxn],s1[maxn][maxn],s2[maxn][maxn];
void dfs(int u,int fa){
	for(int i=1;i<=n;i++) f[u][i]=1;
	for(int v:g[u]) if(v!=fa){
		dfs(v,u);
		for(int i=1;i<=n;i++) f[u][i]=f[u][i]*s[v][i]%p;
	}
	if(u!=1){
		for(int i=1;i<=n;i++) s1[0][i]=1;
		for(int i=1;i<=(int)g[u].size();i++){
			int v=g[u][i-1];
			if(v==fa) for(int j=1;j<=n;j++) s1[i][j]=s1[i-1][j];
			else for(int j=1;j<=n;j++) s1[i][j]=s1[i-1][j]*s[v][j]%p;
		}
		for(int i=1;i<=n;i++) s2[g[u].size()][i]=1;
		for(int i=(int)g[u].size()-1;i>=0;i--){
			int v=g[u][i];
			if(v==fa) for(int j=1;j<=n;j++) s2[i][j]=s2[i+1][j];
			else for(int j=1;j<=n;j++) s2[i][j]=s2[i+1][j]*s[v][j]%p;
		}
		for(int i=0;i<(int)g[u].size();i++){
			int v=g[u][i];
			if(v==fa) continue;
			ll res=0;
			for(int j=1;j<=n;j++){
				f[u][j]=(f[u][j]+f[v][j]*res%p)%p;
				res=(res+s1[i][j]*s2[i+1][j]%p)%p;
			}
		}
	}
	for(int i=1;i<=n;i++) s[u][i]=(s[u][i-1]+f[u][i])%p;
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	p=read();
	for(int i=1;i<n;i++){
		int u,v;
		u=read();
		v=read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%p;
	ifac[n]=ksm(fac[n],p-2);
	for(int i=n-1;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%p;
	dfs(1,0);
	for(int i=1;i<n;i++){
		ll ans=0;
		for(int j=1;j<=i;j++)
			ans=(ans+f[1][j]*C(i,j)%p*((i-j)%2==0?1:p-1)%p)%p;
		printf("%lld ",ans);
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}