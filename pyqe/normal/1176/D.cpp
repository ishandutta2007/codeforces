#include <bits/stdc++.h>

using namespace std;

long long n,bg[3000069],pm[300069],c=0,a[400069];
bitset<3000069> vtd;
bitset<400069> tkn;
vector<long long> sq;
priority_queue<long long> pq;

int main()
{
	long long i,j;
	
	for(i=2;i<=3000000;i++)
	{
		if(!vtd[i])
		{
			c++;
			pm[c]=i;
			for(j=i*i;j<=3000000;j+=i)
			{
				if(!vtd[j])
				{
					vtd[j]=1;
					bg[j]=j/i;
				}
			}
		}
	}
	scanf("%lld",&n);
	for(i=1;i<=n+n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+n+1);
	for(i=n+n;i>0;i--)
	{
		if(!pq.empty()&&a[i]==pq.top())
		{
			tkn[i]=1;
			pq.pop();
		}
		else if(vtd[a[i]])
		{
			sq.push_back(a[i]);
			tkn[i]=1;
			pq.push(bg[a[i]]);
		}
	}
	for(i=1;i<=n+n;i++)
	{
		if(!tkn[i])
		{
			if(!pq.empty()&&a[i]==-pq.top())
			{
				tkn[i]=1;
				pq.pop();
			}
			else
			{
				sq.push_back(a[i]);
				tkn[i]=1;
				pq.push(-pm[a[i]]);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n-1]);
	}
}