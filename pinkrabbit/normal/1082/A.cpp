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

int n,q,m,k,t,x,y,d;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&x,&y,&d);
		if((x-y)%d==0) printf("%d\n",abs(x-y)/d);
		else{
			int Ans=INF;
			if((y-1)%d==0) Ans=min(Ans,(x-1)/d+!!(x-1)%d+(y-1)/d);
			if((n-y)%d==0) Ans=min(Ans,(n-x)/d+!!(n-x)%d+(n-y)/d);
			if(Ans!=INF) printf("%d\n",Ans);
			else puts("-1");
		}
	}
	return 0;
}