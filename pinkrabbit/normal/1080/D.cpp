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
inline int Pow(int B,LL E,int M){if(!(B%=M))return 0;int A=1;for(;E;E>>=1,B=(LL)B*B%M)E&1?A=(LL)A*B%M:0;return A;}
inline LL Pow(LL B,LL E,LL M){if(!(B%=M))return 0;LL A=1;for(;E;E>>=1,B=B*B%M)E&1?A=A*B%M:0;return A;}
const int INF=0x3f3f3f3f;
const LL t18=1000000000000000000ll;

LL n,k;
LL km[10005];

int main(){
	km[0]=0;
	F(i,1,1000){
		km[i]=1+4*km[i-1];
		if(km[i]>=t18) // 1e18
			break;
	}
	int Te;
	scanf("%d",&Te);
	while(Te--){
		scanf("%lld%lld",&n,&k);
		if(n==2&&k==3) {puts("NO"); continue;}
		if(n<=50&&km[n]&&k>km[n]) {puts("NO"); continue;}
		if(n==1) {puts("YES 0"); continue;}
		for(int i=1;i<=n;++i){
			LL lb=(1ll<<(i+1))-i-2;
			LL rb=km[i];
			if(n-i<=30){
				LL p1=(1<<i)-1; p1*=p1;
				if((km[n-i]!=0&&p1!=0)&&t18/km[n-i]<p1) rb=t18;
				else rb+=p1*km[n-i];
				if(rb>t18) rb=t18;
			}
			else rb=t18;
			if(lb<=k&&k<=rb) {printf("YES %d\n",n-i); break;}
		}
	}
	return 0;
}