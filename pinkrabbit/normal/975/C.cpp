#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
#define ll long long
#define ld double
using namespace std;
typedef pair<int,ll> pii;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline ll Gcd(ll X,ll Y){return Y?Gcd(Y,X%Y):X;}
inline int Pow(int base,ll exp,int _mod){if(!(base%=_mod))return 0;int _ans=1;for(;exp;exp>>=1,base=(ll)base*base%_mod)exp&1?_ans=(ll)_ans*base%_mod:0;return _ans;}
inline ll Pow(ll base,ll exp,ll _mod){if(!(base%=_mod))return 0;ll _ans=1;for(;exp;exp>>=1,base=base*base%_mod)exp&1?_ans=_ans*base%_mod:0;return _ans;}
const int INF=0x3f3f3f3f;

int n,q;
ll a[200008],k[200008];
ll sum[200008];
int main(){
	scanf("%d%d",&n,&q);
	F(i,1,n) scanf("%I64d",a+i), sum[i]=sum[i-1]+a[i]; sum[n+1]=0x3f3f3f3f3f3f3f3fll;
	F(i,1,q) scanf("%I64d",k+i);
	ll tot=0;
	F(i,1,q){
		tot+=k[i];
		int pos=upper_bound(sum+1,sum+n+2,tot)-sum-1;
		if(pos==n){
			tot=0;
			printf("%d\n",n);
		}
		else{
			printf("%d\n",n-pos);
		}
	}
	return 0;
}