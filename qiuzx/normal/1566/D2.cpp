//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 310
using namespace std;
ll n,m,a[N*N],plc[N*N],ans;
bool occ[N][N];
vector<pair<ll,ll> > ord;
bool cmp(pair<ll,ll> x,pair<ll,ll> y)
{
	return (x.F==y.F)?(x.S>y.S):(x.F<y.F);
}
int main(){
	ll T,i,j,x,y;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&m);
		ord.clear();
		for(i=0;i<n*m;i++)
		{
			occ[i/m][i%m]=false;
			scanf("%lld",&a[i]);
			ord.push_back(make_pair(a[i],i));
		}
		sort(ord.begin(),ord.end());
		for(i=0;i<n;i++)
		{
			sort(ord.begin()+i*m,ord.begin()+(i+1)*m,cmp);
		}
		for(i=0;i<ord.size();i++)
		{
			plc[ord[i].S]=i;
		}
		ans=0;
		for(i=0;i<n*m;i++)
		{
			x=plc[i]/m;
			y=plc[i]%m;
			for(j=0;j<y;j++)
			{
				if(occ[x][j])
				{
					ans++;
				}
			}
			occ[x][y]=true;
		}
		printf("%lld\n",ans);
	}
	return 0;
}