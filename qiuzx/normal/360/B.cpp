//sol O(nlogn)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 2020
using namespace std;
ll n,k,a[N],dp[N][2],bit[N];
vector<pair<ll,ll> > fd,bk;
void update(ll x,ll v)
{
	x++;
	while(x<N)
	{
		bit[x]=min(bit[x],v);
		x+=(x&(-x));
	}
	return;
}
ll query(ll x)
{
	x++;
	ll ret=LINF;
	while(x>0)
	{
		ret=min(ret,bit[x]);
		x-=(x&(-x));
	}
	return ret;
}
bool cmp(pair<ll,ll> a,pair<ll,ll> b)
{
	if(a.F<b.F)
	{
		return true;
	}
	if(a.F>b.F)
	{
		return false;
	}
	if(a.S>b.S)
	{
		return true;
	}
	return false;
}
bool check(ll x)
{
	ll i,j;
	memset(bit,63,sizeof(bit));
	fd.clear();
	bk.clear();
	for(i=0;i<n;i++)
	{
		//a[i]<=a[i-j-1]+(j+1)*x --> a[i]-i*x<=a[j]-j*x
		//a[i]>=a[i-j-1]-(j+1)*x --> a[i]+i*x>=a[j]+j*x
		fd.push_back(make_pair(a[i]-i*x,i));
		bk.push_back(make_pair(a[i]+i*x,i));
		dp[i][0]=dp[i][1]=2*INF;
	}
	sort(fd.begin(),fd.end(),cmp);
	sort(bk.begin(),bk.end());
	for(i=fd.size()-1;i>=0;i--)
	{
		j=upper_bound(bk.begin(),bk.end(),make_pair(fd[i].F+2*x*fd[i].S,(ll)INF))-bk.begin()-1;
		dp[fd[i].S][0]=min((ll)0,query(j))+fd[i].S;
		update(j,dp[fd[i].S][0]-fd[i].S-1);
	}
	dp[0][1]=1;
	for(i=1;i<n;i++)
	{
		dp[i][1]=min(dp[i][1],min(dp[i-1][0],dp[i-1][1])+1);
	}
	if(dp[n-1][0]<=k||dp[n-1][1]<=k)
	{
		return true;
	}
	return false;
}
int main(){
	ll i,l,r,mid;
	scanf("%lld%lld",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	l=0;
	r=2*INF+10;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	printf("%lld\n",l);
	return 0;
}