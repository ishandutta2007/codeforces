#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<"-----------------------------------"<<endl
#define LL long long
#define DB double
#define pb push_back
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
#define M 4020
int n,m,p[M];
int S[M],top;
bool *F[M],g[M][M*3],f[M][M*2],*s[M];
inline bool solve(){
	n=read();
	for(int i=1;i<=n+n;i++) p[i]=read(); S[top=1]=p[n+n+1]=n+n+1;
	
	for(int i=1;i<=n+n+1;i++){
		s[i]=g[i]+M,F[i]=f[i]+M;
		memset(f[i],false,sizeof(f[i]));
		memset(g[i],false,sizeof(g[i]));

	} F[n+n+1][0]=s[1][n+n+1]=true;
	for(int i=n+n;i>=1;--i){
		while(p[S[top]]<p[i]) --top;
		for(int d=-M+1;d<M+M;d++) if(s[top][d]) F[i][d-i]=true;
		S[++top]=i,memcpy(g[top],g[top-1],sizeof(g[top]));
		for(int k=-M+1;k<M;k++) if(F[i][k]) s[top][i-k]=true;
	}
	return F[1][0];
}
int main(){
	for(int Cas=read();Cas;--Cas) puts(solve()?"YES":"NO");
	return 0;
}