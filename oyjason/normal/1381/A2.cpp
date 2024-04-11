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
#define M 200020
int n,m,p[M];
char A[M],B[M];
int a[M],b[M];
int l,r,nom,tag;
inline void calc1(int i){
	if((a[r]^tag)==b[i]){r--;return;}
	if((a[l]^tag^1)!=b[i]) p[++m]=1,a[l]^=1; 
	p[++m]=r-l+1,l++,tag^=1,nom^=1;
}
inline void calc2(int i){
	if((a[l]^tag)==b[i]){l++;return;}
	if((a[r]^tag^1)!=b[i]) p[++m]=1,a[r]^=1;
	p[++m]=r-l+1,r--,tag^=1,nom^=1;
}
inline void solve(){
	n=read(),m=0,l=1,r=n,nom=1,tag=0,scanf("%s%s",A+1,B+1);
	for(int i=1;i<=n;i++) a[i]=A[i]-'0',b[i]=B[i]-'0';
	for(int i=n;i>=1;i--) if(nom) calc1(i); else calc2(i);
	printf("%d",m);
	for(int i=1;i<=m;i++) printf(" %d",p[i]); puts("");
}
int main(){
	for(int Cas=read();Cas;--Cas) solve();
	return 0;
}