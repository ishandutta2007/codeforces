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
const int maxn=2.5e5+5;
int n,d[maxn];
ll fac[maxn];
poly solve(int l,int r){
	if(l==r) return {1,d[r]-(r!=1)};
	int mid=l+(r-l)/2;
	poly F=solve(l,mid),G=solve(mid+1,r);
	int len=1;
	while(len<r-l+2) len*=2;
	F.resize(len);
	G.resize(len);
	F=FFT(F,1);
	G=FFT(G,1);
	for(int i=0;i<len;i++) F[i]=F[i]*G[i]%mod;
	F=FFT(F,0);
	F.resize(r-l+2);
	return F;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<n;i++){
		d[readint()]++;
		d[readint()]++;
	}
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	poly F=solve(1,n);
	ll ans=0;
	for(int i=0;i<=n;i++)
		ans=(ans+F[i]*fac[n-i]%mod*(i%2==0?1:mod-1)%mod)%mod;
	printf("%lld\n",ans);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}