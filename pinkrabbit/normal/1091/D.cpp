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
const int Mod=998244353;

map<int,int> mp;
set<int> st;

int n,q,m,k;
int a[300005],b[300005];
int f[3000005],g[3000005];
int M[3005][3005];
char str[300005];

int h[300005],nxt[600005],to[600005],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}

int main(){
	scanf("%d",&n);
	f[0]=1;F(i,1,n)f[i]=(LL)f[i-1]*i%Mod;
	f[0]=g[1]=1;F(i,2,n)g[i]=(LL)(Mod-Mod/i)*g[Mod%i]%Mod;
	F(i,2,n)g[i]=(LL)g[i-1]*g[i]%Mod;
	int Ans=f[n];
	F(i,1,n-2)Ans=(Ans+(LL)f[n]*g[n-i]%Mod*(n-i-1)%Mod*i)%Mod;printf("%d\n",Ans);
	return 0;
}