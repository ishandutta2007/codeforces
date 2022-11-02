#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<"-----------------------------------"<<endl
#define LL long long
#define DB double
using namespace std;
inline LL read(){
	LL nm=0; bool fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define mod 998244353
namespace  CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(LL x,LL y){return x*y%mod;}
	inline void upd(int &x,int y){x=(x+y>=mod)?(x+y-mod):(x+y);}
	inline void dec(int &x,int y){x=(x-y<0)?(x-y+mod):(x-y);}
	inline int qpow(int x,int sq){LL res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
#define M 2000020
int n,m,fs[M],nt[M],to[M],tmp,cnt,d[M];
bool del[M]; int nd[M];
int main(){
	for(int Cas=read();Cas;--Cas){
		n=read(),m=read(),cnt=0,tmp=0;
		for(int x=1;x<=n;x++) fs[x]=-1,del[x]=false,d[x]=0;
		for(int i=1,x,y;i<=m;i++) x=read(),y=read(),nt[tmp]=fs[x],fs[x]=tmp,to[tmp++]=y;
		for(int x=1;x<=n;x++){
			if(d[x]==2){nd[++cnt]=x;continue;}
			for(int i=fs[x];i!=-1;i=nt[i]) d[to[i]]=max(d[to[i]],d[x]+1);
		}
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++) printf("%d%c",nd[i],i<cnt?' ':'\n');
	}
	return 0;
}