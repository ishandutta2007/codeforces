#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 1000005
#define MM 10005
#define MG 1005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,m,g,r;
int a[MM];
int d[MM][MG];
pii _q[2*MM*MG],*q=_q+MM*MG;
int lb,rb;
int main(){
	scanf("%d%d",&n,&m);
	F(i,1,m)scanf("%d",a+i);
	sort(a+1,a+m+1);
	scanf("%d%d",&g,&r);
	memset(d,-1,sizeof d);
	d[1][0]=0;
	q[lb=rb=0]={1,0};
	while(lb<=rb){
		pii p=q[lb++];
		int i=p.fi,j=p.se;
		if(i>1&&j+a[i]-a[i-1]<g&&!~d[i-1][j+a[i]-a[i-1]])
			d[i-1][j+a[i]-a[i-1]]=d[i][j],
			q[--lb]={i-1,j+a[i]-a[i-1]};
		if(i<m&&j+a[i+1]-a[i]<g&&!~d[i+1][j+a[i+1]-a[i]])
			d[i+1][j+a[i+1]-a[i]]=d[i][j],
			q[--lb]={i+1,j+a[i+1]-a[i]};
		if(i>1&&j+a[i]-a[i-1]==g&&!~d[i-1][0])
			d[i-1][0]=d[i][j]+1,
			q[++rb]={i-1,0};
		if(i<m&&j+a[i+1]-a[i]==g&&!~d[i+1][0])
			d[i+1][0]=d[i][j]+1,
			q[++rb]={i+1,0};
	}
//	F(i,1,m)F2(j,0,g)if(~d[i][j])printf("d[%d][%d]=%d\n",i,j,d[i][j]);
	ll ans=infll;
	F(i,1,m)if(n-a[i]<=g)if(~d[i][0])ans=min(ans,(ll)(g+r)*d[i][0]+(n-a[i]));
	printf("%lld\n",ans==infll?-1:ans);
	return 0;
}