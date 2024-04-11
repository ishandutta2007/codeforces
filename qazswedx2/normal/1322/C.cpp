#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
pii b[500005];
ll c[500005];
int t,n,m,mod,bt,bs;
vector<int> val[500005];
ll gcd(ll a,ll b)
{
	if(!b) return a;
	return gcd(b,a%b);
}
ll gethsh(int x)
{
	ll ans=(int)val[x].size();
	for(int i=0;i<(int)val[x].size();i++)
		ans=(1ll*ans*bs%mod+val[x][i])%mod;
//	printf("x=%d,ans=%I64d\n",x,ans);
	return ans;
}
int isel(int x,int y)
{
	if(val[x].size()!=val[y].size()) return 0;
	for(int i=0;i<(int)val[x].size();i++)
		if(val[x][i]!=val[y][i])
			return 0;
	return 1;
}
int main()
{
	srand(time(0));
	rand();
	scanf("%d",&t);
	while(t--)
	{
		mod=1e13+1+rand()%10000;
		bs=1000+1+rand()%10000;
		bt=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%I64d",&c[i]);
		for(int i=1;i<=n;i++)
			val[i].clear();
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			val[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
		{
			sort(val[i].begin(),val[i].end());
			if(!val[i].empty())
				b[++bt]=make_pair(gethsh(i),i);
		}
		sort(b+1,b+bt+1);
		for(int l=1,r;l<=bt;l=r+1)
		{
			r=l;
			while(r<bt&&b[r+1].first==b[l].first) r++;
			for(int i=l+1;i<=r;i++)
				for(int j=l;j<i;j++)
				{
					int ni=b[i].second,nj=b[j].second;
					if(isel(ni,nj))
					{
						c[nj]+=c[ni],c[ni]=0;
						break;
					}
				}
		}
		ll ans=0;
		for(int i=1;i<=bt;i++)
		{
		//	printf("i=%d,%I64d,%I64d,%d\n",i,c[b[i].second],b[i].first,b[i].second);
			ans=gcd(ans,c[b[i].second]);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}