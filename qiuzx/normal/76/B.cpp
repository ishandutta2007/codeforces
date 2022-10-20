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
#define N 100010
using namespace std;
ll n,m,y0,y1;
vector<ll> a,b;
multiset<ll> pos[N];
ll calc(ll x)
{
	if(pos[x].size()<=1)
	{
		return 0;
	}
	multiset<ll>::iterator it,it2;
	it=pos[x].begin();
	it2=it;
	it2++;
	if((*it)==(*it2))
	{
		return pos[x].size()-2;
	}
	return pos[x].size()-1;
}
ll cost()
{
	ll i,ret=0;
	for(i=0;i<m;i++)
	{
		ret+=calc(i);
	}
	return ret;
}
int main(){
	ll i,j;
	scanf("%lld%lld%lld%lld",&n,&m,&y0,&y1);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&j);
		a.push_back(j);
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld",&j);
		b.push_back(j);
	}
	for(i=0,j=0;i<n;i++)
	{
		j=lower_bound(b.begin(),b.end(),a[i])-b.begin();
		if(j==0)
		{
			pos[0].insert(abs(a[i]-b[0]));
		}
		else if(j==m)
		{
			pos[j-1].insert(abs(a[i]-b[j-1]));
		}
		else
		{
			if(abs(a[i]-b[j])<abs(a[i]-b[j-1]))
			{
				pos[j].insert(abs(a[i]-b[j]));
			}
			else if(abs(a[i]-b[j])>abs(a[i]-b[j-1]))
			{
				pos[j-1].insert(abs(a[i]-b[j-1]));
			}
			else
			{
				if(pos[j-1].empty())
				{
					pos[j-1].insert(abs(a[i]-b[j-1]));
				}
				else if((*(pos[j-1].begin()))==abs(a[i]-b[j-1]))
				{
					pos[j-1].insert(abs(a[i]-b[j-1]));
				}
				else
				{
					pos[j].insert(abs(a[i]-b[j]));
				}
			}
		}
	}
	printf("%lld\n",cost());
	return 0;
}