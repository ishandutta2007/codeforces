#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;

int mod(int x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

struct Graph{
	int n,k,tot;
	int v[8005],nxt[8005],rev[8005],h[4005];
	ll dv[8005][80],adv[8005][80],dp[4005][80],adp[4005][80],res[80];
	void addedge(int x,int y){
		v[++tot]=y; rev[tot]=tot+1; nxt[tot]=h[x]; h[x]=tot;
		v[++tot]=x; rev[tot]=tot-1; nxt[tot]=h[y]; h[y]=tot;
	}
	void solve(){
		for(int i=1;i<=n;i++){
			dp[i][0]=adp[i][0]=1;
			for(int p=h[i];p;p=nxt[p]) dv[p][0]=adv[p][0]=1;
		}
		res[0]+=n;
		for(int i=2;i<=k;i+=2){
			for(int j=1;j<=n;j++){
				dp[j][i]=adp[j][i]=0;
				for(int p=h[j];p;p=nxt[p]) dp[j][i]=mod(dp[j][i]+adv[p][i-2]);
				for(int l=2;l<=i;l+=2) adp[j][i]=mod(adp[j][i]+dp[j][l]*adp[j][i-l]%cys);
				res[i]=mod(res[i]+adp[j][i]);
			}
			for(int j=1;j<=n;j++){
				for(int p=h[j];p;p=nxt[p]){
					dv[p][i]=mod(dp[v[p]][i]+cys-adv[rev[p]][i-2]),adv[p][i]=0;
					for(int l=2;l<=i;l+=2) adv[p][i]=mod(adv[p][i]+dv[p][l]*adv[p][i-l]%cys);
				}
			}
		}
	}
}G1,G2;

ll fac[4005],inv[4005];

int main(){
	G1.n=readint(); G2.n=readint(); G1.k=G2.k=readint();
	fac[0]=inv[0]=1;
	for(int i=1;i<=G1.k;i++) fac[i]=fac[i-1]*i%cys;
	inv[G1.k]=qpow(fac[G1.k],cys-2);
	for(int i=G1.k-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%cys;
	for(int i=1;i<=G1.n-1;i++) G1.addedge(readint(),readint());
	for(int i=1;i<=G2.n-1;i++) G2.addedge(readint(),readint());
	G1.solve(); G2.solve();
	ll ans=0;
	for(int i=0;i<=G1.k;i++) ans=mod(ans+G1.res[i]*G2.res[G1.k-i]%cys*fac[G1.k]%cys*inv[i]%cys*inv[G1.k-i]%cys);
	cout<<ans<<endl;
	return 0;
}