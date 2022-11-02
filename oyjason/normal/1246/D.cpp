#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
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

namespace CALC{
	#define mod 1000000007
	inline int add(int x,int y){return ((x+y>=mod)?(x+y-mod):(x+y));}
	inline int mns(int x,int y){return ((x-y<0)?(x-y+mod):(x-y));}
	inline int mul(LL x,LL y){return (LL)x*(LL)y%mod;}
	inline void upd(int &x,int y){x=((x+y>=mod)?(x+y-mod):(x+y));}
	inline void dec(int &x,int y){x=((x-y<0)?(x-y+mod):(x-y));}
	inline int qpow(int x,int sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
#define M 200020
int n,m,sz[M],fa[M],mxd[M],nd[M],up[M],u[M<<3];
vector<int>to[M];
inline int cmp(int x,int y){if(mxd[x]!=mxd[y])return mxd[x]<mxd[y];return sz[x]<sz[y];}
inline void dfs(int x){
	nd[m++]=x;
	for(int i=0,TP=to[x].size();i<TP;i++) dfs(to[x][i]);
} 
int main(){
	n=read();
	for(int i=1;i<n;i++) fa[i]=read(),to[fa[i]].pb(i);
	for(int i=n-1;i>0;i--) sz[i]++,sz[fa[i]]+=sz[i],mxd[fa[i]]=max(mxd[fa[i]],mxd[i]+1);
	for(int i=0;i<n;i++) sort(to[i].begin(),to[i].end(),cmp); dfs(0),m=0;
	for(int i=1;i<n;i++) up[nd[i]]=nd[i-1];
	for(int i=1;i<n;i++){
		int x=nd[i];
		while(up[x]!=fa[x]) u[++m]=x,up[x]=up[up[x]];
	}
	for(int i=0;i<n;i++) printf("%d ",nd[i]); puts("");
	printf("%d\n",m);
	for(int i=1;i<=m;i++) printf("%d ",u[i]); puts("");
	return 0;
}