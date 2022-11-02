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
#define M 10020
#define bas 1002
int n,m,A,B,G[M],d[M];
int F[M][bas];
int q[M*bas*2],hd,tl;
#define nd second
#define ds first
priority_queue<pii >Q;
bool vis[M];
LL ans; bool ok=false;
inline void push(int x,int rem,int cnt){
	if(rem>A||F[x][rem]!=-1) return; F[x][rem]=cnt;
	q[--hd]=x*bas+rem;
	if(rem==A) q[tl++]=x*bas,F[x][0]=cnt+1;
}
int main(){
	n=read(),m=read(),memset(F,-1,sizeof(F));
	for(int i=1;i<=m;i++) d[i]=read(); sort(d+1,d+m+1);
	A=read(),B=read(); hd=tl=(M*bas+1000); push(1,0,0);
	while(hd<tl){
		int x=q[hd]/bas,rem=q[hd]%bas; hd++;
		if(x>1) push(x-1,rem+(d[x]-d[x-1]),F[x][rem]);
		if(x<m) push(x+1,rem+(d[x+1]-d[x]),F[x][rem]);
	}
	memset(&ans,0x3f,sizeof(LL));
	for(int i=1;i<=A;i++) if(F[m][i]!=-1) ok=true,ans=min(ans,i+(LL)(A+B)*(F[m][i]));
	if(!ok) ans=-1;printf("%lld\n",ans);
	return 0;
}