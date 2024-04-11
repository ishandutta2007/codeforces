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
int a[MN],d[MN],per[MN];
ll ans;
int main(){int tests=1;scanf("%d",&tests);
while(tests--){int x,y;
	scanf("%d",&n),ans=0;
	F(i,1,n)scanf("%d",a+i),ans+=a[i],d[i]=-1,per[i]=i;
	F(i,2,n)scanf("%d%d",&x,&y),++d[x],++d[y];
	sort(per+1,per+n+1,[](int i,int j){return a[i]>a[j];});
	printf("\t\t%lld",ans);
	int j=1;
	F(i,2,n-1){
		while(!d[per[j]])++j;
		ans+=a[per[j]];
		--d[per[j]];
		printf(" %lld",ans);
	}puts("");
}	return 0;
}