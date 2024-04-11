#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<"-----------------------------------"<<endl
#define LL long long
#define uint unsigned int
#define ULL unsigned long long
#define LDB long double 
#define DB double
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
using namespace std;
namespace IO{
	const int BS=(1<<23)+5; int Top=0;
	char Buffer[BS],OT[BS],*OS=OT,*HD,*TL,SS[20]; const char *fin=OT+BS-1;
	char Getchar(){if(HD==TL){TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);} return (HD==TL)?EOF:*HD++;}
	void flush(){fwrite(OT,1,OS-OT,stdout),OS=OT;}
	void Putchar(char c){*OS++ =c;if(OS==fin)flush();}
	void write(int x){
		if(!x){Putchar('0');return;} if(x<0) x=-x,Putchar('-');
		while(x) SS[++Top]=x%10,x/=10;
		while(Top) Putchar(SS[Top]+'0'),--Top;
	}
	inline int read(){
		int nm=0; bool fh=true; char cw=getchar();
		for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
		for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
		return fh?nm:-nm;
	}
} using namespace IO;
#define M 160020
namespace CALC{
	#define mod 998244353
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(LL x,LL y){return x*y%mod;}
	inline void upd(int &x,int y){x=((x+y>=mod)?(x+y-mod):(x+y));}
	inline void dec(int &x,int y){x=((x-y<0)?(x-y+mod):(x-y));}
	inline int qpow(int x,int sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
} using namespace CALC;
int n,m,tmp,fs[M],nt[M<<1],to[M<<1],low[M],P[M];
int sz[M],mxs[M],dfn[M],tp[M],cnt,fa[M],INV,tot,tg[M];
struct Bit{
	int c[M];
	inline void ins(int x,int w){for(int k=x;k<=n;k+=(k&-k))upd(c[k],w);}
	inline int qry(int l,int r,int tt=0){
		if(r<l) return 0;
		for(int k=r;k;k-=(k&-k)) upd(tt,c[k]);
		for(int k=l-1;k;k-=(k&-k)) dec(tt,c[k]); return tt;
	}
}Mx,Sub,rs,ls;
inline void link(int x,int y){nt[tmp]=fs[x],fs[x]=tmp,to[tmp++]=y;}
inline void dfs1(int x,int last){
	fa[x]=last,sz[x]=1;
	for(int i=fs[x];i!=-1;i=nt[i]) if(to[i]!=last){
		dfs1(to[i],x),sz[x]+=sz[to[i]];
		if(sz[to[i]]>sz[mxs[x]]) mxs[x]=to[i];
	}
}
inline void dfs2(int x,int dtp){
	tp[x]=dtp,dfn[x]=++cnt; if(mxs[x]) dfs2(mxs[x],dtp);
	for(int i=fs[x];i!=-1;i=nt[i]) if(to[i]!=fa[x]&&to[i]!=mxs[x]) dfs2(to[i],to[i]);
}
inline void mdf(int x,int w){
	upd(tot,w); int ot=mul(P[n-sz[x]],w); upd(tg[x],w);
	rs.ins(dfn[x]+sz[x]-1,ot),ls.ins(dfn[x],ot),Sub.ins(dfn[x],ot);
	if(mxs[x]) Mx.ins(dfn[mxs[x]],mul(w,P[sz[mxs[x]]]));
}
inline int calc(int x){
	int ans=tot;
	dec(ans,rs.qry(1,dfn[x]-1));
	dec(ans,ls.qry(dfn[x]+sz[x],n));
	dec(ans,Sub.qry(dfn[x]+1,dfn[x]+sz[x]-1));
	while(x){
		dec(ans,Mx.qry(dfn[tp[x]]+1,dfn[x])),x=tp[x];
		dec(ans,mul(P[sz[x]],tg[fa[x]])),x=fa[x];
	}
	return ans;
}
int main(){
	n=read(),m=read(),memset(fs,-1,sizeof(fs));
	for(int i=1,x,y;i<n;i++) x=read(),y=read(),link(x,y),link(y,x);
	dfs1(1,0),dfs2(1,1),INV=qpow(n,mod-2);
	for(int x=1;x<=n;x++) P[x]=mul(INV,x);
	while(m--){
		int op=read(),x=read();
		if(op==2){printf("%d\n",calc(x));continue;}
		mdf(x,read());
	} return 0;
}