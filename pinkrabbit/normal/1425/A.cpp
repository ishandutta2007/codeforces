#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
ll f(ll n){
	if(!n)return 0;
	if(n&1)return n-f(n-1);
	if(n>=12&&n%4==0)return n-f(n-1);
	return n-f(n/2);
}
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	ll n;
	scanf("%lld",&n);
	printf("%lld\n",f(n));
}	return 0;
}