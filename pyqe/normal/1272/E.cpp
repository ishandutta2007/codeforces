#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[200069],nr[200069];
bitset<200069> vtd;
vector<long long> al[200069];
queue<pair<long long,long long>> q;

int main()
{
	long long i,ii,k,l,w,sz;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		for(ii=0;ii<2;ii++)
		{
			l=i+(ii*2-1)*a[i];
			if(l>0&&l<=n)
			{
				al[l].push_back(i);
			}
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			if(a[i]%2!=ii)
			{
				q.push({i,0});
			}
		}
		for(;!q.empty();)
		{
			k=q.front().fr;
			w=q.front().sc;
			q.pop();
			sz=al[k].size();
			for(i=0;i<sz;i++)
			{
				l=al[k][i];
				if(a[l]%2==ii&&!vtd[l])
				{
					q.push({l,w+1});
					vtd[l]=1;
					nr[l]=w+1;
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(vtd[i])
		{
			k=nr[i];
		}
		else
		{
			k=-1;
		}
		printf("%lld%c",k," \n"[i==n]);
	}
}