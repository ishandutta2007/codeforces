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
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline LL Gcd(LL X,LL Y){return Y?Gcd(Y,X%Y):X;}
inline int Pow(int B,LL E,int M){if(!(B%=M))return 0;int A=1;for(;E;E>>=1,B=(LL)B*B%M)E&1?A=(LL)A*B%M:0;return A;}
inline LL Pow(LL B,LL E,LL M){if(!(B%=M))return 0;LL A=1;for(;E;E>>=1,B=B*B%M)E&1?A=A*B%M:0;return A;}
const int INF=0x3f3f3f3f;

map<int,int> mp;
set<int> st;

int n,q,m,k;
int a[300005],b[300005];
int f[300005],g[300005];
int M[3005][3005];
char str[300005];

int h[300005],nxt[600005],to[600005],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}

int main(){
	int xa,ya,xb,yb,xc,yc;
	scanf("%d%d",&xa,&ya);
	scanf("%d%d",&xb,&yb);
	scanf("%d%d",&xc,&yc);
	if(xa>xb)swap(xa,xb),swap(ya,yb);
	if(xb>xc)swap(xb,xc),swap(yb,yc);
	if(xa>xb)swap(xa,xb),swap(ya,yb);
	if(xb>xc)swap(xb,xc),swap(yb,yc);
		int k=0;
		F(i,xa,xb-1)++k;
		dF(i,xc,xb+1)++k;
		int mx=max(max(ya,yb),yc);
		int mn=min(min(ya,yb),yc);
		k+=mx-mn+1;
		printf("%d\n",k);
		F(i,xa,xb-1)printf("%d %d\n",i,ya);
		dF(i,xc,xb+1)printf("%d %d\n",i,yc);
		F(i,mn,mx)printf("%d %d\n",xb,i);
	return 0;
}