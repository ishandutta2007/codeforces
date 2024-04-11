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

int A,B,C,D;
char F[55][55];

int main(){
	scanf("%d%d%d%d",&A,&B,&C,&D);
	--A, --B, --C, --D;
	puts("50 50");
	F(i,1,25) F(j,1,25) F[i][j]='A';
	F(i,1,25) F(j,26,50) F[i][j]='B';
	F(i,26,50) F(j,1,25) F[i][j]='C';
	F(i,26,50) F(j,26,50) F[i][j]='D';
	//BC
	//DA
	for(int i=2;i<25;i+=2)
		for(int j=2;j<25;j+=2)
			if(B) F[i][j]='B', --B;
	for(int i=2;i<25;i+=2)
		for(int j=27;j<50;j+=2)
			if(C) F[i][j]='C', --C;
	for(int i=27;i<50;i+=2)
		for(int j=2;j<25;j+=2)
			if(D) F[i][j]='D', --D;
	for(int i=27;i<50;i+=2)
		for(int j=27;j<50;j+=2)
			if(A) F[i][j]='A', --A;
	F(i,1,50) printf("%s\n",F[i]+1);
	return 0;
}