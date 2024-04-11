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
#define M 302000
int n,m,a[M],t[M],cnt[M];
inline int getmex(){int mx=0;while(cnt[mx]>0) ++mx;return mx;}
inline void solve(){
	n=read(),m=0;
	memset(cnt,0,sizeof(int)*(n+4));
	for(int i=1;i<=n;i++) a[i]=read(),cnt[a[i]]++;

	while(true){
		int val=getmex(),i=val+1;
		if(val>=n){
			bool ok=false;
			for(int k=1;k<=n;k++) if(a[k]!=k-1){
				t[++m]=k,--cnt[a[k]],a[k]=val,++cnt[a[k]];
				ok=true; break;
			}
			if(ok) continue;
			break;
		}t[++m]=i;
		--cnt[a[i]],a[i]=val,++cnt[a[i]];
	}
	printf("%d\n",m);
	for(int i=1;i<=m;i++) printf("%d%c",t[i],i<m?' ':'\n');
}

int main(){

	for(int Cas=read();Cas;--Cas) solve();
	return 0;
}