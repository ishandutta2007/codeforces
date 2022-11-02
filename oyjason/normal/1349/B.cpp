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
namespace CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(int x,int y){return (LL)x*(LL)y%mod;}
	inline void upd(int &x,int y){x+=y;(x>=mod)?(x-=mod):0;}
	inline void dec(int &x,int y){x-=y;(x<0)?(x+=mod):0;}
	inline int qpow(int x,int sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
#define M 200200
int n,p[M],k,s[M],fs[M+M+M];
inline bool solve(){
	n=read(),k=read(); int hv=0;
	for(int i=1;i<=n;i++){
		int x=read();
		if(x<k) p[i]=-1;
		if(x==k) p[i]=0,hv++;
		if(x>k) p[i]=1;
	}
	if(!hv) return false; if(n==1) return true;
	for(int i=1;i<n;i++) if(p[i]+p[i+1]>=1) return true;
	for(int i=1;i<n;i++) if(p[i]==0&&p[i+1]==0) return true;
	for(int i=1;i+1<n;i++) if(p[i]+p[i+2]==2) return true;
	for(int i=1;i+1<n;i++) if(p[i]==0&&p[i+2]==0) return true;
	for(int i=-n;i<=n;i++) fs[M+i]=n+1; fs[M+0]=0;
	int sum=0,r0=-1;
	for(int i=1;i<=n;i++){
		if(p[i]==0) r0=i; sum+=p[i];
		if(min(fs[sum+M],fs[sum+M-1])<min(i-1,r0)) return true;
		fs[sum+M]=min(fs[sum+M],i);
	} return false;
}
int main(){
	for(int Cas=read();Cas;--Cas) puts(solve()?"yes":"no");
	return 0;
}