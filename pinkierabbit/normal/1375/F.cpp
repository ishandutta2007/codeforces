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
ll a,b,c;
int main(){
	scanf("%lld%lld%lld",&a,&b,&c);
	puts("First");fflush(stdout);
	puts("10000000000");fflush(stdout);
	int id;
	scanf("%d",&id);
	(id==1?a:id==2?b:c)+=10000000000;
	ll v=max({a,b,c})*3-a-b-c;
	printf("%lld\n",v);fflush(stdout);
	scanf("%d",&id);
	(id==1?a:id==2?b:c)+=v;
	v=(max({a,b,c})-min({a,b,c}))/2;
	printf("%lld\n",v);fflush(stdout);
	return 0;
}