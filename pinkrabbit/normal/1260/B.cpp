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
ll a,b;
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%lld%lld",&a,&b);
	if(!a&&!b)puts("YES");
	else if(!a||!b)puts("NO");
	else if(a==1&&b==1)puts("NO");
	else if((a+b)%3!=0)puts("NO");
	else{
		ll z=(a+b)/3;
		ll x=a-z,y=b-z;
		if(x>=0&&y>=0)puts("YES");
		else puts("NO");
	}
}	return 0;
}