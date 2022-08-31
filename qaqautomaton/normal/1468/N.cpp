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
	int c1,c2,c3,a1,a2,a3,a4,a5;
	scanf("%d%d%d%d%d%d%d%d",&c1,&c2,&c3,&a1,&a2,&a3,&a4,&a5);
	c1-=a1,c2-=a2,c3-=a3;
	if(c1<0||c2<0||c3<0)puts("no");
	else{
		a4-=min(a4,c1);
		a5-=min(a5,c2);
		if(a4+a5<=c3)puts("yes");
		else puts("no");
	}
}	return 0;
}