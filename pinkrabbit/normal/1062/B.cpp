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
int a[300005],b[300005],t;

int main(){
	scanf("%d",&n);
	if(n==1) prts("1 0");
	F(i,2,n){
		if(i>n) break;
		if(n%i) continue;
		a[++t]=i;
		while(n%i==0) ++b[t], n/=i;
	}
	if(n>1) a[++t]=n, b[t]=1;
	int Ans=1, Max=0, Min=INF;
	F(i,1,t) Max=max(Max,b[i]), Min=min(Min,b[i]), Ans*=a[i];
	printf("%d ",Ans);
	printf("%d\n",((Max&(Max-1))!=0||Max!=Min)+((Max&(Max-1))!=0?32-__builtin_clz(Max):31-__builtin_clz(Max)));
	return 0;
}