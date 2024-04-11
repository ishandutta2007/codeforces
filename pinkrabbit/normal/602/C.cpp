#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define dF3(i,a,b) for(int i=(a)-1;i>=(b);--i)
using namespace std;typedef long long ll;typedef double ld;int INF=0x3f3f3f3f;int INF2=0x7fffffff;ll LNF=0x3f3f3f3f3f3f3f3f;ll LNF2=0x7fffffffffffffff;

int n,m,x,y;
int a[401][401],b[401][401];
int f[401][401],g[401][401];

int main(){
	scanf("%d%d",&n,&m);
	memset(f,0x3f,sizeof f);
	F(i,1,n) F(j,1,n) g[i][j]=1;
	F(i,1,n) f[i][i]=g[i][i]=0;
	F(i,1,m) scanf("%d%d",&x,&y), f[x][y]=f[y][x]=1, g[x][y]=g[y][x]=0x3f3f3f3f;
	F(k,1,n) F(i,1,n) F(j,1,n){
		if(f[i][j]>f[i][k]+f[k][j]) f[i][j]=f[i][k]+f[k][j];
		if(g[i][j]>g[i][k]+g[k][j]) g[i][j]=g[i][k]+g[k][j];
	}
	if(f[1][n]==0x3f3f3f3f||g[1][n]==0x3f3f3f3f) {puts("-1"); return 0;}
	printf("%d",max(f[1][n],g[1][n]));
	return 0;
}