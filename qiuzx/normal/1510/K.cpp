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
#define N 2010
using namespace std;
ll n;
vector<ll> a,b,res,ori;
vector<ll> cge1(vector<ll> t)
{
	vector<ll> rem;
	ll i;
	for(i=0;i<t.size();i+=2)
	{
		rem.push_back(t[i+1]);
		rem.push_back(t[i]);
	}
	return rem;
}
vector<ll> cge2(vector<ll> t)
{
	vector<ll> rem;
	ll i;
	for(i=t.size()/2;i<t.size();i++)
	{
		rem.push_back(t[i]);
	}
	for(i=0;i<t.size()/2;i++)
	{
		rem.push_back(t[i]);
	}
	return rem;
}
int main(){
	ll i,x;
	scanf("%lld",&n);
	n*=2;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&x);
		a.push_back(x);
	}
	res=a;
	ori=a;
	b=a;
	sort(res.begin(),res.end());
	i=0;
	if(a==res)
	{
		puts("0");
		return 0;
	}
	while(i==0||a!=ori)
	{
		a=cge1(a);
		b=cge2(b);
		i++;
		if(a==res||b==res)
		{
			printf("%lld\n",i);
			return 0;
		}
		a=cge2(a);
		b=cge1(b);
		i++;
		if(a==res||b==res)
		{
			printf("%lld\n",i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}