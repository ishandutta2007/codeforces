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
#define M 200020
int n;
int p[M],be[M];
inline LL solve(LL m){
	m--; LL id=m/3,kd=m%3,fs=1,ed=2,a,b,_b=0,k=0;
	while(id>=ed-fs) id-=ed-fs,fs<<=2,ed<<=2,k++;
	a=fs+id,b=ed;
	while((--k)>=0){
		int dn=((id>>(k+k))&3); _b<<=2;
		if(dn==1) _b+=2;
		if(dn==2) _b+=3;
		if(dn==3) _b+=1;
	} b+=_b;
	if(kd==0) return a;
	if(kd==1) return b;
	return a^b;
}
int main(){
	// int bs=1;
	// for(int j=1;j<=100;j++){
	// 	while(be[bs]) ++bs;
	// 	int a=-1;
	// 	p[++n]=bs;
	// 	for(int i=bs+1;i<M;i++) if(!be[i]){
	// 		if(!be[i^bs]){a=i;break;}
	// 	}
	// 	if(a==-1) break;
	// 	p[++n]=a,p[++n]=(a^bs);
	// 	be[bs]=be[a]=be[a^bs]=1;
	// }
	// for(int i=1;i<=n;i+=3) printf("%d,%d,%d\n",p[i],p[i+1],p[i+2]); puts("");
	// int i=41;debug(i)sp,debug(p[i])sp,debug(solve(i))el;
	for(int Cas=read();Cas;--Cas) printf("%lld\n",solve(read()));
	return 0;
}