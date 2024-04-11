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
#define M 1020
int n,m,Q;
int p[M][M],lev[M][M],q[M*M],hd,tl;
char ch[M][M];
inline void gv(int x,int y,int k){
	if(x<1||y<1||x>n||y>m||lev[x][y]!=-1) return;
	// debug(x)sp,debug(y)sp,debug(k)el;
	q[tl++]=x*M+y,lev[x][y]=k;
}
int main(){
	n=read(),m=read(),Q=read(),memset(lev,-1,sizeof(lev));
	for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for(int i=1;i<n;i++) for(int j=1;j<=m;j++) if(ch[i][j]==ch[i+1][j])	gv(i,j,0),gv(i+1,j,0);
	for(int i=1;i<=n;i++) for(int j=1;j<m;j++) if(ch[i][j]==ch[i][j+1])	gv(i,j,0),gv(i,j+1,0);
	for(int x,y,k;hd<tl;++hd){
		x=q[hd]/M,y=q[hd]%M,k=lev[x][y]+1;
		gv(x+1,y,k),gv(x-1,y,k);
		gv(x,y+1,k),gv(x,y-1,k);
	} LL t;
	for(int x,y;Q;Q--,putchar('\n')){
		x=read(),y=read(),t=read();
		if(lev[x][y]==-1){putchar(ch[x][y]);continue;}
		else if(lev[x][y]>=t){putchar(ch[x][y]);continue;}
		t-=lev[x][y],t&=1; int ans=ch[x][y]-'0';
		putchar((ans^t)+'0');
	}
	return 0;
}