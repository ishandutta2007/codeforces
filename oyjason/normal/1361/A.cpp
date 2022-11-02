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
#define M 500200
int n,m,fs[M],nt[M<<1],to[M<<1],tmp;
int nd[M],val[M],tar[M],tg[M];
inline void link(int x,int y){nt[tmp]=fs[x],fs[x]=tmp,to[tmp++]=y;}
inline bool cmp(int a,int b){return tar[a]<tar[b];}
int main(){
	n=read(),m=read(),memset(fs,-1,sizeof(fs));
	for(int i=0,x,y;i<m;i++) x=read(),y=read(),link(x,y),link(y,x);
	for(int i=1;i<=n;i++) nd[i]=i,tar[i]=read();
	sort(nd+1,nd+n+1,cmp);
	for(int i=1;i<=n;i++){
		int x=nd[i]; tg[0]=i;
		for(int j=fs[x];j!=-1;j=nt[j]) tg[val[to[j]]]=i;
		while(tg[val[x]]==i) ++val[x];
	}
	for(int x=1;x<=n;x++) if(val[x]!=tar[x]){puts("-1");return 0;}
	for(int i=1;i<=n;i++) printf("%d%c",nd[i],i<n?' ':'\n');
	return 0;
}