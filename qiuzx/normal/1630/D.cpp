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
#define N 1000010
using namespace std;
ll n,m,g,a[N],b[N],tot,s1,s2;
void calc(vector<ll> v)
{
	ll i,mn=INF,num=0;
	for(i=0;i<v.size();i++)
	{
		tot+=abs(v[i]);
		mn=min(mn,abs(v[i]));
		num+=(v[i]<0);
	}
	if(num&1)
	{
		s1+=mn;
	}
	else
	{
		s2+=mn;
	}
	return;
}
int main(){
	ll T,i,j;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		ll g=0;
		for(i=0;i<m;i++)
		{
			scanf("%lld",&b[i]);
			g=__gcd(g,b[i]);
		}
		tot=s1=s2=0;
		vector<ll> v;
		for(i=0;i<g;i++)
		{
			v.clear();
			for(j=i;j<n;j+=g)
			{
				v.push_back(a[j]);
			}
			calc(v);
		}
		printf("%lld\n",tot-2*min(s1,s2));
	}
	return 0;
}