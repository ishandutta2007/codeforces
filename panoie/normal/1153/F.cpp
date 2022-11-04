#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

const int N = 2005, P = 998244353;
int n, k, l, ans, fac[N], ifac[N], inv[N<<1], f[N<<1];
inline int Pow(ll x, int y=P-2){
	int ans=1;
	for(; y; y>>=1, x=x*x%P) if(y&1) ans=ans*x%P;
	return ans;
}
inline int calc(){
	int now=0;
	for(int i=0; i<=n*2; ++i) now=(now+(ll)f[i]*inv[i+1])%P;
	return now;
}
int main() {
	scanf("%d%d%d", &n, &k, &l);
	inv[1]=1;
	for(int i=2; i<=n*2+1; ++i) inv[i]=(ll)(P-P/i)*inv[P%i]%P;
	fac[0]=1;
	for(int i=1; i<=n; ++i) fac[i]=(ll)fac[i-1]*i%P;
	ifac[n]=Pow(fac[n]);
	for(int i=n; i; --i) ifac[i-1]=(ll)ifac[i]*i%P;
	f[0]=1;
	for(int i=1; i<=n; ++i){
		for(int j=2*n; j>1; --j) f[j]=((P-2ll)*f[j-2]+2ll*f[j-1])%P;
		f[1]=(2ll*f[0])%P;
		f[0]=0;
	}
	for(int i=n; i>=k; --i){
		ans=(ans+(ll)fac[n]*ifac[i]%P*ifac[n-i]%P*calc())%P;
		// if(!i) printf(">> %d %d %d\n", f[0], f[1], f[2]);
		memmove(f, f+1, (n*2+1)<<2);// f/=x
		// for(int j=0; j<=n*2; ++j) f[j]=f[j+1];
		// if(f[n*2]) puts("shit");
		// for(int i=0; i<=n*2; ++i) printf("[%d]", f[i]<P/2?f[i]:f[i]-P); puts("");
		for(int j=0; j<=n*2; ++j) f[j]=f[j]*(P+1ll)/2%P;// f/=2
		for(int j=1; j<=n*2; ++j) (f[j]+=f[j-1])%=P;// f/=1-x
		f[n*2]=f[n*2-1]=0;

		for(int j=2*n; j>1; --j) f[j]=(2ll*f[j-2]+(P-2ll)*f[j-1]+f[j])%P;// f*=2x^2-2x+1
		f[1]=((P-2ll)*f[0]+f[1])%P;
	}
	return printf("%lld", (ll)ans*l%P), 0;
}