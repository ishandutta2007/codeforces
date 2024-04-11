#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define INF 1000000000
#define LINF 1000000000000000000
#define N 100010
using namespace std;
int n,k;
ll ans,a[N];
vector<ll> poss;
map<ll,ll> sum;
void solve()
{
	int i,j;
	ll pre=1;
	scanf("%d%d",&n,&k);
	sum.clear();
	poss.clear();
	ans=0;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if(k==1)
	{
		poss.push_back(1);
	}
	else if(k==-1)
	{
		poss.push_back(-1);
		poss.push_back(1);
	}
	else
	{
		for(i=0;i<60;i++)
		{
			if(abs(pre)>(ll)100000000000000)
			{
				break;
			}
			poss.push_back(pre);
			pre*=k;
		}
	}
	pre=0;
	for(i=0;i<n;i++)
	{
		if(sum.count(pre))
		{
			sum[pre]++;
		}
		else
		{
			sum[pre]=1;
		}
		pre+=a[i];
		for(j=0;j<poss.size();j++)
		{
			if(sum.count(pre-poss[j]))
			{
				ans+=sum[pre-poss[j]];
			}
		}
	}
	printf("%lld\n",ans);
	return;
}
int main(){
	int T;
	T=1;
	while(T--)
	{
		solve();
	}
	return 0;
}