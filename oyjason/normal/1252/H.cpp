#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
#define DB long double
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
inline int read(){
	int nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define mod 1000000007
#define M 2020
namespace CALC{
	inline LL add(LL x,LL y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline LL mns(LL x,LL y){return (x-y<0)?(x-y+mod):(x-y);}
	inline LL mul(LL x,LL y){return x*y%mod;}
	inline void upd(LL &x,LL y){x=((x+y>=mod)?(x+y-mod):(x+y));}
	inline void dec(LL &x,LL y){x=((x-y<0)?(x-y+mod):(x-y+mod));}
	inline LL qpow(LL x,LL sq){LL res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
bitset<2019>F[1<<16|100];
int p[M],n,k,u[M],v[M],m,b[M],S[M],top;
inline void solve(int x){
	top=0;
	for(int i=0;i<n;i++) if(b[i]==x) S[++top]=i;
	while(top>1){
		int t1=S[top],t2=S[top-1];
		printf("%d %d\n",p[t1],p[t2]);
		top-=2,p[t1]+=p[t2],b[t2]=-1;
		while(p[t1]%k==0) p[t1]/=k,b[t1]--; if(b[t1]==x){S[++top]=t1;continue;}
	}
}
int main(){
	n=read(),k=read();
	for(int i=0;i<n;i++) p[i]=read(); F[0][0]=1;
	for(int sta=0;sta<(1<<n);sta++){
		for(int j=2000/k;j>0;--j) F[sta][j]=(F[sta][j*k]|F[sta][j]);
		for(int j=0;j<n;j++) if(!((sta>>j)&1)) F[sta|(1<<j)]|=(F[sta]<<p[j]);
	}
	int sta=(1<<n)-1;
	
	if(!F[sta][1]){puts("NO");return 0;} puts("YES");
	for(int tms=0,lev=0,sm=1;tms<n;++tms){
		int pos=-1;
		for(int i=0;i<n;i++) if(sm>=p[i]&&((sta>>i)&1))
			if(F[sta^(1<<i)][sm-p[i]]){pos=i;break;}
//		debug(sta)sp,debug(sm)sp,debug(pos)el;
		if(pos>=0){b[pos]=lev,sm-=p[pos],sta^=(1<<pos);continue;}
		--tms,sm*=k,++lev;
	}
	for(int i=100;i>0;--i) solve(i);
	return 0;
}