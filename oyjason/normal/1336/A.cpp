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
#define nd second
#define ds first
inline LL read(){
	LL nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
 	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define mod 998244353
namespace  CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(int x,int y){return (LL)x*(LL)y%mod;}
	inline void upd(int &x,int y){x+=y;(x>=mod)?(x-=mod):0;}
	inline void dec(int &x,int y){x-=y;(x<0)?(x+=mod):0;}
	inline int qpow(int x,int sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
#define M 400020
int n,m,p[M],fs[M],nt[M],to[M],sz[M],tmp;
LL ans;
inline void link(int x,int y){nt[tmp]=fs[x],fs[x]=tmp,to[tmp++]=y;}
inline void dfs(int x,int last,int dep){
	
	for(int i=fs[x];i!=-1;i=nt[i]) if(to[i]^last) dfs(to[i],x,dep+1),sz[x]+=sz[to[i]];
	sz[x]++,p[x]=dep-(sz[x]-1);
}
int main(){
	n=read(),m=read(),memset(fs,-1,sizeof(fs));
	for(int i=1,x,y;i<n;i++) x=read(),y=read(),link(x,y),link(y,x);
	dfs(1,0,0),sort(p+1,p+n+1),reverse(p+1,p+n+1);
	for(int i=1;i<=m;i++) ans+=p[i];
	printf("%lld\n",ans);
	return 0;
}