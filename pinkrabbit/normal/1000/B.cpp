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

int n,M;
int a[100005],b[100005],c[100005];

int main(){
	scanf("%d%d",&n,&M);
	F(i,1,n) scanf("%d",a+i); a[n+1]=M; ++n;
	dF(i,n,1) a[i]=a[i]-a[i-1];
	//ok
	F(i,1,n) b[i]=b[i-1]+(i&1?a[i]:0);
	dF(i,n-1,0) c[i]=c[i+1]+(i&1?a[i+1]:0);
	int A=b[n];
	F(i,1,n){
		if(i&1){
			int C=b[i]-1+c[i];
			A=max(A,C);
		}
		else{
			int C=b[i-1]+(a[i]-1)+c[i];
			A=max(A,C);
		}
	} printf("%d",A);
	return 0;
}