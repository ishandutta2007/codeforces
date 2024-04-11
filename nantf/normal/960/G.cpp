#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
const int maxn=266666,mod=998244353,g=3;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,p,q,fac[maxn],invfac[maxn],inv[maxn],lim,l,rev[maxn],wn[maxn];
void init(int upr){
	for(lim=1,l=0;lim<upr;lim<<=1,l++);
	FOR(i,0,lim-1) rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
	for(int i=1;i<lim;i<<=1){
		wn[i]=1;
		int w=qpow(g,(mod-1)/(i<<1));
		FOR(k,1,i-1) wn[i+k]=1ll*wn[i+k-1]*w%mod;
	}
}
void dft(int *a){
	static ull b[maxn];
	FOR(i,0,lim-1) b[i]=a[rev[i]];
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=i<<1)
			FOR(k,0,i-1){
				ull x=b[j+k],y=b[i+j+k]*wn[i+k]%mod;
				b[j+k]=x+y;b[i+j+k]=x-y+mod;
			}
	FOR(i,0,lim-1) a[i]=b[i]%mod;
}
void idft(int *a){
	dft(a);
	reverse(a+1,a+lim);
	int linv=qpow(lim,mod-2);
	FOR(i,0,lim-1) a[i]=1ll*a[i]*linv%mod;
}
int f[maxn],a[maxn],b[maxn];
void work(int n){
	if(!n) return f[0]=1,void();
	if(n%2==1){
		work(n-1);
		ROF(i,n,1) f[i]=(f[i-1]+1ll*(n-1)*f[i])%mod;
		f[0]=0;
	}
	else{
		work(n/2);
		int m=n/2;
		init(2*m+1);
		FOR(i,0,m) a[i]=1ll*f[i]*fac[i]%mod;
		b[m]=1;
		ROF(i,m-1,0) b[i]=1ll*b[i+1]*m%mod;
		FOR(i,0,m) b[i]=1ll*b[i]*invfac[m-i]%mod;
		FOR(i,m+1,lim-1) a[i]=b[i]=0;
		dft(a);dft(b);
		FOR(i,0,lim-1) a[i]=1ll*a[i]*b[i]%mod;
		idft(a);
		FOR(i,0,m) b[i]=1ll*invfac[i]*a[i+m]%mod;
		FOR(i,0,m) a[i]=f[i];
		FOR(i,m+1,lim-1) a[i]=b[i]=0;
		dft(a);dft(b);
		FOR(i,0,lim-1) a[i]=1ll*a[i]*b[i]%mod;
		idft(a);
		FOR(i,0,2*m) f[i]=a[i];
	}
}
int main(){
	n=read();p=read();q=read();
	if(!p || !q || p+q>n+1) return puts("0"),0;
	fac[0]=1;
	FOR(i,1,n) fac[i]=1ll*fac[i-1]*i%mod;
	invfac[n]=qpow(fac[n],mod-2);
	ROF(i,n-1,0) invfac[i]=1ll*invfac[i+1]*(i+1)%mod;
	work(n-1);
	printf("%lld\n",1ll*f[p+q-2]*fac[p+q-2]%mod*invfac[p-1]%mod*invfac[q-1]%mod);
}