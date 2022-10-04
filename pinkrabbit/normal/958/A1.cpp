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

int n,q,Ans;
char mp1[15][15],mp2[15][15];
char tmp[15][15];

bool check(){
	F2(i,0,n) F2(j,0,n) tmp[i][j]=mp1[i][j];
	if(0==memcmp(tmp,mp2,225)) return 1;
	F2(i,0,n) F2(j,0,n) tmp[i][j]=mp1[j][n-i-1];
	if(0==memcmp(tmp,mp2,225)) return 1;
	F2(i,0,n) F2(j,0,n) tmp[i][j]=mp1[n-i-1][n-j-1];
	if(0==memcmp(tmp,mp2,225)) return 1;
	F2(i,0,n) F2(j,0,n) tmp[i][j]=mp1[n-j-1][i];
	if(0==memcmp(tmp,mp2,225)) return 1;
	return 0;
}

int main(){
	scanf("%d",&n);
	F2(i,0,n) scanf("%s",mp1[i]);
	F2(i,0,n) scanf("%s",mp2[i]);
	if(check()) Ans=1;
	F2(i,0,n) reverse(mp1[i],mp1[i]+n);
	if(check()) Ans=1;
	printf(Ans?"Yes":"No");
	return 0;
}