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

int n,q;
int a[300001];

int ip[15000005];
int P[970705],pc;
int g[15000005], f[15000005];

void init(){
	ip[1]=1;
	for(int i=2;i<=15000000;++i){
		if(!ip[i]) P[++pc]=i, g[i]=i, f[i]=1;
		for(int j=1;j<=pc&&P[j]*i<=15000000;++j){
			ip[P[j]*i]=1;
			g[P[j]*i]=P[j];
			if(i%P[j]) f[P[j]*i]=i;
			else {f[P[j]*i]=f[i]; break;}
		}
	}
}

int main(){
	init();
	scanf("%d",&n);
	int G=0;
	F(i,1,n) scanf("%d",a+i), G=Gcd(G,a[i]);
	F(i,1,n) a[i]/=G;
	int A=0;
	memset(ip,0,sizeof ip);
	F(i,1,n){
		int b=a[i];
		while(b>1) ++ip[g[b]], b=f[b];
	}
	for(int i=1;i<=pc;++i) A=max(A,ip[P[i]]);
	printf("%d",A==0?-1:n-A);
	return 0;
}