#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
#define DB long double
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define rint register int 
#define M 1160010
inline int read(){
	int nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
int fac[M],ifac[M];
#define mod 998244353
namespace CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(LL x,LL y){return x*y%mod;}
	inline void upd(int &x,int y){x=((x+y>=mod)?(x+y-mod):(x+y));}
	inline void dec(int &x,int y){x=((x-y<0)?(x-y+mod):(x-y));}
	inline int qpow(int x,int sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
int n,m,p[M],K;
namespace POLY{
	int lg[M],g[40],v[40],od[M],iv[40],vv[M];
	void init(int N=M){
		N=min(N,M-10); int len=2,nw=1;
		for(;len<=N;len<<=1,nw++)
			lg[len]=nw,v[nw]=qpow(g[nw]=qpow(3,(mod-1)/len),mod-2),iv[nw]=qpow(len,mod-2);
		len>>=1,fac[0]=ifac[0]=1;
		for(rint i=1;i<=len;i++) fac[i]=mul(fac[i-1],i);
		vv[0]=0,ifac[len]=qpow(fac[len],mod-2);
		for(rint i=len;i>0;--i) ifac[i-1]=mul(ifac[i],i),vv[i]=mul(ifac[i],fac[i-1]);
	}
	void NTT(int *x,int len,int kd){
		int bas=lg[len];
		for(rint i=1;i<len;i++) od[i]=(od[i>>1]>>1)|((i&1)<<(bas-1));
		for(rint i=1;i<len;i++) if(i<od[i]) swap(x[i],x[od[i]]);
		for(rint tt=1,tp=1;tt<len;tp++,tt<<=1){
			for(rint wn=(kd>0)?g[tp]:v[tp],st=0;st<len;st+=(tt<<1)){
				for(rint now=1,pos=st;pos<st+tt;pos++,now=mul(now,wn)){
					int t1=x[pos],t2=mul(now,x[pos+tt]);
					x[pos]=add(t1,t2),x[pos+tt]=mns(t1,t2);
				}
			}
		} if(kd>0) return;
		for(rint i=0;i<len;i++) x[i]=mul(x[i],iv[bas]);
	}
	inline void clr(int *_dt,int len){memset(_dt,0,sizeof(int)*(len));}
	inline void cpy(int *_dt,int *_ss,int len){memcpy(_dt,_ss,sizeof(int)*len);}
	inline void tms(int *a,int mxa,int *b,int mxb,int *res,int mx=0){
		static int A[M],B[M]; int len=1; while(len<=mxa+mxb) len<<=1;
		clr(A,len),clr(B,len),cpy(A,a,mxa+1),cpy(B,b,mxb+1);
		NTT(A,len,1),NTT(B,len,1); if(!mx) mx=len;
		for(rint i=0;i<len;i++) A[i]=mul(A[i],B[i]); NTT(A,len,-1); cpy(res,A,mx);
	}
	void calc(int *F,int l,int r){
		if(l==r){
			if(p[l]==p[l+1]) F[0]=F[2]=0,F[1]=K;
			else F[0]=F[2]=1,F[1]=K-2;
			return;
		} int mid=((l+r)>>1),ls=mid-l+1,rs=r-mid;
		ls<<=1,rs<<=1;
		calc(F,l,mid);
		calc(F+ls+2,mid+1,r);
		tms(F,ls,F+ls+2,rs,F);
	}
}
int F[M],G[M];
int cnt,ot;
using POLY::NTT;
int main(){
	n=read(),K=read(),POLY::init(n<<4);
	for(int i=1;i<=n;i++) p[i]=read(); p[n+1]=p[1];
	for(int i=1;i<=n;i++) cnt+=(p[i]!=p[i+1]);
	if(!cnt){puts("0");return 0;}
	ot=qpow(K,n-cnt);
	F[0]=F[2]=1,F[1]=K-2;
	int len=1;
	while(len<=cnt+cnt+cnt) len<<=1;
	NTT(F,len,1);
	for(int i=0;i<len;i++) F[i]=qpow(F[i],cnt);
	NTT(F,len,-1);
	int ans=0;
	for(int i=cnt+1;i<=cnt+cnt;i++) upd(ans,F[i]);
	printf("%d\n",mul(ans,ot));
	return 0;
}