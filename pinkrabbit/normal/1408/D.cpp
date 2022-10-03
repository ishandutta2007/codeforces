#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 2005
#define MM 4000005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,m,k;
pii a[MN],b[MN];
pii c[MM],d[MM];
int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n)scanf("%d%d",&a[i].fi,&a[i].se);
	F(i,1,m)scanf("%d%d",&b[i].fi,&b[i].se);
	F(i,1,n)F(j,1,m)if(a[i].fi<=b[j].fi&&a[i].se<=b[j].se)c[++k]={b[j].fi-a[i].fi,b[j].se-a[i].se};
	c[++k]={inf,-1},c[++k]={-1,inf};
	sort(c+1,c+k+1);
	int j=0;
	F(i,1,k){
		while(j&&d[j].fi<=c[i].fi&&d[j].se<=c[i].se)--j;
		d[++j]=c[i];
	}
	k=j;
//	F(i,1,k)printf("(%d,%d)\n",d[i].fi,d[i].se);
	int ans=inf;
	F(i,2,k)ans=min(ans,d[i-1].fi+d[i].se);
	printf("%d\n",ans+2);
	return 0;
}