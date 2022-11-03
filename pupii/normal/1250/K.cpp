#include<bits/stdc++.h>
#define mod 998244353
typedef std::vector<int>poly;
typedef long long ll;
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
const int G=19260817,iG=pow(G,mod-2),maxn=131113;
int fir[100010],dis[200010],nxt[200010],id;
void link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int N,lg,P[30],iP[30],rev[maxn];
void setN(int n){
	lg=32-__builtin_clz(n),N=1<<lg;
	for(int i=0;i<N;++i)rev[i]=(rev[i>>1]>>1)|((i&1)<<lg-1);
}
void ntt(int*A,int t){
	for(int i=0;i<N;++i)if(i>rev[i])std::swap(A[i],A[rev[i]]);
	for(int o=1,_=1,w;o<N;o<<=1,++_){
		w=t?P[_]:iP[_];
		for(int*p=A;p!=A+N;p+=o<<1)
			for(int i=0,W=1;i<o;++i,W=1ll*W*w%mod){
				int t=1ll*p[i+o]*W%mod;
				p[i+o]=(p[i]-t+mod)%mod,p[i]=(p[i]+t)%mod;
			}
	}
	if(!t)for(int i=0,iv=pow(N,mod-2);i<N;++i)A[i]=1ll*A[i]*iv%mod;
}
poly operator*(const poly&a,const poly&b){
	static int A[maxn],B[maxn];
	int len=a.size()+b.size()-1;
	setN(len);
	for(int i=0;i<a.size();++i)A[i]=a[i];
	for(int i=0;i<b.size();++i)B[i]=b[i];
	memset(A+a.size(),0,4*(N-a.size()));
	memset(B+b.size(),0,4*(N-b.size()));
	ntt(A,1),ntt(B,1);
	for(int i=0;i<N;++i)A[i]=1ll*A[i]*B[i]%mod;
	ntt(A,0);
	poly c(len);for(int i=0;i<len;++i)c[i]=A[i];
	return c;
}
poly operator+(poly a,const poly&b){if(a.size()<b.size())a.resize(b.size());for(int i=0;i<b.size();++i)a[i]=(a[i]+b[i])%mod;return a;}
poly operator-(poly a,const poly&b){if(a.size()<b.size())a.resize(b.size());for(int i=0;i<b.size();++i)a[i]=(a[i]-b[i]+mod)%mod;return a;}
int siz[100010],fa[100010],son[100010];
void dfs(int x){
	siz[x]=1;
	for(int i=fir[x],y;i;i=nxt[i]){
		if(fa[x]==(y=dis[i]))continue;
		fa[y]=x;dfs(y);
		siz[x]+=siz[y];
		if(siz[son[x]]<siz[y])son[x]=y;
	}
}
int chain[100010],m;
poly f[100010],g[100010];
struct poly2{poly a,b;};// a:r; b:r
#define mid ((l+r)>>1)
poly Divide(int l,int r){
	if(l==r)return f[chain[l]];
	return Divide(l,mid)*Divide(mid+1,r);
}
poly2 divide(int l,int r){
	if(l==r)return{g[chain[l]]*poly{0,1},poly(1,1)};
	poly2 L=divide(l,mid),R=divide(mid+1,r);
	return{L.a*R.a,L.b+L.a*R.b};
}
#undef mid
void DFS(int x){
	g[x]={1};
	for(int i=fir[x];i;i=nxt[i])if(dis[i]!=fa[x])DFS(dis[i]);
	m=0;
	for(int i=fir[x];i;i=nxt[i])if(dis[i]!=fa[x]&&dis[i]!=son[x])chain[++m]=dis[i];
	if(m)g[x]=Divide(1,m);
	else g[x]=poly{1};
	if(son[fa[x]]!=x){
		m=0;for(int i=x;i;i=son[i])chain[++m]=i;
		poly2 s=divide(1,m);
		f[x]=s.a+s.b;
	}
}
int main(){
	for(int i=1;i<23;++i)P[i]=pow(G,mod/(1<<i)),iP[i]=pow(iG,mod/(1<<i));
	int n=gi(),s=gi()%mod,x,y;
	for(int i=1;i<n;++i)x=gi(),y=gi(),link(x,y),link(y,x);
	dfs(1);DFS(1);
	int ans=0;
	for(int i=1,C=1;i<=n;++i,C=1ll*C*(s+i-1)%mod*pow(i-1,mod-2)%mod)ans=(ans+1ll*f[1][i]*C)%mod;
	printf("%d\n",ans);
	return 0;
}