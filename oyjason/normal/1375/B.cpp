#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define LL long long
#define uint unsigned int 
#define ULL unsigned long long
#define LDB long double
#define DB double
#define pii pair<int,int>
#define pli pair<LL,int>
#define mp make_pair
#define pb push_back
using namespace std;
inline LL read(){
	LL nm=0; bool fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define mod 998244353
namespace CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(LL x,LL y){return x*y%mod;}
	inline void upd(int &x,int y){x=(x+y>=mod)?(x+y-mod):(x+y);}
	inline void dec(int &x,int y){x=(x-y<0)?(x-y+mod):(x-y);}
	inline int qpow(int x,LL sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
#define M 102000
int n,m,a[320][320];
inline void solve(){
	n=read(),m=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		int lim=4-(i==1)-(j==1)-(i==n)-(j==m);
		if(a[i][j]>lim) {puts("NO");return;}
		a[i][j]=lim;
	} puts("YES");
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) printf("%d%c",a[i][j],j<m?' ':'\n');
}

int main(){

	for(int Cas=read();Cas;--Cas) solve();
	return 0;
}