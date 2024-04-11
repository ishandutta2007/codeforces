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
int n; LL m,l1,r1,l2,r2,c1,c2,ans,now;
inline void solve(){
	n=read(),m=read(),l1=read(),r1=read(),l2=read(),r2=read();
	memset(&ans,0x3f,sizeof(LL));
	if(l1>l2) swap(l1,l2),swap(r1,r2);
	if(r1<=l2) c1=l2-r1,c2=r2-l1,now=0;
	else c1=0,c2=max(r2,r1)-l1-(now=(min(r2,r1)-l2)),now*=(LL)n;
	if(now>=m){puts("0");return;}
	for(int k=1;k<=n;k++){
		LL cur=(LL)k*c1,rem=(LL)k*c2,cst=min(rem,m-now);
		ans=min(ans,cur+cst+((m-now-cst)<<1));
	} printf("%lld\n",ans);
}
int main(){
	for(int Cas=read();Cas;--Cas) solve();
	return 0;
}