#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<ctime>
using namespace std;
typedef long long ll;
int n,prime[1000005],p[1000005],pt,pn=1e6,mx=35;
ll a[1000005],ans;
map<ll,int> mp;
void getans(ll x)
{
	if(!x) return;
	for(int i=1;i<=pt;i++)
		if(x%prime[i]==0)
		{
			while(x%prime[i]==0) x/=prime[i];
			mp[prime[i]]++;
		}
	if(x!=1) mp[x]++;
}
void check(ll x)
{
	ll nw=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<x) nw+=x-a[i];
		else nw+=min(a[i]%x,(x-a[i]%x)%x);
		if(nw>ans) return;
	}
	if(nw<ans) ans=nw;
}
int main()
{
	srand(time(0));
	for(int i=2;i<=pn;i++)
	{
		if(!p[i]) prime[++pt]=i;
		for(int j=1;j<=pt&&i*prime[j]<=pn;j++)
		{
			p[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
	scanf("%d",&n);
	ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		if(a[i]%2) ans++;
	}
	random_shuffle(a+1,a+n+1);
	for(int i=1;i<=min(n,mx);i++)
	{
		getans(a[i]);
		getans(a[i]-1);
		getans(a[i]+1);
	}
	for(map<ll,int>::iterator it=mp.begin();it!=mp.end();it++)
		check(it->first);
	printf("%I64d",ans);
	return 0;
}