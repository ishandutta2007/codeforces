#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,na=0,nd=0,at[1069],de[1069],a[1069];
priority_queue<pair<long long,long long>> pq;
bitset<1069> vtd;

int main()
{
	long long i,j,k,sm,mx=-1e18;
	string s;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		cin>>s;
		scanf("%lld",&k);
		if(s[0]=='A')
		{
			na++;
			at[na]=k;
		}
		else
		{
			nd++;
			de[nd]=k;
		}
	}
	sort(at+1,at+na+1);
	sort(de+1,de+nd+1);
	for(i=1;i<=m;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+m+1);
	for(i=0;i<=m;i++)
	{
		sm=0;
		for(j=1;j<=na&&j+i<=m;j++)
		{
			k=a[j+i]-at[j];
			if(k<0)
			{
				j=-1;
				break;
			}
			sm+=k;
		}
		if(j!=-1)
		{
			mx=max(mx,sm);
		}
	}
	for(j=m,i=nd;i;i--)
	{
		for(;j&&a[j]>de[i];j--)
		{
			pq.push({-a[j],j});
		}
		if(pq.empty())
		{
			i=-1;
			break;
		}
		vtd[pq.top().sc]=1;
		pq.pop();
	}
	if(i!=-1)
	{
		sm=0;
		for(j=m,i=na;i;i--)
		{
			for(;j&&vtd[j];j--);
			if(!j||a[j]<at[i])
			{
				i=-1;
				break;
			}
			sm-=at[i];
		}
		if(i!=-1)
		{
			for(i=1;i<=m;i++)
			{
				sm+=a[i]*!vtd[i];
			}
			mx=max(mx,sm);
		}
	}
	printf("%lld\n",mx);
}