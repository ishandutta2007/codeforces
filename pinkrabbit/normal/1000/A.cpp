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

int n;
char str[100];
int a[30],b[30];

int main(){
	scanf("%d",&n);
	F(i,1,n){
		scanf("%s",str);
		int C=0;
		F(j,0,strlen(str)-1) if(str[j]=='X') ++C;
		if(str[0]=='M') ++a[0];
		if(str[C]=='S') ++a[C+1];
		if(str[C]=='L') ++a[C+5];
	}
	F(i,1,n){
		scanf("%s",str);
		int C=0;
		F(j,0,strlen(str)-1) if(str[j]=='X') ++C;
		if(str[0]=='M') ++b[0];
		if(str[C]=='S') ++b[C+1];
		if(str[C]=='L') ++b[C+5];
	}
	int A=0;
	F(i,0,8) A+=abs(a[i]-b[i]); printf("%d",A/2);
	return 0;
}