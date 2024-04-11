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

int n;
char str[100001],ans[100001],tot=1;

bool vol(char x){return x=='a'||x=='e'||x=='i'||x=='o'||x=='u'||x=='y';}

int main(){
	scanf("%d",&n);
	scanf("%s",str+1); ans[1]=str[1];
	F(i,2,n) if(!(vol(ans[tot])&&vol(str[i]))) ans[++tot]=str[i];
	printf("%s",ans+1);
	return 0;
}