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
using poly=vector<ll>;
vector<int> rev;
vector<ll> w,w2;
ll invn;
void init(int n){
	rev.resize(n);
	for(int i=1;i<n;i++) rev[i]=rev[i>>1]>>1|((i&1)?n>>1:0);
	w.resize(n);
	for(int i=1;i<n;i*=2){
		w[i]=1;
		ll wn=ksm(g,(mod-1)/(i*2));
		for(int j=1;j<i;j++) w[i+j]=w[i+j-1]*wn%mod;
	}
	w2.resize(n);
	for(int i=1;i<n;i*=2){
		w2[i]=1;
		ll wn=ksm(invg,(mod-1)/(i*2));
		for(int j=1;j<i;j++) w2[i+j]=w2[i+j-1]*wn%mod;
	}
	invn=ksm(n,mod-2);
}
poly FFT(poly F,bool flag){
	int n=F.size();
	for(int i=0;i<n;i++) if(i<rev[i]) swap(F[i],F[rev[i]]);
	for(int i=1;i<n;i*=2) for(int j=0;j<n;j+=i*2)
		for(int k=j;k<j+i;k++){
			ll t=F[k+i]*(flag?w[i+k-j]:w2[i+k-j])%mod;
			F[k+i]=(F[k]-t+mod)%mod;
			F[k]=(F[k]+t)%mod;
		}
	if(!flag) for(int i=0;i<n;i++) F[i]=F[i]*invn%mod;
	return F;
}
const int maxn=2e5+5,maxm=100+5;
int n,m;
char s[maxm];
ll fac[maxn],ifac[maxn];
ll C(int n,int m){
	return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
ll a01[maxn],a[maxm][maxn],b[maxn];
void solve1(int l,int r){
	if(l==r){
		if(r==1) a01[r]=1;
		else if(r<=m){
			a01[r]=0;
			for(int i=1;i<r;i++) a01[r]=(a01[r]+a[i][r]*a01[i]%mod*C(r-2,i-1)%mod)%mod;
		}
		else{
			a01[r]=a01[r]*fac[r-2]%mod;
			for(int i=1;i<=m;i++)
				a01[r]=(a01[r]+(a[i][r]-b[r-i+1]+mod)%mod*a01[i]%mod*C(r-2,i-1)%mod)%mod;
		}
		return;
	}
	int mid=l+(r-l)/2;
	solve1(l,mid);
	poly F(mid-l+1),G(r-l+1);
	for(int i=l;i<=mid;i++) F[i-l]=a01[i]*ifac[i-1]%mod;
	for(int i=1;i<=r-l;i++) G[i]=b[i+1]*ifac[i-1]%mod;
	int len=1;
	while(len<mid+r-l*2+1) len*=2;
	F.resize(len);
	G.resize(len);
	init(len);
	F=FFT(F,1);
	G=FFT(G,1);
	for(int i=0;i<len;i++) F[i]=F[i]*G[i]%mod;
	F=FFT(F,0);
	for(int i=mid+1;i<=r;i++) a01[i]=(a01[i]+F[i-l])%mod;
	solve1(mid+1,r);
}
ll a10[maxn];
void solve2(int l,int r){
	if(l==r){
		if(r==n) a10[r]=1;
		else a10[r]=a10[r]*fac[n-r-1]%mod;
		return;
	}
	int mid=l+(r-l)/2;
	solve2(mid+1,r);
	poly F(r-mid),G(r-l+1);
	for(int i=mid+1;i<=r;i++) F[r-i]=a10[i]*ifac[n-i]%mod;
	for(int i=1;i<=r-l;i++) G[i]=b[i+1]*ifac[i-1]%mod;
	int len=1;
	while(len<r*2-l-mid) len*=2;
	F.resize(len);
	G.resize(len);
	init(len);
	F=FFT(F,1);
	G=FFT(G,1);
	for(int i=0;i<len;i++) F[i]=F[i]*G[i]%mod;
	F=FFT(F,0);
	for(int i=l;i<=mid;i++) a10[i]=(a10[i]+F[r-i])%mod;
	solve2(l,mid);
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	scanf("%s",s+1);
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	ifac[n]=ksm(fac[n],mod-2);
	for(int i=n-1;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
	b[2]=b[3]=1;
	for(int i=4;i<=n;i++) b[i]=b[i-1]*2%mod;
	for(int i=m+1;i<=n;i++) a[m+1][i]=b[i-m];
	for(int i=m;i>0;i--){
		for(int j=i+2;j<=n;j++){
			if(s[i]=='<') a[i][j]=a[i+1][j];
			if(j>m+1||s[j-1]=='>') a[i][j]=(a[i][j]+a[i][j-1])%mod;
		}
		a[i][i+1]=s[i]=='>';
	}
	solve1(1,n);
	solve2(m+1,n);
	for(int i=m;i>0;i--){
		a[i][i+1]=s[i]=='<';
		for(int j=i+1;j<=n;j++) a10[i]=(a10[i]+a10[j]*a[i][j]%mod*C(n-i-1,n-j)%mod)%mod;
	}
	ll ans=0;
	for(int i=1;i<=n;i++) ans=(ans+a01[i]*a10[i]%mod*C(n-1,i-1)%mod)%mod;
	printf("%lld\n",ans);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}