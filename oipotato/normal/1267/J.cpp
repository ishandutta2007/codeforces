#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
int n,c[2000010];
vector<int>g;
int cal(int s)
{
	int tans=0;
	for(auto i:g)
	{
		int k=(i-1)/s+1;
		if((s-1)*k<=i&&i<=s*k)tans+=k;else return 2*n;
	}
	return tans;
}
int main()
{
	int T;scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&n);
		rep(i,n)c[i]=0;
		rep(i,n){int x;scanf("%d",&x);c[x]++;}
		g.clear();
		int mi=n;
		rep(i,n)if(c[i])g.pb(c[i]),mi=min(mi,c[i]);
		int ans=2*n;
		for(int i=mi+1;i;i--)ans=min(ans,cal(i));
		printf("%d\n",ans);
	}
	return 0;
}