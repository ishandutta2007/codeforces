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

int n,p[1005],Ans;
char str[1003][1005];
set<int> St;

int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%s",str[i]);
	F(i,1,n){
		int len=strlen(str[i]);
		sort(str[i],str[i]+len);
		len=unique(str[i],str[i]+len)-str[i];
		str[i][len]='\0';
		F(j,0,len-1) p[i]=p[i]|(1<<(str[i][j]-'a'));
		if(!St.count(p[i])) ++Ans, St.insert(p[i]);
	}printf("%d",Ans);
	return 0;
}