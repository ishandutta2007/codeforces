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
int k1,k2;
int a[MN],b[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%*d%d%d",&k1,&k2);
	F(i,1,k1)scanf("%d",a+i);
	F(i,1,k2)scanf("%d",b+i);
	puts(*max_element(a+1,a+k1+1)>*max_element(b+1,b+k2+1)?"YES":"NO");
}	return 0;
}