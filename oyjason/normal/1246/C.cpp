#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
#define DB double
#define pii pair<int,int>
#define mp make_pair
#define pb push_back

inline LL read(){
	LL nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}

namespace CALC{
	#define mod 1000000007
	inline int add(int x,int y){return ((x+y>=mod)?(x+y-mod):(x+y));}
	inline int mns(int x,int y){return ((x-y<0)?(x-y+mod):(x-y));}
	inline int mul(LL x,LL y){return (LL)x*(LL)y%mod;}
	inline void upd(int &x,int y){x=((x+y>=mod)?(x+y-mod):(x+y));}
	inline void dec(int &x,int y){x=((x-y<0)?(x-y+mod):(x-y));}
	inline int qpow(int x,int sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
#define M 2020
int n,m,F[2][M][M],suf[2][M][M],c[2][M][M],mx,tag[2][M][M],G[2][M];
// inline void ins(int kd,int ps,int l,int r,int x){
// 	for(;l<=mx;l+=(l&-l)) upd(c[kd][ps][l],x);
// 	for(++r;r<=mx;r+=(r&-r)) dec(c[kd][ps][r],x);
// }
// inline int qry(int kd,int ps,int k,int tt=0){
// 	for(;k;k-=(k&-k))upd(tt,c[kd][ps][x]);
// }

//  0 -
//  1 |
char ch[M][M];
int main(){
	n=read(),m=read(),mx=max(n,m);
	for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for(int i=1;i<=n;i++) for(int j=m;j>=1;--j) suf[0][i][j]=suf[0][i][j+1]+(ch[i][j]=='R');
	for(int j=1;j<=m;j++) for(int i=n;i>=1;--i) suf[1][i][j]=suf[1][i+1][j]+(ch[i][j]=='R');
	if(n==1||m==1){
		if(suf[0][1][1]||suf[1][1][1]) puts("0");
		else puts("1"); return 0;
	} F[0][1][1]=F[1][1][1]=1;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		dec(G[0][i],tag[0][i][j]),dec(G[1][j],tag[1][i][j]);
		upd(F[0][i][j],G[0][i]),upd(F[1][i][j],G[1][j]);
		int ct0=suf[0][i][j+1];
		upd(G[0][i],F[1][i][j]),upd(tag[0][i][m-ct0+1],F[1][i][j]);
		int ct1=suf[1][i+1][j];
		upd(G[1][j],F[0][i][j]),upd(tag[1][n-ct1+1][j],F[0][i][j]);
	}
	printf("%d\n",add(F[1][n][m],F[0][n][m]));
	return 0;
}