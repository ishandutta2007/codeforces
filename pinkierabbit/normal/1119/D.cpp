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
const int Mod=998244353;
inline LL Pow(LL B,LL E,LL M=Mod){LL A=1;for(;E;E>>=1,B=B*B%M)E&1?A=A*B%M:0;return A;}
#define INF 0x3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f

map<int,int> mp;
set<int> st;

int n,q,m,k;
LL s[300005],t[300005];

int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%lld",s+i);
	sort(s+1,s+n+1);
	--n;
	F(i,1,n) s[i]=s[i+1]-s[i];
	sort(s+1,s+n+1);
	F(i,1,n)t[i]=t[i-1]+s[i];
	scanf("%d",&q);
	while(q--){
		LL l,r,len;
		scanf("%lld%lld",&l,&r);
		len=r-l+1;
		LL ans=len*(n+1);
		int pos=lower_bound(s+1,s+n+1,len)-s-1;
		ans-=len*pos;
		ans+=t[pos];
		printf("%lld ",ans);
	}
	return 0;
}