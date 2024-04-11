#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

bool chkmax(int &x,int y){return x<y?x=y,true:false;}
bool chkmin(int &x,int y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000007;
int n,D;
ll fac[3005],inv[3005],pre[3005],suf[3005],d[3005][3005];
vector<int> adj[3005];

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

void dfs(int u){
	if(adj[u].size()==0){
		for(int i=1;i<=n+1;i++) d[u][i]=i;
		return;
	}
	for(int i=1;i<=n+1;i++) d[u][i]=1;
	for(auto v:adj[u]){
		dfs(v);
		for(int i=1;i<=n+1;i++) d[u][i]=d[u][i]*d[v][i]%cys;
	}
	for(int i=1;i<=n+1;i++) d[u][i]=mod(d[u][i]+d[u][i-1]);
}

int main(){
	n=readint(); D=readint();
	for(int i=2;i<=n;i++) adj[readint()].push_back(i);
	dfs(1);
	fac[0]=inv[0]=1;
	for(int i=1;i<=n+1;i++) fac[i]=fac[i-1]*i%cys;
	inv[n+1]=qpow(fac[n+1],cys-2);
	for(int i=n;i>=1;i--) inv[i]=inv[i+1]*(i+1)%cys;
	pre[0]=suf[n+2]=1;
	for(int i=1;i<=n+1;i++) pre[i]=pre[i-1]*mod(D+cys-i)%cys;
	for(int i=n+1;i>=1;i--) suf[i]=suf[i+1]*mod(D+cys-i)%cys;
	ll ans=0;
	for(int i=1;i<=n+1;i++){
		ll tmp=d[1][i]*pre[i-1]%cys*suf[i+1]%cys,pw=1;
		for(int j=1;j<=n+1;j++) if(i!=j) pw=pw*mod(i+cys-j)%cys;
		ans=mod(ans+tmp*qpow(pw,cys-2)%cys);
	}
	printf("%lld\n",ans);
	return 0;
}