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
LL sm[M],inc[M];
LL dsm[M],dinc[M];
int m,n;
LL now[M];
inline void gg(){
	for(int i=1;i<=n;i++) sm[m]+=(now[i]*(now[i]-1)*(now[i]-2))/6;
	for(int i=1;i+2<=n;i++) inc[m]+=now[i]*now[i+1]*now[i+2];
}
inline void ask(int k){
	++m;
	cout<<"+ "<<k<<endl;
	cin>>sm[m]>>inc[m];
	++now[k];
	// gg();
	for(int i=1;i<=n;i++) 
	dsm[m]=sm[m]-sm[m-1];
	dinc[m]=inc[m]-inc[m-1];
}
int a[M];
int main(){
	cin>>n;
	// for(int i=1;i<=n;i++) now[i]=read();
	// gg();
	cin>>sm[0]>>inc[0];
	for(int i=2;i<n-1;i++) ask(i);
	ask(n);
	ask(n-1);
	ask(n);
	a[n]=(int)sqrtl(dsm[n]*2);
	a[n-2]=dinc[n]-dinc[n-2]-1;
	a[n-1]=dinc[n]/(a[n-2]+1)-1;
	a[n-3]=(dinc[n-1]-(a[n-2]+1)*(a[n]+1))/(a[n-2]+1)-1;
	for(int i=n-2,k=n-3;i>2;i--,k--)
		a[i-2]=(dinc[k]-a[i+1]*a[i+2]-a[i+1]*(a[i-1]+1))/(a[i-1]+1)-1;
	a[1]++;
	cout<<"!";
	for(int i=1;i<=n;i++) cout<<" "<<a[i];
	cout<<endl;
	return 0;
}