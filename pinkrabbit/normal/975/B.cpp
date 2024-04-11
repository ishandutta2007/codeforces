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
ll a[19],b[19],Ans;

int main(){
	n=14;
	F(i,1,n) scanf("%I64d",a+i);
	F(i,1,n){
		if(a[i]==0) continue;
		ll sum=0;
		memcpy(b,a,sizeof(a));
		ll x=b[i]; b[i]=0;
		ll y=x/14, z=x%14;
		F(j,1,14) b[j]+=y;
		for(int j=i%14+1;z;j=j%14+1){
			++b[j]; --z;
		}
		F(j,1,14) if(b[j]%2==0) sum+=b[j];
		Ans=max(Ans,sum); 
	} printf("%I64d",Ans);
	return 0;
}