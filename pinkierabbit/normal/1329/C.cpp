#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 4000005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
inline int qpow(int b,ll e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,m;ll s;
int a[MN],b[MN];
int stk[MN],tp;
int ch(int i){
	if(!a[i<<1]&&!a[i<<1|1]){
		if(i<1<<m)return b[i]=0,0;
		return a[i]=0,1;
	}
	if(a[i<<1]>a[i<<1|1]){
		int v=a[i<<1];
		if(!ch(i<<1))return b[i]=0,0;
		return a[i]=v,1;
	}else{
		int v=a[i<<1|1];
		if(!ch(i<<1|1))return b[i]=0,0;
		return a[i]=v,1;
	}
}
void dfs(int i){
	if(b[i]){while(b[i])stk[++tp]=i,s-=a[i],ch(i);--tp,s+=a[i];}
	if(a[i<<1])dfs(i<<1);
	if(a[i<<1|1])dfs(i<<1|1);
}
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&m),s=tp=0;
	F2(i,1,2<<n)a[i]=0;
	F2(i,1,1<<n)scanf("%d",a+i),b[i]=1,s+=a[i];
	dfs(1);
	printf("%lld\n",s);
	F(i,1,tp)printf("%d ",stk[i]);puts("");
}	return 0;
}