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

int n,t;
ll l[200001],r[200001],b[400001];
int s[400001];
ll c[200001];

int main(){
	scanf("%d",&n);
	F(i,1,n) {scanf("%I64d%I64d",l+i,r+i), ++r[i]; b[++t]=l[i], b[++t]=r[i];}
	sort(b+1,b+t+1); int k=unique(b+1,b+t+1)-b-1;
	F(i,1,n) l[i]=lower_bound(b+1,b+k+1,l[i])-b, r[i]=lower_bound(b+1,b+k+1,r[i])-b;
	F(i,1,n) ++s[l[i]], --s[r[i]];
	F(i,1,k) s[i]+=s[i-1];
	F(i,1,k-1) c[s[i]]+=b[i+1]-b[i];
	F(i,1,n) printf("%I64d ",c[i]);
	return 0;
}