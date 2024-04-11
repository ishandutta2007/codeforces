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
#define M 4020
int F[M][M];
char s[M],t[M];
int n,m,ot,ans;
int main(){
	scanf("%s",s+1),n=strlen(s+1);
	scanf("%s",t+1),m=strlen(t+1);
	for(int i=1;i<=n;i++) F[i][i]=(i>m||s[1]==t[i])?2:0;
	for(int r=1;r<=n;r++) for(int l=r-1;l>=1;--l){
		int len=r-l+1;
		if(l>m||s[len]==t[l]) upd(F[l][r],F[l+1][r]);
		if(r>m||s[len]==t[r]) upd(F[l][r],F[l][r-1]);
	}
	for(int i=m;i<=n;i++) upd(ans,F[1][i]);
	printf("%d\n",ans);
	return 0;
}