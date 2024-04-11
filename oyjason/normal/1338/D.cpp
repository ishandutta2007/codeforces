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
int n,fs[M],nt[M],to[M],tmp,F[M],G[M],W[M],ans;
inline void link(int x,int y){nt[tmp]=fs[x],fs[x]=tmp,to[tmp++]=y;}
//F used    G not use
inline void trans(int &mx,int &sc,int w){if(w>=mx)sc=mx,mx=w;else sc=max(sc,w);}
inline void dfs(int x,int last){
	int mx=0,sc=0,allmx=0,allsc=0,cnt=0,con;
	for(int i=fs[x];i!=-1;i=nt[i]) if(to[i]^last){
		++cnt,dfs(to[i],x),con=max(G[to[i]],F[to[i]]);
		trans(mx,sc,G[to[i]]),trans(allmx,allsc,con);
	}
	ans=max(ans,mx+sc+1);
	ans=max(ans,allmx+allsc+max(cnt-2,0)+(last>0));
	F[x]=mx+1;
	G[x]=allmx+max(cnt-1,0);
}
int main(){
	n=read(),memset(fs,-1,sizeof(fs));
	for(int i=1,x,y;i<n;i++) x=read(),y=read(),link(x,y),link(y,x);
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}