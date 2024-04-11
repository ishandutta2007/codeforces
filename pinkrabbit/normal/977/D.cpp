#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
#define ll long long
#define ld double
using namespace std;
typedef pair<int,int> pii;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline ll Gcd(ll X,ll Y){return Y?Gcd(Y,X%Y):X;}
inline int Pow(int base,ll exp,int _mod){if(!(base%=_mod))return 0;int _ans=1;for(;exp;exp>>=1,base=(ll)base*base%_mod)exp&1?_ans=(ll)_ans*base%_mod:0;return _ans;}
inline ll Pow(ll base,ll exp,ll _mod){if(!(base%=_mod))return 0;ll _ans=1;for(;exp;exp>>=1,base=base*base%_mod)exp&1?_ans=_ans*base%_mod:0;return _ans;}
const int INF=0x3f3f3f3f;

int n;
ll a[100001];
int lst[300],nxt[300];

int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%lld",a+i);
	F(i,1,n){
		F(j,1,n){
			if(a[j]*3==a[i]) nxt[i]=j, lst[j]=i;
			if(a[j]==a[i]*2) nxt[i]=j, lst[j]=i;
		}
	}
	F(i,1,n){
		if(!lst[i]){
			int now=nxt[i]; printf("%lld ",a[i]);
			for(;now;now=nxt[now]) printf("%lld ",a[now]);
		}
	}
	return 0;
}