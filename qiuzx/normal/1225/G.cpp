//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 2010
#define M (1<<16)+10
using namespace std;
ll n,k,a[20],cnt[20];
bool vis[N];
bitset<N> f[M];
void dfs(ll mask,ll v)
{
	ll i;
	if(mask==0)
	{
		return;
	}
	if(v*k<=2000&&f[mask][v*k])
	{
		for(i=0;i<n;i++)
		{
			if(vis[i])
			{
				cnt[i]++;
			}
		}
		dfs(mask,v*k);
		return;
	}
	for(i=0;i<n;i++)
	{
		if(mask&(1<<i))
		{
			if(v>=a[i]&&f[mask^(1<<i)][v-a[i]])
			{
				vis[i]=true;
				cnt[i]=0;
				dfs(mask^(1<<i),v-a[i]);
				break;
			}
		}
	}
	return;
}
int main(){
	ll i,j;
	scanf("%lld%lld",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=0;i<(1<<n);i++)
	{
		f[i]=0;
	}
	f[0][0]=1;
	for(i=0;i<(1<<n);i++)
	{
		for(j=2000;j>0;j--)
		{
			if(j%k==0&&f[i][j])
			{
				f[i][j/k]=1;
			}
		}
		for(j=0;j<n;j++)
		{
			if(!(i&(1<<j)))
			{
				f[i|(1<<j)]|=f[i]<<a[j];
			}
		}
	}
	if(!f[(1<<n)-1][1])
	{
		puts("NO");
		return 0;
	}
	memset(vis,false,sizeof(vis));
	dfs((1<<n)-1,1);
	vector<pair<ll,ll> > lft;
	for(i=0;i<n;i++)
	{
		lft.push_back(make_pair(cnt[i],a[i]));
	}
	puts("YES");
	for(j=1;j<n;j++)
	{
		sort(lft.begin(),lft.end());
		printf("%lld %lld\n",lft[0].S,lft[1].S);
		for(i=lft[0].S+lft[1].S;i%k==0;i/=k)
		{
			lft[0].F++;
		}
		lft[0].S=i;
		lft.erase(lft.begin()+1);
	}
	return 0;
}