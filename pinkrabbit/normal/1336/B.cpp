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
inline int qpow(int b,ll e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
pii a[MN];int t;ll b[2][4][MN];
int v(ll x){return 1<=x&&x<=1000000000;}
ll f(ll x,ll y,ll z){return (x-y)*(x-y)+(y-z)*(y-z)+(z-x)*(z-x);}
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	int n1,n2,n3,x;
	scanf("%d%d%d",&n1,&n2,&n3),t=0;
	F(i,1,n1)scanf("%d",&x),a[++t]=mkp(x,1);
	F(i,1,n2)scanf("%d",&x),a[++t]=mkp(x,2);
	F(i,1,n3)scanf("%d",&x),a[++t]=mkp(x,3);
	sort(a+1,a+t+1);
	F(j,1,3)b[0][j][0]=-infll,b[1][j][t+1]=infll;
	F(i,1,t){
		F(j,1,3)b[0][j][i]=b[0][j][i-1];
		b[0][a[i].se][i]=a[i].fi;
	}
	dF(i,t,1){
		F(j,1,3)b[1][j][i]=b[1][j][i+1];
		b[1][a[i].se][i]=a[i].fi;
	}
	ll ans=infll;
	F(i,1,t){
		F(w1,0,1)F(w2,0,1)F(w3,0,1)
			if(v(b[w1][1][i])&&v(b[w2][2][i])&&v(b[w3][3][i]))
				ans=min(ans,f(b[w1][1][i],b[w2][2][i],b[w3][3][i]));
	}
	printf("%lld\n",ans);
}	return 0;
}