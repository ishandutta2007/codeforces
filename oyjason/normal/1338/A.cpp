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
int n; LL a[M],p[M];
inline bool check(int w){
	p[n]=a[n]+(1ll<<w)-1;
	for(int i=n-1;i>=1;i--){
		if(a[i]>p[i+1]) return false; p[i]=a[i];
		for(int k=w-1;k>=0;--k) if(p[i]+(1ll<<k)<=p[i+1]) p[i]+=(1ll<<k);
	} return true;
}
inline int solve(){
	n=read(); int l=0,r=31,ans=32;
	for(int i=1;i<=n;i++) a[i]=read();
	while(l<=r){
		int mid=((l+r)>>1);
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	} return ans;
}
int main(){
	for(int Cas=read();Cas;--Cas) printf("%d\n",solve());
	return 0;
}