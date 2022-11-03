#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
//===================================
#define mod 998244353
#define maxn 262147
#define Gmod 3
#define poly std::vector<int>
il int pow(int x,int y){
    int ret=1;
    while(y){
        if(y&1)ret=1ll*ret*x%mod;
        x=1ll*x*x%mod;y>>=1;
    }
    return ret;
}
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
il poly operator%(poly a,poly b){
    int n=a.size(),m=b.size();
    if(n<m)return a;
    std::reverse(a.begin(),a.end());
    std::reverse(b.begin(),b.end());
    b.resize(n);
    poly c=mul(a,getinv(b),n-m+1);
    std::reverse(a.begin(),a.end());
    b.resize(m);std::reverse(b.begin(),b.end());
    std::reverse(c.begin(),c.end());
    a=a-mul(b,c);
    int s=a.size();while(s&&!a[s-1])--s;
    a.resize(s);
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
    int G=Gmod,iG=pow(G,mod-2);
    for(int i=1;i<maxn;i<<=1)P[i]=pow(G,(mod-1)/(i<<1)),iP[i]=pow(iG,(mod-1)/(i<<1));
}
struct _poly_auto_init{_poly_auto_init(){poly_init();}}_auto_init;
//End=================================
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),c;
	poly G(m+1,0);
	for(int i=1;i<=n;++i){
		c=gi();
		if(c<=m)G[c]=1;
	}
	G=getinv(poly(1,1)+sqrt(poly(1,1)-G*4))*2;
	for(int i=1;i<=m;++i)printf("%d\n",G[i]);
	return 0;
}