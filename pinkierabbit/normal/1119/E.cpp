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
LL a[300005],b[300005];
LL f[300005];

int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%lld",a+i),b[i]=b[i-1]+a[i];
	F(i,1,n){
		LL l=b[i-1]-3*f[i-1];
		if(a[i]>=2*l)f[i]=f[i-1]+l+(a[i]-2*l)/3;
		else f[i]=f[i-1]+a[i]/2;
	}printf("%lld\n",f[n]);
	return 0;
}