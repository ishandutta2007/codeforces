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
int n,b;ll ans;
int a[MN],c[MN],m;
priority_queue<int,vector<int>,greater<int> >pq;
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%d",&n),b=__builtin_ctz(n);
//	printf("%d\n",b);
	F(i,1,n)scanf("%d",a+i);
	int o=0;
	F(i,1,n)if(a[i]!=-1)c[++m]=o?a[i]:0;else o=1;
//	F(i,1,m)printf("%d,",c[i]);puts("");
	dF(i,m,1){
		pq.push(c[i]);
		if(((i+1)&-(i+1))==i+1)ans+=pq.top(),pq.pop();
	}
	printf("%lld\n",ans);
}	return 0;
}