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

int n,k;
int a[5001],b[501],c[11];
int p[100001],h[100001];
ll f[5001][501];
ll Ans;

int main(){
	scanf("%d%d",&n,&k);
	F(i,1,n*k) scanf("%d",a+i), ++p[a[i]];
	F(i,1,n) scanf("%d",b+i), ++h[b[i]];
	F(i,1,k) scanf("%d",c+i);
	memset(f,192,sizeof f);
	f[0][0]=0;
	F(i,1,n*k){
		F(j,1,n){
			f[i][j]=f[i][j-1];
			F(l,1,min(k,i))
				f[i][j]=max(f[i][j],f[i-l][j-1]+c[l]);
		}
	}
	F(i,1,100000){
		if(!p[i]||!h[i]) continue;
		if(h[i]*k<=p[i]) {Ans+=(ll)c[k]*h[i]; continue;}
		Ans+=f[p[i]][h[i]];
	} printf("%I64d",Ans);
	return 0;
}