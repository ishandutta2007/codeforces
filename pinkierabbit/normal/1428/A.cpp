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
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	int a,b,c,d,x,y;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	x=abs(c-a),y=abs(d-b);
	if(x>y)swap(x,y);
	if(!y)puts("0");
	else if(!x)printf("%d\n",y);
	else printf("%d\n",x+y+2);
}	return 0;
}