#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
#define LDB long double
#define DB double
#define pii pair<int,int>
#define pli pair<LL,int>
#define mp make_pair
#define pb push_back
inline LL read(){
	LL nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
 	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define mod 1000000007
namespace  CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(int x,int y){return (LL)x*(LL)y%mod;}
	inline void upd(int &x,int y){x+=y;(x>=mod)?(x-=mod):0;}
	inline void dec(int &x,int y){x-=y;(x<0)?(x+=mod):0;}
	inline int qpow(int x,int sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
#define M 1000020
#define INF 100000000000000000ll
#define lim 10000000000000000ll
int n,K,p[M],pw[M];
int tg[M],L[M],R[M];
inline int solve(){
	n=read(),K=read();
	LL now=0; int ans=0;
	for(int i=1;i<=n;i++) p[i]=read();
	if(K==1) return n&1;
	sort(p+1,p+n+1),reverse(p+1,p+n+1);
	now=1,ans=qpow(K,p[1]);
	for(int i=2;i<=n;i++){
		for(int k=0;now>0&&now<lim&&k<p[i-1]-p[i];k++)
			now=min(now,INF/K),now*=K;
		if(now>0) now--,dec(ans,qpow(K,p[i]));
		else now=1,upd(ans,qpow(K,p[i]));
	} return ans;
}
int main(){
	for(int Cas=read();Cas;--Cas) printf("%d\n",solve());
	return 0;
}