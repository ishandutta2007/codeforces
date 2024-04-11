#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
#define SZ(x) ((int)(x).size())
#define prts(x) return puts(x),0
#define pirtf(x) return printf("%d\n",x),0
#define re return
typedef long long LL;
typedef double ld;
typedef pair<int,int> pii;
const int Mod=998244353;
inline LL Pow(LL B,LL E,LL M=Mod){LL A=1;for(;E;E>>=1,B=B*B%M)E&1?A=A*B%M:0;return A;}
#define INF 0x3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f

map<int,int> mp;
set<int> st;

int n,q,m,k;
int a[505][505],b[505][505];
int c[505],d[505],e[505],f[505];

int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n)F(j,1,m)scanf("%d",&a[i][j]),c[i]^=a[i][j],d[j]^=a[i][j];
	F(i,1,n)F(j,1,m)scanf("%d",&b[i][j]),e[i]^=b[i][j],f[j]^=b[i][j];
	F(i,1,n)if(c[i]!=e[i])prts("No");
	F(i,1,m)if(d[i]!=f[i])prts("No");
	prts("Yes");
	return 0;
}