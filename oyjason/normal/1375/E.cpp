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
namespace CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(LL x,LL y){return x*y%mod;}
	inline void upd(int &x,int y){x=(x+y>=mod)?(x+y-mod):(x+y);}
	inline void dec(int &x,int y){x=(x-y<0)?(x-y+mod):(x-y);}
	inline int qpow(int x,LL sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
#define M 1000200
int n,m;
int p[M],pos[M],a[M];
int u[M],v[M];
inline bool cmp(int x,int y){return (a[x]^a[y])?(a[x]<a[y]):(x<y);}
inline void mdf(int x,int y){
	++m,u[m]=x,v[m]=y,swap(p[x],p[y]);
	pos[p[x]]=x,pos[p[y]]=y;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++) pos[i]=i,a[i]=read();
	sort(pos+1,pos+n+1,cmp);
	for(int i=1;i<=n;i++) p[pos[i]]=i;
	for(int i=n;i>=1;--i) for(int k=p[i]+1;k<=i;k++) mdf(pos[k],i);
	printf("%d\n",m);
	for(int i=1;i<=m;i++) printf("%d %d\n",u[i],v[i]);
	return 0;
}