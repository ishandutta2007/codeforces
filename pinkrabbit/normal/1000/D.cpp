//luogu
#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
#define ll long long
#define ld double
typedef pair<int,int> pii;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline ll Gcd(ll X,ll Y){return Y?Gcd(Y,X%Y):X;}
inline int Pow(int base,ll exp,int _mod){if(!(base%=_mod))return 0;int _ans=1;for(;exp;exp>>=1,base=(ll)base*base%_mod)exp&1?_ans=(ll)_ans*base%_mod:0;return _ans;}
inline ll Pow(ll base,ll exp,ll _mod){if(!(base%=_mod))return 0;ll _ans=1;for(;exp;exp>>=1,base=base*base%_mod)exp&1?_ans=_ans*base%_mod:0;return _ans;}
const int INF=0x3f3f3f3f;
#define Mod 998244353
int n;
ll C[1001][1001];
int a[1005],f[1005];

int main(){
	scanf("%d",&n);
	C[0][0]=1;
	F(i,1,n){
		C[i][0]=1;
		F(j,1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
	}
	F(i,1,n) scanf("%d",a+i);
	f[n+1]=1;
	dF(i,n,1){
		if(a[i]<=0) continue;
		F(j,i+a[i]+1,n+1){
			f[i]=(f[i]+C[j-i-1][a[i]]*f[j])%Mod;
		}
	}
	ll A=0;
	F(i,1,n) A=(A+f[i])%Mod;
	printf("%I64d",A);
	return 0;
}