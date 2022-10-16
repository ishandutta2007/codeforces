#include<bits/stdc++.h>
using namespace std;
const int maxn=300030;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
    while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}
int n,q,a[maxn],f[maxn][19],g[maxn][19],hhh[19];
int main(){
	n=read();q=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,1,n){
		FOR(j,0,18) g[i][j]=hhh[j];
		FOR(j,0,18) if((a[i]>>j)&1) hhh[j]=i;
	}
	FOR(i,1,n){
		FOR(j,0,18) if((a[i]>>j)&1) f[i][j]=i;
		else FOR(k,0,18) if((a[i]>>k)&1) f[i][j]=max(f[i][j],f[g[i][k]][j]);
	}
	while(q--){
		int l=read(),r=read();
		bool flag=false;
		FOR(i,0,18) if((a[l]>>i)&1) flag|=f[r][i]>=l;
		puts(flag?"Shi":"Fou");
	}
}
// fuck you