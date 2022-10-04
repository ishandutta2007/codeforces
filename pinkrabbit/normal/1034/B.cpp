#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
typedef long long LL;
typedef double ld;
typedef pair<int,int> pii;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline LL Gcd(LL X,LL Y){return Y?Gcd(Y,X%Y):X;}
inline int Pow(int B,LL E,int M){if(!(B%=M))return 0;int A=1;for(;E;E>>=1,B=(LL)B*B%M)E&1?A=(LL)A*B%M:0;return A;}
inline LL Pow(LL base,LL exp,LL _mod){if(!(base%=_mod))return 0;LL _ans=1;for(;exp;exp>>=1,base=base*base%_mod)exp&1?_ans=_ans*base%_mod:0;return _ans;}
const int INF=0x3f3f3f3f;

#define ex(x) return printf("%lld\n",x),0 

LL n,m;

int main(){
	scanf("%lld%lld",&n,&m);
	if(n>m) swap(n,m);
	if(n==1){
		printf("%lld\n",m/6ll*6ll+max(m%6ll-3ll,0ll)*2ll);
		return 0;
	}
	if(n==2){
		if(m==2) return puts("0"),0;
		if(m==3) return puts("4"),0;
		if(m==7) return puts("12"),0;
		ex(m*2ll);
	}
	if((n&1)&&(m&1)) ex((LL)n*m-1);
	else ex((LL)n*m);
	return 0;
}