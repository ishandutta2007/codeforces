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

int n,q;
int a[200001];
map<int,int> Mp;
int Ans[200001],t;

int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d",a+i);
	F(i,1,n){
		if(!Mp.count(a[i])) Mp[a[i]]=1;
		if(Mp.count(a[i]-1))
			Mp[a[i]]=max(Mp[a[i]],Mp[a[i]-1]+1);
	}
	int ans=a[1];
	F(i,2,n) if(Mp[ans]<Mp[a[i]]) ans=a[i];
	t=Mp[ans]; int At=t;
	dF(i,n,1) if(a[i]==ans) Ans[t--]=i, --ans;
	printf("%d\n",At);
	F(i,1,At) printf("%d ",Ans[i]);
	return 0;
}