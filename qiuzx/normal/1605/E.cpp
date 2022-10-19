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
#define N 200010
using namespace std;
ll prm[N],mu[N];
bool no_prm[N];
void get_mu()
{
	ll i,j,cnt=0;
	mu[1]=1;
	for(i=2;i<N;i++)
	{
		if(!no_prm[i])
		{
			prm[cnt++]=i;
			mu[i]=-1;
		}
		for(j=0;j<cnt;j++)
		{
			if(i*prm[j]>=N)
			{
				break;
			}
			no_prm[i*prm[j]]=true;
			if(i%prm[j]==0)
			{
				mu[i*prm[j]]=0;
				break;
			}
			mu[i*prm[j]]=-mu[i];
		}
	}
	return;
}
ll n,q,a[N],b[N],d[N],sum1[N],sum2[N];
vector<ll> v1,v2;
int main(){
	ll i,j,x;
	get_mu();
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&b[i]);
	}
	b[1]=0;
	ll tot=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j*j<=i;j++)
		{
			if(i%j==0)
			{
				d[i]+=mu[j]*(b[i/j]-a[i/j]);
				if(j*j!=i)
				{
					d[i]+=mu[i/j]*(b[j]-a[j]);
				}
			}
		}
		if(mu[i]==-1)
		{
			v1.push_back(d[i]);
		}
		else if(mu[i]==1)
		{
			v2.push_back(d[i]);
		}
		else
		{
			tot+=abs(d[i]);
		}
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	for(i=0;i<v1.size();i++)
	{
		sum1[i+1]=sum1[i]+v1[i];
	}
	for(i=0;i<v2.size();i++)
	{
		sum2[i+1]=sum2[i]+v2[i];
	}
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld",&x);
		ll pos=lower_bound(v2.begin(),v2.end(),-x)-v2.begin(),ans=0;
		ans+=(v2.size()-pos)*x+sum2[v2.size()]-sum2[pos];
		ans+=-pos*x-sum2[pos];
		pos=lower_bound(v1.begin(),v1.end(),x)-v1.begin();
		ans+=-(v1.size()-pos)*x+sum1[v1.size()]-sum1[pos];
		ans+=pos*x-sum1[pos];
		printf("%lld\n",ans+tot);
	}
	return 0;
}