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
#define mod 1000000007
set<int> st;

int n,q,m,k;
int a[300005];
char str[300005];
int sum[300005];

int main(){
	scanf("%d%d%s",&n,&q,str+1);
	F(i,1,n) sum[i]=sum[i-1]+str[i]-'0';
	a[0]=1; F(i,1,n) a[i]=a[i-1]*2ll%mod;
	F(i,1,q){
		int l,r;
		scanf("%d%d",&l,&r);
		int one=sum[r]-sum[l-1], zero=r-l+1-one;
		LL Ans=a[r-l+1]-a[zero];
		Ans=(Ans%mod+mod)%mod;
		printf("%lld\n",Ans);
	}
	return 0;
}