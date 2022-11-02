#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<"-----------------------------------"<<endl
#define LL long long
#define DB double
#define pb push_back
#define LDB long double
#define ULL unsigned long long
using namespace std;
inline LL read(){
	LL nm=0; bool fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define mod 998244353
namespace CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(LL x,LL y){return x*y%mod;}
	inline void upd(int &x,int y){x=(x+y>=mod)?(x+y-mod):(x+y);}
	inline void dec(int &x,int y){x=(x-y<0)?(x-y+mod):(x-y);}
	inline int qpow(int x,LL sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
#define M 200020
int n,m,z;
LL s[M],a[M];
LL F[M],ans,res,pr[M];
inline void solve(){
	n=read(),m=read(),z=read(),ans=res=0;
	for(int i=1;i<=n;i++) s[i]=s[i-1]+(a[i]=read());
	for(int i=2;i<=n;i++) pr[i]=max(pr[i-1],a[i-1]+a[i]); pr[n+1]=pr[n];
	if(m==1){printf("%lld\n",s[2]); return;}
	for(int k=0;k<=z;k++){
		int rgt=m-k,lft=k,ed=1+rgt-lft;
		if(lft>rgt) break;
		res=s[ed]+(LL)lft*pr[ed+1];
		ans=max(ans,res);
	} printf("%lld\n",ans);
}
int main(){
	for(int Cas=read();Cas;--Cas) solve();
	return 0;
}