#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 105
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,m;
int a[MN][MN],b[MN][MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	ll ans=0;
	scanf("%d%d",&n,&m);
	F(i,1,n)F(j,1,m)scanf("%d",&a[i][j]),b[i][j]=0;
	F(i,1,n)F(j,1,m)if(!b[i][j]){
		pii x[4]={{i,j},{n-i+1,j},{i,m-j+1},{n-i+1,m-j+1}};
		sort(x,x+4);
		int c=unique(x,x+4)-x;
		vector<int> y;
		F2(k,0,c)b[x[k].fi][x[k].se]=1,y.pb(a[x[k].fi][x[k].se]);
//		for(int z:y)printf("%d,",z);
//		puts("");
		sort(y.begin(),y.end());
		int ww=y[c/2];
		for(int z:y)ans+=(int)(abs(z-ww)+0.5);
	}
	printf("%lld\n",ans);
}	return 0;
}