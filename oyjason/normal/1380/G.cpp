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
	LL nm=0; bool fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define mod 998244353
#define inv2 499122177
namespace CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(LL x,LL y){return x*y%mod;}
	inline void upd(int &x,int y){x=(x+y>=mod)?(x+y-mod):(x+y);}
	inline void dec(int &x,int y){x=(x-y<0)?(x-y+mod):(x-y);}
	inline int qpow(int x,LL sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
#define M 1010000
int n,m,ans,c[M],pre[M],inv;
inline int calc(int m,int k){
	int ret=0;
	for(int r=m,l=r-k,cnt=1;r>0;r=l,l=r-k,cnt++)
		l=max(l,0),upd(ret,mul(mns(pre[r],pre[l]),cnt));
	return mul(inv,ret);
}
int main(){
	n=read(),inv=qpow(n,mod-2);
	for(int i=1;i<=n;i++) c[i]=read();
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++) pre[i]=add(pre[i-1],c[i]);
	for(int k=1;k<=n;k++) printf("%d%c",calc(n-k,k),k<n?' ':'\n');

	return 0;
}