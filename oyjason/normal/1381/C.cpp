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
#define M 1020000
int n,X,Y,sz[M];
int b[M],a[M];
vector<int>pos[M];
#define pii pair<int,int>
#define mp make_pair
priority_queue<pii >Q;
int ps[M],c[M],hv1[M],hv2[M];
inline void solve(){
	n=read(),X=read(),Y=read(),Y-=X;
	while(!Q.empty()) Q.pop();
	for(int i=1;i<=n+1;i++) pos[i].clear(),sz[i]=0;
	for(int i=1;i<=n;i++) b[i]=read(),pos[b[i]].pb(i),sz[b[i]]++;
	int ot=1; while(sz[ot]>0) ++ot;
	for(int i=1;i<=n+1;i++) Q.push(mp(sz[i],i));
	
	for(int tms=1;tms<=X;tms++){
		int x=Q.top().second; Q.pop();
		a[pos[x][sz[x]-1]]=x,sz[x]--,Q.push(mp(sz[x],x));
	}
	int rem=n-X,tms=n-X-Y;
	while((Q.top().first<<1)>rem&&tms>0){
		int x=Q.top().second; Q.pop(),--tms,--rem;
		a[pos[x][sz[x]-1]]=ot,sz[x]--,Q.push(mp(sz[x],x));
	} int mx=Q.top().first,m=0; if(mx+mx>rem){puts("NO");return;}
	for(int i=1;i<=n+1;i++) for(int j=0;j<sz[i];j++) ps[m]=pos[i][j],c[m]=i,m++;
	for(int i=0;i<m;i++) a[ps[i]]=c[(i+mx)%m];//,debug(i)sp,debug(ps[i])sp,debug(c[i])el;
	for(int i=0;i<tms;i++) a[ps[i]]=ot;
	puts("YES");
	for(int i=1;i<=n;i++) printf("%d%c",a[i],i<n?' ':'\n');
	//int _X=0,_Y=0;
	//for(int i=1;i<=n;i++) if(a[i]==b[i]) _X++;
	//for(int i=1;i<=n+1;i++) hv1[i]=hv2[i]=0;
	//for(int i=1;i<=n;i++) hv1[a[i]]++,hv2[b[i]]++;
	//for(int i=1;i<=n+1;i++) _Y+=min(hv1[i],hv2[i]);
	//assert(_X==X);
	//assert(_Y==X+Y);
}
int main(){
	for(int Cas=read();Cas;--Cas) solve();
	return 0;
}