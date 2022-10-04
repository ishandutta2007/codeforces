#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=b;i>=(a);--i)
#define dF2(i,a,b) for(int i=b;i>(a);--i)
#define eF(i,u) for(int i:h[u])
#define ll long long
#define ld double
using namespace std;
typedef pair<int,int> pii;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline ll Gcd(ll X,ll Y){return Y?Gcd(Y,X%Y):X;}
inline int Pow(int base,ll exp,int _mod){int _ans=1;for(;exp;exp>>=1,base=(ll)base*base%_mod)exp&1?_ans=(ll)_ans*base%_mod:0;return _ans;}
inline ll Pow(ll base,ll exp,ll _mod){ll _ans=1;for(;exp;exp>>=1,base=base*base%_mod)exp&1?_ans=_ans*base%_mod:0;return _ans;}
const int INF=0x3f3f3f3f;

int n,m;
char str[100003];
int a[100001],b[100001];

int main(){
	scanf("%s",str+1); n=strlen(str+1);
	F2(i,1,n) if(str[i]==str[i+1]) a[i]=1;
	F2(i,1,n) a[i]+=a[i-1];
	scanf("%d",&m);
	int x,y;
	F(i,1,m) scanf("%d%d",&x,&y), printf("%d\n",a[y-1]-a[x-1]);
	return 0;
}