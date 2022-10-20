//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
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
ll n,m,k,a[N][6],ans=-1;
multiset<ll> val[6];
vector<ll> res;
int main(){
	ll i,j,r;
	n=rint(),m=rint(),k=rint();
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			a[i][j]=rint();
		}
	}
	for(i=0,r=0;i<n;i++)
	{
		if(i==r)
		{
			ll sum=0;
			for(j=0;j<m;j++)
			{
				sum+=a[r][j];
			}
			if(sum>k)
			{
				r++;
				continue;
			}
			for(j=0;j<m;j++)
			{
				val[j].insert(a[r][j]);
			}
			r++;
		}
		while(r<n)
		{
			ll sum=0;
			for(j=0;j<m;j++)
			{
				multiset<ll>::iterator it=val[j].end();
				it--;
				sum+=max(*it,a[r][j]);
			}
			if(sum>k)
			{
				break;
			}
			for(j=0;j<m;j++)
			{
				val[j].insert(a[r][j]);
			}
			r++;
		}
		if(ans<r-i)
		{
			ans=r-i;
			res.clear();
			for(j=0;j<m;j++)
			{
				multiset<ll>::iterator it=val[j].end();
				it--;
				res.push_back(*it);
			}
		}
		if(i!=r)
		{
			for(j=0;j<m;j++)
			{
				val[j].erase(val[j].lower_bound(a[i][j]));
			}
		}
	}
	if(ans<=0)
	{
		for(i=0;i<m;i++)
		{
			printf("0 ");
		}
		puts("");
		return 0;
	}
	for(i=0;i<res.size();i++)
	{
		printf("%lld ",res[i]);
	}
	puts("");
	return 0;
}