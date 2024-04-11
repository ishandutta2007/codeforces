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
inline ll Gcd(ll X,ll Y){return Y?Gcd(Y,X%Y):X;}
inline int Pow(int base,ll exp,int _mod){if(!(base%=_mod))return 0;int _ans=1;for(;exp;exp>>=1,base=(ll)base*base%_mod)exp&1?_ans=(ll)_ans*base%_mod:0;return _ans;}
inline ll Pow(ll base,ll exp,ll _mod){if(!(base%=_mod))return 0;ll _ans=1;for(;exp;exp>>=1,base=base*base%_mod)exp&1?_ans=_ans*base%_mod:0;return _ans;}
const int INF=0x3f3f3f3f;

ll p,q,b;

int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%I64d%I64d%I64d",&p,&q,&b);
		ll d=Gcd(p,q);
		p/=d, q/=d;
//		1/q -> base b
//		printf(" q: %d , b: %d\n",q,b);
		while((d=Gcd(q,b))>1){
			while(q%d==0) q/=d;
		}
//		printf(" q: %d , b: %d\n",q,b);
		if(q==1) puts("Finite");
		else puts("Infinite");
	}
	return 0;
}