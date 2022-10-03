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
#define mp make_pair
#define fi first
#define se second
ll n,m,p;int c;
int main(){
	scanf("%lld",&n),m=n;
	if(n==1)return puts("1"),0;
	for(ll i=2;i*i<=n;++i)if(n%i==0){p=i;++c;while(n%i==0)n/=i;}
	if(n>1)p=n,++c;
	if(c>1)return puts("1"),0;
	printf("%lld\n",p);
	return 0;
}