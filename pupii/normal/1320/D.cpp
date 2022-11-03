#include<bits/stdc++.h>
#define mod 1019260817
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
#ifdef mod
#define maxn 262147
#define poly std::vector<int>
poly pA,pB;
int rev[maxn],_lstN,P[maxn],iP[maxn];
void ntt(int*A,int N,int t){
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
int N,lg,G=19260817,iG=332748118;
void setN(int n){
	N=1,lg=0;
	while(N<n)N<<=1,++lg;
	if(N!=_lstN)for(int i=0;i<N;++i)rev[i]=(rev[i>>1]>>1)|((i&1)<<lg-1);
}
void ntt(poly&a,int t){
	static int A[maxn];
	for(int i=0;i<a.size();++i)A[i]=a[i];memset(A+a.size(),0,4*(N-a.size()));
	ntt(A,N,t);
	a.resize(N);
	for(int i=0;i<N;++i)a[i]=A[i];
	int s=a.size();while(s&&!a[s-1])--s;
	a.resize(s);
}
poly mul(poly a,poly b,int newn){
	setN(a.size()+b.size()-1);
	ntt(a,1),ntt(b,1);
	for(int i=0;i<N;++i)a[i]=1ll*a[i]*b[i]%mod;
	ntt(a,0);a.resize(newn);
	return a;
}
poly operator+(poly a,const poly&b){
	if(a.size()<b.size())a.resize(b.size());
	for(int i=0;i<a.size();++i)if(i<b.size())a[i]=(a[i]+b[i])%mod;
	return a;
}
poly operator-(poly a,const poly&b){
	if(a.size()<b.size())a.resize(b.size());
	for(int i=0;i<a.size();++i)if(i<b.size())a[i]=(a[i]-b[i]+mod)%mod;
	return a;
}
poly operator*(poly a,int b){
	for(auto&i:a)i=1ll*i*b%mod;
	return a;
}
#undef mod
int mod;
struct qwq{
	int rnd(){return rand()&32767;}
	qwq(){
		srand(time(NULL));
		while(1){
			mod=((1ll*rnd()<<15)|rnd())%120000000+900000000;
			bool flg=0;
			for(int i=2;i*i<=mod;++i)if(mod%i==0){flg=1;break;}
			if(!flg)break;
		}
	}
}_____;
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
poly qiudao(poly a){
	for(int i=0;i<a.size()-1;++i)a[i]=1ll*a[i+1]*(i+1)%mod;
	a.erase(a.end()-1);
	return a;
}
poly jifen(poly a){
	a.insert(a.begin(),0);
	for(int i=1;i<a.size();++i)a[i]=1ll*a[i]*pow(i,mod-2)%mod;
	return a;
}
poly getinv(poly a){
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
poly getln(poly a,int n=-1){
	if(n==-1)n=a.size();
	a.resize(n);
	return jifen(mul(qiudao(a),getinv(a),n));
}
poly getexp(poly a){
	if(a.size()==1)return a[0]=1,a;
	int n=a.size(),m=a.size()+1>>1;
	poly _a(m);
	for(int i=0;i<m;++i)_a[i]=a[i];
	poly b=getexp(_a);
	return mul(b,poly(1,1)-getln(b,a.size())+a,a.size());
}
void poly_init(){
	for(int i=1;i<maxn;i<<=1)P[i]=pow(G,(mod-1)/(i<<1)),iP[i]=pow(iG,(mod-1)/(i<<1));
}
template<class Ta,class Tb>void inc(Ta&a,Tb b){a=a+b>=mod?a+b-mod:a+b;}
template<class Ta,class Tb>void dec(Ta&a,Tb b){a=a>=b?a-b:a+mod-b;}
#endif
char S[200010];
int H[200010],seed=19260817,ps[200010],sps[200010];
int nxt[200010],s[200010],ips[200010];
int get(int l,int r){
	if(!nxt[l]||nxt[l]>r)return-1;
	int R=1ll*(H[r]-H[l-1]+mod)*ips[s[l-1]]%mod;
	if(l&1)R=(3ll*sps[s[r]-s[l-1]]-R+mod)%mod;
	return R;
}
signed main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi();scanf("%s",S+1);
	ps[0]=1;for(int i=1;i<=n;++i)ps[i]=1ll*seed*ps[i-1]%mod;
	for(int i=1;i<=n;++i)sps[i]=(sps[i-1]+ps[i])%mod;
	for(int i=0;i<=n;++i)ips[i]=pow(ps[i],mod-2);
	for(int i=1;i<=n;++i)s[i]=s[i-1]+(S[i]=='0');
	for(int i=1;i<=n;++i)
		if(S[i]=='1')H[i]=H[i-1];
		else H[i]=(H[i-1]+((i&1)+1)*1ll*ps[s[i]])%mod;
	for(int i=n;i;--i)nxt[i]=S[i]=='0'?i:nxt[i+1];
	int Q=gi(),l,r,len;
	while(Q--){
		l=gi(),r=gi(),len=gi();
		if(get(l,l+len-1)==get(r,r+len-1))puts("Yes");
		else puts("No");
	}
	return 0;
}