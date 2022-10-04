#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
#define SZ(x) ((int)(x).size())
#define prts(x) return puts(x),0
#define pirtf(x) return printf("%d\n",x),0
#define re return
typedef long long LL;
typedef double ld;
typedef pair<int,int> pii;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline LL Gcd(LL X,LL Y){return Y?Gcd(Y,X%Y):X;}
inline int Pow(int B,LL E,int M){if(!E)return 1;if(!(B%=M))return 0;int A=1;for(;E;E>>=1,B=(LL)B*B%M)E&1?A=(LL)A*B%M:0;return A;}
inline LL Pow(LL B,LL E,LL M){if(!E)return 1;if(!(B%=M))return 0;LL A=1;for(;E;E>>=1,B=B*B%M)E&1?A=A*B%M:0;return A;}
const int INF=0x3f3f3f3f;

map<int,int> mp;
set<int> st;

int n,q,m,k;
char str[1000005];

int main(){
	scanf("%s",str+1);
	n=strlen(str+1);
	int l1=n+1,r1=0,l2=n+1,r2=0;
	F(i,1,n)if(str[i]=='['){l1=i;break;}
	dF(i,n,1)if(str[i]==']'){r1=i;break;}
	if(l1>r1)prts("-1");
	F(i,l1,n)if(str[i]==':'){l2=i;break;}
	dF(i,r1,1)if(str[i]==':'){r2=i;break;}
	if(l2>=r2)prts("-1");
	int cnt=0;
	F(i,l2,r2)if(str[i]=='|')++cnt;
	printf("%d\n",cnt+4); 
	return 0;
}