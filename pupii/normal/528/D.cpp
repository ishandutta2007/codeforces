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
#define maxn 524289
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
il vd poly_init(){
    int G=Gmod,iG=pow(G,mod-2);
    for(int i=1;i<maxn;i<<=1)P[i]=pow(G,(mod-1)/(i<<1)),iP[i]=pow(iG,(mod-1)/(i<<1));
}
struct _poly_auto_init{_poly_auto_init(){poly_init();}}_auto_init;
//End=================================
int n,m,k;
int s[200010][4];
char S[200010],T[200010];
int ans[200010];
int qaq[127];
il int query(int l,int r,int ch){
	if(l<1)l=1;
	if(r>n)r=n;
	return s[r][ch]-s[l-1][ch];
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	qaq['A']=0,qaq['T']=1,qaq['G']=2,qaq['C']=3;
	n=gi(),m=gi(),k=gi();
	scanf("%s",S+1),scanf("%s",T+1);
	for(int i=1;i<=n;++i)S[i]=qaq[S[i]];
	for(int i=1;i<=m;++i)T[i]=qaq[T[i]];
	for(int i=1;i<=n;++i){
		++s[i][S[i]];
		for(int j=0;j<4;++j)s[i][j]+=s[i-1][j];
	}
	poly F(n+1),G(m+1);
	for(int i=1;i+m-1<=n;++i)ans[i]=1;
	for(int ch=0;ch<4;++ch){
	    F.resize(n+1);
		for(int i=1;i<=n;++i)F[i]=!query(i-k,i+k,ch);
		for(int i=1;i<=m;++i)G[i]=T[m-i+1]==ch;
		F=mul(F,G);
		for(int i=1;i<=n;++i)if(F[m+i])ans[i]=0;
	}
	int ANS=0;
	for(int i=1;i<=n;++i)ANS+=ans[i];
	printf("%d\n",ANS);
	return 0;
}