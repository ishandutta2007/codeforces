#include <bits/stdc++.h>

using namespace std;

long long n,d,wg[200069],a[200069];
priority_queue<long long> pq;

int main()
{
	long long i,j,z=0;
	string s;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",wg+i);
	}
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
	}
	for(i=1;i<=n;i++)
	{
		pq.push(wg[i]);
		if(i==n||a[i]!=a[i+1])
		{
			for(j=0;!pq.empty();pq.pop(),j++)
			{
				if(j<d)
				{
					z+=pq.top();
				}
			}
		}
	}
	printf("%lld\n",z);
}