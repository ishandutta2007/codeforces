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
#define mod 998244353
namespace  CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(int x,int y){return (LL)x*(LL)y%mod;}
	inline void upd(int &x,int y){x+=y;(x>=mod)?(x-=mod):0;}
	inline void dec(int &x,int y){x-=y;(x<0)?(x+=mod):0;}
	inline int qpow(int x,int sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
#define M 200200
int n,fs[M],nt[M],to[M],m,d[M],mx,tmp;
int nd[M<<3],ti[M<<3];
inline void link(int x,int y){nt[tmp]=fs[x],fs[x]=tmp,to[tmp++]=y;}
inline void dfs(int x,int last,int now){
	// debug(x)sp,debug(last)sp,debug(now)el;
	++m,nd[m]=x,ti[m]=now;
	int cur=now;
	for(int i=fs[x];i!=-1;i=nt[i]) if(to[i]^last){
		if(cur==mx) ++m,nd[m]=x,ti[m]=cur=mx-d[x];
		++cur,dfs(to[i],x,cur),++m,nd[m]=x,ti[m]=cur;
	}
	if(x>1&&cur!=now-1) ++m,nd[m]=x,ti[m]=now-1;
}
int main(){
	n=read(),memset(fs,-1,sizeof(fs));
	for(int i=1,x,y;i<n;i++) x=read(),y=read(),link(x,y),link(y,x),d[x]++,d[y]++;
	for(int i=1;i<=n;i++) mx=max(mx,d[i]);
	if(n==1){puts("1\n1 0");return 0;}
	dfs(1,0,0);
	printf("%d\n",m);
	for(int i=1;i<=m;i++) printf("%d %d\n",nd[i],ti[i]);
	return 0;
}