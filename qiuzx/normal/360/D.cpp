//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#include <unordered_map>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
ll ksm(ll x,ll y,ll md)
{
	ll ret=1;
	while(y>0)
	{
		if(y&1)
		{
			ret=(ret*x)%md;
		}
		x=(x*x)%md;
		y>>=1;
	}
	return ret;
}
ll n,m,p,g,a[N],b[N],pw[N],dp[N];
vector<ll> v;
unordered_map<ll,ll> mp;
int main(){
//	freopen("in.txt","r",stdin);
	ll i,j;
	n=rint(),m=rint(),p=rint();
	for(i=1;i*i<=p-1;++i)
	{
		if((p-1)%i==0)
		{
			v.push_back(i);
			if(i*i!=p-1)
			{
				v.push_back((p-1)/i);
			}
		}
	}
	sort(v.begin(),v.end());
	for(i=0;i<v.size();++i)
	{
		mp[v[i]]=i;
	}
	for(i=0;i<n;++i)
	{
		a[i]=rint();
	}
	g=p-1;
	for(i=0;i<m;++i)
	{
		b[i]=rint();
		g=__gcd(g,b[i]);
	}
	for(i=0;i<n;++i)
	{
		a[i]=ksm(a[i],g,p);
		for(j=0;j<v.size();j++)
		{
			if(ksm(a[i],v[j],p)==1)
			{
				break;
			}
		}
		pw[i]=(p-1)/v[j];
	}
	for(i=0;i<n;++i)
	{
		for(j=v.size()-1;j>=0;--j)
		{
			ll nj=mp[v[j]*pw[i]/__gcd(v[j],pw[i])];
			dp[nj]-=dp[j];
		}
		++dp[mp[pw[i]]];
	}
	ll ans=0;
	for(i=0;i<v.size();++i)
	{
		ans+=dp[i]*((p-1)/v[i]);
	}
	cout<<ans<<endl;
	return 0;
}