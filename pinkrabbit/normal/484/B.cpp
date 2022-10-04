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
inline int Pow(int base,ll exp,int _mod){int _ans=1;for(;exp;exp>>=1,base=(ll)base*base%_mod)exp&1?_ans=(ll)_ans*base%_mod:0;return _ans;}
inline ll Pow(ll base,ll exp,ll _mod){ll _ans=1;for(;exp;exp>>=1,base=base*base%_mod)exp&1?_ans=_ans*base%_mod:0;return _ans;}
const int INF=0x3f3f3f3f;

int n,ans;
int a[200001],b[2000001];

int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d",a+i);
	sort(a+1,a+n+1);
	F(i,1,n) b[a[i]+1]=a[i];
	F(i,1,2000000) if(!b[i]) b[i]=b[i-1];
	F(i,1,n){
		if(a[i]==a[i-1]) continue;
		for(int j=a[i]*2;j<=2000000;j+=a[i])
			ans=max(ans,b[j]%a[i]);
	}
	printf("%d",ans);
	return 0;
}