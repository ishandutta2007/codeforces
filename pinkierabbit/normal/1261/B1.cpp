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
int n,m,q,k;
int a[MN],p[MN],v[MN];
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i),p[i]=i;
	sort(p+1,p+n+1,[](int i,int j){return a[i]==a[j]?i<j:a[i]>a[j];});
	scanf("%d",&q);
	while(q--){
		int k,x;
		scanf("%d%d",&k,&x);
		F(i,1,k)v[i]=p[i];
		sort(v+1,v+k+1);
		printf("%d\n",a[v[x]]);
	}
}	return 0;
}