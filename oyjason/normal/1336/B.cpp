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
#define M 400020
int m,p[M],c[M],id[M],pr[M][4];
LL w[5];
inline LL calc(LL a,LL b,LL c){return (a-b)*(a-b)+(a-c)*(a-c)+(b-c)*(b-c);}
inline bool cmp(int a,int b){return p[a]<p[b];}
inline LL solve(){
	int na=read(),nb=read(),nc=read(),n=0;
	nb+=na,nc+=nb,w[1]=w[2]=w[3]=-1;
	while(n<na) ++n,p[n]=read(),c[n]=1,id[n]=n;
	while(n<nb) ++n,p[n]=read(),c[n]=2,id[n]=n;
	while(n<nc) ++n,p[n]=read(),c[n]=3,id[n]=n;
	sort(id+1,id+n+1,cmp); LL ans; memset(&ans,0x7f,sizeof(LL));
	for(int i=1;i<=n;i++){
		for(int k=1;k<=3;k++) pr[i][k]=pr[i-1][k];
		pr[i][c[id[i]]]=i;
	}
	for(int i=n;i>=1;i--){
		w[c[id[i]]]=i;
		int a=1,b=2;
		if(a==c[id[i]]) a=3;
		if(b==c[id[i]]) b=3;
		if(w[a]!=-1&&pr[i][b]>0) ans=min(ans,calc(p[id[i]],p[id[w[a]]],p[id[pr[i][b]]]));
		swap(a,b);
		if(w[a]!=-1&&pr[i][b]>0) ans=min(ans,calc(p[id[i]],p[id[w[a]]],p[id[pr[i][b]]]));
	}
	return ans;
}
int main(){
	for(int Cas=read();Cas;--Cas) printf("%lld\n",solve());
	return 0;
}