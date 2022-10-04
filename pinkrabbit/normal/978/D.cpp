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

int n,q;
ll a[100001],b[100001];

int check(){
	int cnt=0;
	ll k=a[2]+a[2]-a[1], d=a[2]-a[1];
	F(i,3,n){
		if(-1<=a[i]-k&&a[i]-k<=1) cnt+=(a[i]!=k);
		else return INF;
		k+=d;
	} return cnt;
}

int main(){
	int Ans=INF;
	scanf("%d",&n);
	F(i,1,n) scanf("%I64d",a+i);
	if(n<=2) return 0*puts("0");
	Ans=min(Ans,check());
	++a[1];
	Ans=min(Ans,check()+1);
	a[1]-=2;
	Ans=min(Ans,check()+1);
	++a[1]; ++a[2];
	Ans=min(Ans,check()+1);
	++a[1];
	Ans=min(Ans,check()+2);
	a[1]-=2;
	Ans=min(Ans,check()+2);
	++a[1]; a[2]-=2;
	Ans=min(Ans,check()+1);
	++a[1];
	Ans=min(Ans,check()+2);
	a[1]-=2;
	Ans=min(Ans,check()+2);
	printf("%d",Ans==INF?-1:Ans);
	return 0;
}