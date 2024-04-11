#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define LL long long
#define uint unsigned int 
#define ULL unsigned long long
#define LDB long double
#define DB double
#define pii pair<int,int>
#define pli pair<LL,int>
#define mp make_pair
#define pb push_back
using namespace std;
inline LL read(){
	LL nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}

#define mod 1000000007
namespace CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(LL x,LL y){return x*y%mod;}
	inline void upd(int &x,int y){x=(x+y>=mod)?(x+y-mod):(x+y);}
	inline void dec(int &x,int y){x=(x-y<0)?(x-y+mod):(x-y);}
	inline int qpow(int x,int sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
#define M 300020
char s[M],t[M]; int lens,lent,n,ans,pw[M],fac[M<<1],ifac[M<<1];
int gA,gB,qs,qt;
int hv[M],pri[M],mu[M],tot,ans0; bool isp[M];
inline void precalc(){
	memset(isp,true,sizeof(isp)),mu[1]=1;
	for(int i=2;i<M;i++){
		if(isp[i]) mu[i]=-1,pri[++tot]=i;
		for(int j=1;j<=tot&&pri[j]*i<M;++j){
			int num=pri[j]*i; isp[num]=false,mu[num]=-mu[i];
			if(i%pri[j]==0){mu[num]=0;break;}
		}
	}
	for(int i=1;i<=n;i++) hv[i]=mul(n/i,n/i);
	for(int i=1;i<=n;i++) for(int j=i+i;j<=n;j+=i){
		if(mu[j/i]>0) upd(hv[i],hv[j]);
		if(mu[j/i]<0) dec(hv[i],hv[j]);
	}
	for(int i=1;i<=n;i++) upd(ans0,mul(hv[i],pw[i]));
}
inline int calc(int a,int b){
	if(a==0&&b==0) return ans0; if((LL)a*(LL)b<=0) return 0;
	if(a<0) a=-a,b=-b; return mns(pw[1+n/(max(a,b)/__gcd(a,b))],2);
}
inline int C(int N,int K){return (N<K||K<0)?0:mul(fac[N],mul(ifac[K],ifac[N-K]));}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%s%s",s+1,t+1),lens=strlen(s+1),lent=strlen(t+1),n=read();
	pw[0]=fac[0]=1; for(int i=1;i<M;i++) pw[i]=add(pw[i-1],pw[i-1]);
	for(int i=1;i<(M<<1);i++) fac[i]=mul(fac[i-1],i); ifac[(M<<1)-1]=qpow(fac[(M<<1)-1],mod-2);
	for(int i=(M<<1)-1;i>0;--i) ifac[i-1]=mul(ifac[i],i); precalc();
	for(int i=1;i<=lens;i++) if(s[i]=='A') gA++; else if(s[i]=='B') gB--; else qs++;
	for(int i=1;i<=lent;i++) if(t[i]=='A') gA--; else if(t[i]=='B') gB++; else qt++;
	for(int d=-qt;d<=qs;d++) upd(ans,mul(C(qs+qt,d+qt),calc(gA+d,gB+qt-qs+d)));
	if(lens==lent){
		int prd=1;
		for(int i=1;i<=lens&&prd>0;i++){
			if(s[i]!='?'&&t[i]!='?'){if(s[i]!=t[i])prd=0;continue;}
			if(s[i]=='?'&&t[i]=='?') prd=mul(prd,2);
		}
		if(prd>0) upd(ans,mul(prd,mns(mul(mns(pw[n+1],2),mns(pw[n+1],2)),ans0)));
	} printf("%d\n",ans);
	return 0;
}