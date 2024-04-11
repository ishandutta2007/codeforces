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

int n,len;
char s1[1000001],s2[1000001],s3[1000001];
int t[300],a1,a2,a3;

int main(){ int Ans;
	scanf("%d",&n);
	scanf("%s%s%s",s1,s2,s3); len=strlen(s1);
	memset(t,0,sizeof t);
	F2(i,0,len)
		++t[s1[i]];
	Ans=0;
	F(i,0,299) Ans=max(Ans,t[i]);
	a1=min(Ans+n,len); if(Ans==len&&n==1) a1=len-1;
	memset(t,0,sizeof t);
	F2(i,0,len)
		++t[s2[i]];
	Ans=0;
	F(i,0,299) Ans=max(Ans,t[i]);
	a2=min(Ans+n,len); if(Ans==len&&n==1) a2=len-1;
	memset(t,0,sizeof t);
	F2(i,0,len)
		++t[s3[i]];
	Ans=0;
	F(i,0,299) Ans=max(Ans,t[i]);
	a3=min(Ans+n,len); if(Ans==len&&n==1) a3=len-1;
	if(a1>a2){
		if(a3>a1) puts("Katie");
		else if(a3==a1) puts("Draw");
		else puts("Kuro");
	}
	else if(a1<a2){
		if(a3>a2) puts("Katie");
		else if(a3==a2) puts("Draw");
		else puts("Shiro");
	}
	else{
		if(a3>a1) puts("Katie");
		else puts("Draw");
	} 
	return 0;
}