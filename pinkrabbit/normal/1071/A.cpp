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

#ifdef PINKRABBIT
#define debug(x) cout<<" #debug#  "<<#x<<" = "<<x<<endl;
#else
#define debug(x) ;
#endif

typedef long long LL;
typedef double ld;
typedef pair<int,int> pii;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline LL Gcd(LL X,LL Y){return Y?Gcd(Y,X%Y):X;}
inline int Pow(int B,LL E,int M){if(!(B%=M))return 0;int A=1;for(;E;E>>=1,B=(LL)B*B%M)E&1?A=(LL)A*B%M:0;return A;}
inline LL Pow(LL B,LL E,LL M){if(!(B%=M))return 0;LL A=1;for(;E;E>>=1,B=B*B%M)E&1?A=A*B%M:0;return A;}
const int INF=0x3f3f3f3f;

map<int,int> mp;
set<int,int> st;

int n,q,m,k;
int a,b;
int f[300005],g[300005];
int M[3005][3005];
char str[300005];

int h[300005],nxt[600005],to[600005],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}

int main(){
	scanf("%d%d",&a,&b);
	if(a==0 && b==0) prts("0\n\n0\n\n");
	int c=a+b;
	int d=0,s=0;
	while(s+d<=a+b) s+=d, ++d;
	--d;
	debug(d);
	int D=d;
	int Ans1=0;
	while(D>=1&&a>=D) a-=D, f[++Ans1]=D, --D;
	if(a&&D) f[++Ans1]=a;
	printf("%d\n",Ans1);
	F(i,1,Ans1) printf("%d ",f[i]); puts("");
	if(!D) prts("0\n\n");
	printf("%d\n",d-Ans1);
	F(i,1,D) if(i!=a) printf("%d ",i); puts("");
	return 0;
}