#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 998244353
#define poly std::vector<int>
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
il int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
#define maxn 262147
poly pA,pB;
int rev[maxn],_lstN,P[maxn],iP[maxn];
il vd ntt(int*A,int N,int t){
	for(int i=0;i<N;++i)if(rev[i]>i)std::swap(A[i],A[rev[i]]);
	for(int o=1;o<N;o<<=1){
		int W=t?P[o]:iP[o];
		for(int*p=A;p!=A+N;p+=o<<1)
			for(int i=0,w=1;i<o;++i,w=1ll*w*W%mod){
				int t=1ll*w*p[i+o]%mod;
				p[i+o]=(p[i]-t+mod)%mod;p[i]=(p[i]+t)%mod;
			}
	}
	if(!t){
		int inv=pow(N,mod-2);
		for(int i=0;i<N;++i)A[i]=1ll*A[i]*inv%mod;
	}
}
int N,lg;
il vd setN(int n){
	N=1,lg=0;
	while(N<n)N<<=1,++lg;
	if(N!=_lstN)for(int i=0;i<N;++i)rev[i]=(rev[i>>1]>>1)|((i&1)<<lg-1);
}
il vd ntt(poly&a,int t){
	static int A[maxn];
	for(int i=0;i<a.size();++i)A[i]=a[i];memset(A+a.size(),0,4*(N-a.size()));
	ntt(A,N,t);
	a.resize(N);
	for(int i=0;i<N;++i)a[i]=A[i];
	int s=a.size();while(s&&!a[s-1])--s;
	a.resize(s);
}
il poly mul(poly a,poly b,int newn=-1){
	if(newn==-1)newn=a.size()+b.size()-1;
	setN(a.size()+b.size()-1);
	ntt(a,1),ntt(b,1);
	for(int i=0;i<N;++i)a[i]=1ll*a[i]*b[i]%mod;
	ntt(a,0);a.resize(newn);
	return a;
}
il poly operator+(poly a,const poly&b){
	if(a.size()<b.size())a.resize(b.size());
	for(int i=0;i<a.size();++i)if(i<b.size())a[i]=(a[i]+b[i])%mod;
	return a;
}
il poly operator-(poly a,const poly&b){
	if(a.size()<b.size())a.resize(b.size());
	for(int i=0;i<a.size();++i)if(i<b.size())a[i]=(a[i]-b[i]+mod)%mod;
	return a;
}
il poly operator*(poly a,int b){
	for(auto&i:a)i=1ll*i*b%mod;
	return a;
}
il poly qiudao(poly a){
	for(int i=0;i<a.size()-1;++i)a[i]=1ll*a[i+1]*(i+1)%mod;
	a.erase(a.end()-1);
	return a;
}
il poly jifen(poly a){
	a.insert(a.begin(),0);
	for(int i=1;i<a.size();++i)a[i]=1ll*a[i]*pow(i,mod-2)%mod;
	return a;
}
il poly getinv(poly a){
	if(a.size()==1)return poly(1,pow(a[0],mod-2));
	int n=a.size(),m=a.size()+1>>1;
	poly _a(m);
	for(int i=0;i<m;++i)_a[i]=a[i];
	poly b=getinv(_a);
	setN(n+m*2-2);
	ntt(a,1);ntt(b,1);
	for(int i=0;i<N;++i)a[i]=1ll*a[i]*b[i]%mod*b[i]%mod;
	ntt(a,0),ntt(b,0);
	a.resize(n);
	return b*2-a;
}
il poly getln(poly a,int n=-1){
	if(n==-1)n=a.size();
	a.resize(n);
	return jifen(mul(qiudao(a),getinv(a),n));
}
il poly getexp(poly a){
	if(a.size()==1)return a[0]=1,a;
	int n=a.size(),m=a.size()+1>>1;
	poly _a(m);
	for(int i=0;i<m;++i)_a[i]=a[i];
	poly b=getexp(_a);
	return mul(b,poly(1,1)-getln(b,a.size())+a,a.size());
}
il poly operator^(poly a,int b){
	int n=a.size();
	a=getexp(getln(a)*b);a.resize(n);
	return a;
}
il poly sqrt(poly a){
	if(a.size()==1)return a;
	int n=a.size(),m=a.size()+1>>1;
	poly _a(m);
	for(int i=0;i<m;++i)_a[i]=a[i];
	poly b=sqrt(_a);b.resize(n);
	return (b+mul(a,getinv(b),n))*(mod+1>>1);
}
il vd poly_init(){
	int G=3,iG=pow(G,mod-2);
	for(int i=1;i<maxn;i<<=1)P[i]=pow(G,(mod-1)/(i<<1)),iP[i]=pow(iG,(mod-1)/(i<<1));
}
int fact[262147],ifact[262147];
il poly get_stelin(int n){
	if(n==0)return poly(1,1);
	if(n==1){poly r(2);r[1]=1;return r;}
	int m=n>>1;
	poly g=get_stelin(m),_g(g),_h(m+1),h(m+1);
	for(int i=0,pm=1;i<=m;++i,pm=1ll*pm*m%mod)_g[i]=1ll*_g[i]*fact[i]%mod*pm%mod;
	for(int i=0;i<=m;++i)_h[i]=ifact[m-i];
	_h=mul(_h,_g);
	int invm=pow(m,mod-2);
	for(int i=0,pm=1;i<=m;++i,pm=1ll*pm*invm%mod)h[i]=1ll*_h[m+i]*pm%mod*ifact[i]%mod;
	g=mul(h,g,n+1);
	if(n&1){
		g.resize(n+1);
		for(int i=n;i;--i)g[i]=(g[i-1]+1ll*(n-1)*g[i])%mod;
		g[0]=1ll*g[0]*(n-1)%mod;
	}
	return g;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	poly_init();
	int n=gi(),a=gi(),b=gi();
	if(a+b-1>n)return puts("0"),0;
	fact[0]=1;for(int i=1;i<=n;++i)fact[i]=1ll*fact[i-1]*i%mod;
	ifact[n]=pow(fact[n],mod-2);for(int i=n-1;~i;--i)ifact[i]=1ll*ifact[i+1]*(i+1)%mod;
	poly f=get_stelin(n-1);
	printf("%lld\n",1ll*f[a+b-2]*fact[a+b-2]%mod*ifact[a-1]%mod*ifact[b-1]%mod);
	return 0;
}