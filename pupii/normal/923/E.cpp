#include<bits/stdc++.h>
typedef long long ll;
#define mod 998244353
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
int A[262147],B[262147],fact[100010],ifact[100010],rev[262147],N,lg,P[30];
void ntt(int*A,int t){
	for(int i=0;i<N;++i)if(i>rev[i])std::swap(A[i],A[rev[i]]);
	for(int o=1,_=1,w;o<N;o<<=1,++_){
		w=P[_];
		for(int*p=A;p!=A+N;p+=o<<1)
			for(int i=0,W=1;i<o;++i,W=1ll*W*w%mod){
				int t=1ll*p[i+o]*W%mod;
				p[i+o]=(p[i]-t+mod)%mod,p[i]=(p[i]+t)%mod;
			}
	}
	if(!t){
		std::reverse(A+1,A+N);
		for(int i=0,iv=pow(N,mod-2);i<N;++i)A[i]=1ll*A[i]*iv%mod;
	}
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi()%(mod-1);
	for(int i=1;i<24;++i)P[i]=pow(19260817,mod/(1<<i));
	for(int i=0;i<=n;++i)A[i]=gi();
	std::reverse(A,A+n+1);
	fact[0]=1;for(int i=1;i<=n;++i)fact[i]=1ll*fact[i-1]*i%mod;
	ifact[n]=pow(fact[n],mod-2);for(int i=n;i;--i)ifact[i-1]=1ll*ifact[i]*i%mod;
	N=1,lg=0;while(N<(n+1)*2)N<<=1,++lg;
	for(int i=0;i<N;++i)rev[i]=(rev[i>>1]>>1)|((i&1)<<lg-1);
	for(int i=0;i<=n;++i)A[i]=1ll*A[i]*fact[n-i]%mod,B[i]=ifact[i]%mod;
	ntt(A,1),ntt(B,1);
	for(int i=0;i<N;++i)A[i]=1ll*A[i]*B[i]%mod;
	ntt(A,0);memset(A+n+1,0,4*(N-n-1));
	for(int i=n,M=1;~i;--i,M=mod-M)A[i]=1ll*A[i]*pow(n-i+1,mod-1-m)%mod*M%mod;
	ntt(A,1);
	for(int i=0;i<N;++i)A[i]=1ll*A[i]*B[i]%mod;
	ntt(A,0);
	for(int i=n,M=1;~i;--i,M=mod-M)printf("%d ",1ll*ifact[n-i]*A[i]%mod*M%mod);
	return 0;
}