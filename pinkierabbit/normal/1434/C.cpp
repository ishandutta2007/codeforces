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
int a,b,c,d;
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if((ll)b*c<a){puts("-1");continue;}
	int x=a/((ll)d*b);
//	printf("x=%d, x*d=%d <= %d=c\n",x,x*d,c);
	printf("%lld\n",(ll)(x+1)*a-((ll)x*(x+1)/2)*b*d);
}	return 0;
}