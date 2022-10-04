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

int n,m,k;
int a[300001],b[300001];

int h[300001],nxt[600001],to[600001],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	if((LL)n*m*2%k!=0) return puts("NO"),0;
	LL S=(LL)n*m*2/k;
	puts("YES");
	if(k%2==0){
		LL A1=Gcd((LL)n,S);
		LL A2=S/A1;
		printf("0 0\n%lld 0\n0 %lld\n",A1,A2);
		return 0;
	}
	else{
		LL A1=Gcd((LL)n,S);
		LL A2=S/A1;
		if(A1*2<=n) A1*=2, A2/=2;
		printf("0 0\n%lld 0\n0 %lld\n",A1,A2);
	}
	return 0;
}