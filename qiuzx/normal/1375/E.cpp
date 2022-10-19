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
#define N 1010
using namespace std;
ll n,a[N],q[N],p[N];
vector<pair<ll,ll> > val,ans;
int main(){
	ll i,j;
	pair<ll,ll> pr;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		val.push_back(make_pair(a[i],i));
	}
	sort(val.begin(),val.end());
	for(i=0;i<n;i++)
	{
		pr=make_pair(a[i],i);
		q[i]=lower_bound(val.begin(),val.end(),pr)-val.begin();
	}
	for(i=0;i<n;i++)
	{
		p[q[i]]=i;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j+1<n;j++)
		{
			if(p[j]>p[j+1])
			{
				ans.push_back(make_pair(p[j+1],p[j]));
				swap(p[j],p[j+1]);
			}
		}
	}
	printf("%lld\n",(ll)ans.size());
	for(i=0;i<ans.size();i++)
	{
		printf("%lld %lld\n",ans[i].F+1,ans[i].S+1);
	}
	return 0;
}