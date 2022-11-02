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
#define mp make_pair
#define pb push_back
inline LL read(){
	LL nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define mod 998244353
#define M 3000020
namespace  CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(int x,int y){return (LL)x*(LL)y%mod;}
	inline void upd(int &x,int y){x+=y;(x>=mod)?(x-=mod):0;}
	inline void dec(int &x,int y){x-=y;(x<0)?(x+=mod):0;}
	inline int qpow(int x,int sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
int n,m,t[M],rg[M],len;
char ch[M];
inline int POS(int i){return i+i-1;}
inline void solve(){
	scanf("%s",ch+1),n=strlen(ch+1),m=len=0;
	for(int i=1;i<n;i++) t[++m]=ch[i]-'a'+1,t[++m]=30;
	t[++m]=ch[n]-'a'+1,t[0]=t[m+1]=30,len=0;
	while(len+len+2<=n&&ch[len+1]==ch[n-len]) ++len;
	if(len+len+1>=n){for(int i=1;i<=n;i++)putchar(ch[i]);puts("");return;}
	int pos=0,rs=0; rg[m+1]=0;
	for(int i=1;i<=m;i++){
		if(i<=rs) rg[i]=rg[pos+pos-i]; else rg[i]=0; rg[i]=min(rg[i],rs-i);
		while(i+rg[i]+1<=m+1&&i-rg[i]-1>=0&&t[i+rg[i]+1]==t[i-rg[i]-1]) ++rg[i];
		if(i+rg[i]>rs) rs=rg[i]+i,pos=i;
	}
	int mid=-1,l,r,mx=0;
	for(int i=POS(len+1);i<=POS(n-len);i++) if(i-rg[i]-1<=POS(len)||i+rg[i]+1>=POS(n-len+1)){
		int ls=max(0,i-rg[i]),rs=min(m+1,i+rg[i]);
		ls++,ls++,ls>>=1,rs>>=1;
		int now=rs-ls+1+(min(n-rs,ls-1)*2);
		if(now>mx) mid=i,mx=now;
	}
	// debug(mid)el;/
	assert(mid!=-1);
	if(mid&1) mid++,mid>>=1,l=r=mid;
	else mid>>=1,l=mid,r=mid+1;
	while(l-1>=1&&r+1<=n&&ch[l-1]==ch[r+1]) l--,r++;
	int bas=min(l-1,n-r);
	for(int i=1;i<=bas;i++) putchar(ch[i]);
	for(int i=l;i<=r;i++) putchar(ch[i]);
	for(int i=bas;i>=1;i--) putchar(ch[n-i+1]);
	puts("");
}
int main(){
	for(int Cas=read();Cas;--Cas) solve();

	return 0;
}