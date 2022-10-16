#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=333333,mod=998244353;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,c[maxn],lim,l,rev[maxn],invtmp[maxn],Binv[maxn],sqrtmp[maxn],Csqrt[maxn],Cinv[maxn];
inline void init(int upr){
	for(lim=1,l=0;lim<upr;lim<<=1,l++);
	FOR(i,0,lim-1) rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
}
inline int add(int a,int b){return a+b<mod?a+b:a+b-mod;}
inline int sub(int a,int b){return a<b?a-b+mod:a-b;}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
void NTT(int *A,int tp){
	FOR(i,0,lim-1) if(i<rev[i]) swap(A[i],A[rev[i]]);
	for(int i=1;i<lim;i<<=1)
		for(int j=0,r=i<<1,Wn=qpow(3,mod-1+tp*(mod-1)/r);j<lim;j+=r)
			for(int k=0,w=1;k<i;k++,w=1ll*w*Wn%mod){
				int x=A[j+k],y=1ll*A[i+j+k]*w%mod;
				A[j+k]=add(x,y);A[i+j+k]=sub(x,y);
			}
	if(tp==-1) for(int i=0,linv=qpow(lim,mod-2);i<lim;i++) A[i]=1ll*A[i]*linv%mod;
}
void poly_inv(int *A,int *B,int deg){
	if(deg==1) return void(B[0]=qpow(A[0],mod-2));
	poly_inv(A,B,(deg+1)>>1);
	init(deg<<1);
	FOR(i,0,deg-1) invtmp[i]=A[i];
	FOR(i,deg,lim-1) invtmp[i]=0;
	NTT(invtmp,1);NTT(B,1);
	FOR(i,0,lim-1) B[i]=1ll*sub(2,1ll*invtmp[i]*B[i]%mod)*B[i]%mod;
	NTT(B,-1);
	FOR(i,deg,lim-1) B[i]=0;
}
void poly_sqrt(int *A,int *B,int deg){
	if(deg==1) return void(B[0]=1);
	poly_sqrt(A,B,(deg+1)>>1);
	init(deg<<1);
	FOR(i,0,lim-1) Binv[i]=0;
	poly_inv(B,Binv,deg);
	init(deg<<1);
	FOR(i,0,deg-1) sqrtmp[i]=A[i];
	FOR(i,deg,lim-1) Binv[i]=sqrtmp[i]=0;
	NTT(sqrtmp,1);NTT(Binv,1);
	FOR(i,0,lim-1) sqrtmp[i]=1ll*sqrtmp[i]*Binv[i]%mod;
	NTT(sqrtmp,-1);
	FOR(i,0,deg-1) B[i]=499122177ll*add(B[i],sqrtmp[i])%mod;
	FOR(i,deg,lim-1) B[i]=0;
}
int main(){
	n=read();m=read();
	FOR(i,1,n){
		int x=read();
		if(x<=m) c[x]=1;
	}
	FOR(i,1,m) c[i]=(mod-4ll*c[i]%mod)%mod;
	c[0]=1;
	poly_sqrt(c,Csqrt,m+1);
	Csqrt[0]=add(Csqrt[0],1);
	poly_inv(Csqrt,Cinv,m+1);
	FOR(i,1,m) printf("%d\n",add(Cinv[i],Cinv[i]));
}