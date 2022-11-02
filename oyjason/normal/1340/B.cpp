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
#define M 2220
char ch[10][8]={
"1110111",
"0010010",
"1011101",
"1011011",
"0111010",
"1101011",
"1101111",
"1010010",
"1111111",
"1111011"
};
char s[M][9];
int n,m,pos[M],cst[M][10],p[M];
bool vis[M][M];
inline bool dfs(int i,int rem){
	if(rem<0) return false;
	if(i==n+1) return rem==0;
	if(vis[i][rem]) return false; vis[i][rem]=true;
	for(int j=9;j>=0;--j) if(cst[i][j]!=-1){
		p[i]=j;
		if(dfs(i+1,rem-cst[i][j])) return true;
	} return false;

}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++) scanf("%s",s[i]);
	for(int i=1;i<=n;i++){
		for(int j=0;j<10;j++){
			cst[i][j]=0;
			for(int k=0;k<7;k++)if(ch[j][k]!=s[i][k]){
				if(ch[j][k]=='1') ++cst[i][j];
				else{cst[i][j]=-1;break;}
			}
		}
	}
	if(!dfs(1,m)){puts("-1");return 0;}
	for(int i=1;i<=n;i++) putchar('0'+p[i]);
	puts("");
	return 0;
}