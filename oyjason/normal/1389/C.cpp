#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<"-----------------------------------"<<endl
#define LL long long
#define DB double
#define pb push_back
#define LDB long double
#define ULL unsigned long long
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
#define M 200020
int n,m,z;
char ch[M];
int ct[20],ans;
inline void solve(){
	scanf("%s",ch+1),n=strlen(ch+1),memset(ct,0,sizeof(ct));
	for(int i=1;i<=n;i++) ct[ch[i]-'0']++; ans=0;
	for(int i=0;i<=9;i++) ans=max(ans,ct[i]);
	for(int a=0;a<10;a++) for(int b=0;b<10;b++) if(a!=b){
		int now=a,ot=b,cur=0;
		for(int i=1;i<=n;i++) if(ch[i]-'0'==now) swap(now,ot),++cur;
		if(cur&1) cur--; ans=max(ans,cur);
	} printf("%d\n",n-ans);
}
int main(){
	for(int Cas=read();Cas;--Cas) solve();
	return 0;
}