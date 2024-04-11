#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define dF3(i,a,b) for(int i=(a)-1;i>=(b);--i)
using namespace std;typedef long long ll;typedef double ld;int INF=0x3f3f3f3f;int INF2=0x7fffffff;ll LNF=0x3f3f3f3f3f3f3f3f;ll LNF2=0x7fffffffffffffff;

ll n,k,M,D;
ll ans;

int main(){
	scanf("%I64d%I64d%I64d%I64d",&n,&k,&M,&D);
	F(i,1,D){
		if(i*k-k+1>n) break;
		ll c=n/(i*k-k+1);
		c=min(c,M);
		ans=max(ans,c*i);
	} printf("%I64d",ans);
	return 0;
}