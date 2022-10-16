#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,df[200069],c=0;
pair<long long,long long> a[200069];
map<long long,long long> fq;
vector<long long> v;

int main()
{
	long long i,j,e;
	bool bad;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].fr);
		a[i].sc=i;
	}
	sort(a+1,a+n+1);
	for(i=1;i<n;i++)
	{
		df[i]=a[i+1].fr-a[i].fr;
		if(!fq[df[i]])
		{
			c++;
			if(c>3)
			{
				printf("-1\n");
				return 0;
			}
			v.push_back(df[i]);
		}
		fq[df[i]]++;
	}
	if(c==1)
	{
		printf("%lld\n",a[1].sc);
	}
	else if(c==2&&fq[df[1]]==1)
	{
		printf("%lld\n",a[1].sc);
	}
	else if(c==2&&fq[df[n-1]]==1)
	{
		printf("%lld\n",a[n].sc);
	}
	else
	{
		for(i=0;i<c;i++)
		{
			bad=0;
			for(j=1;j<n;j++)
			{
				if(df[j]!=v[i])
				{
					break;
				}
			}
			if(j==n-1||df[j]+df[j+1]!=v[i])
			{
				continue;
			}
			e=j+1;
			for(j+=2;j<n;j++)
			{
				if(df[j]!=v[i])
				{
					bad=1;
					break;
				}
			}
			if(!bad)
			{
				printf("%lld\n",a[e].sc);
				return 0;
			}
		}
		printf("-1\n");
	}
}