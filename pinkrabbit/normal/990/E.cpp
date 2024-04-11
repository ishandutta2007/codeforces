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
const ll INF=0x3f3f3f3f3f3f3f3f;

int n,m,k;
int s[1000005],a[1000005];
int ib[1000005],r[1000005];
ll Ans=INF;

int main(){
	scanf("%d%d%d",&n,&m,&k);
	F(i,1,m) scanf("%d",s+i),ib[s[i]+1]=1;
	F(i,1,k) scanf("%d",a+i);
	r[n+1]=n+1;
	dF(i,n,1) r[i]=ib[i]?r[i+1]:i;
	if(ib[1]) return 0*puts("-1");
	F(i,1,k){
		int now=n+1, cnt=0, ok=1;
		while(now>1){
			int u=now-i>=1?r[now-i]:1;
			if(u<now) now=u, ++cnt;
			else {ok=0; break;}
		}
		if(!ok) continue;
		Ans=min(Ans,(ll)cnt*a[i]);
	}
	printf("%I64d",Ans==INF?-1:Ans);
	return 0;
}