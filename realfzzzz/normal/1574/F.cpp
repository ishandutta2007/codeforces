#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
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
const int maxn=3e5+5;
int n,m,k;
const ll mod=998244353,g=3,invg=332748118;
ll ksm(ll a,ll b){
	ll ans=1;
	while(b){
		if(b%2==1) ans=ans*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ans;
}
typedef vector<ll> poly;
poly FFT(poly F,bool flag){
	int n=F.size();
	vector<int> rev(n);
	for(int i=1;i<n;i++) rev[i]=rev[i>>1]>>1|(i&1?n>>1:0);
	for(int i=0;i<n;i++) if(i<rev[i]) swap(F[i],F[rev[i]]);
	for(int i=1;i<n;i*=2){
		ll wn=ksm(flag?g:invg,(mod-1)/(i*2));
		for(int j=0;j<n;j+=i*2){
			ll w=1;
			for(int k=j;k<j+i;k++){
				ll t=F[k+i]*w%mod;
				F[k+i]=(F[k]-t+mod)%mod;
				F[k]=(F[k]+t)%mod;
				w=w*wn%mod;
			}
		}
	}
	if(!flag){
		ll invn=ksm(n,mod-2);
		for(int i=0;i<n;i++) F[i]=F[i]*invn%mod;
	}
	return F;
}
poly Inv(poly F){
	int n=F.size();
	if(n==1) return {ksm(F[0],mod-2)};
	poly G=Inv(poly(F.begin(),F.begin()+(n+1)/2));
	int len=1;
	while(len<n*2-1) len*=2;
	F.resize(len);
	G.resize(len);
	F=FFT(F,1);
	G=FFT(G,1);
	for(int i=0;i<len;i++) F[i]=(2-F[i]*G[i]%mod+mod)%mod*G[i]%mod;
	F=FFT(F,0);
	F.resize(n);
	return F;
}
set<int> g1[maxn],g2[maxn];
bool vis[maxn];
void dfs(int u){
	vis[u]=1;
	for(int v:g1[u]) if(!vis[v]) dfs(v);
	for(int v:g2[u]) if(!vis[v]) dfs(v);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	k=readint();
	for(int i=1;i<=n;i++){
		int c=readint(),lst=0;
		while(c--){
			int a=readint();
			if(lst){
				g1[lst].insert(a);
				g2[a].insert(lst);
			}
			lst=a;
		}
	}
	for(int i=1;i<=k;i++)
		if(((int)g1[i].size()>1||(int)g2[i].size()>1)&&!vis[i]) dfs(i);
	poly F(m+1);
	for(int i=1;i<=k;i++) if(!vis[i]&&!g2[i].size()){
		int u=i,l=1;
		while(g1[u].size()){
			l++;
			u=*g1[u].begin();
		}
		if(l<=m) F[l]=(F[l]-1+mod)%mod;
	}
	F[0]=1;
	printf("%lld\n",Inv(F)[m]);
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}