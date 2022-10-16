#include <bits/stdc++.h>

using namespace std;

long long n,m,sz=0,sq[200069];
queue<long long> q;
map<long long,bool> vtd;

int main()
{
	long long i,k;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(!vtd[k])
		{
			if(sz==m)
			{
				vtd[q.front()]=0;
				q.pop();
				sz--;
			}
			q.push(k);
			sz++;
			vtd[k]=1;
		}
	}
	printf("%lld\n",sz);
	for(i=1;i<=sz;i++)
	{
		sq[i]=q.front();
		q.pop();
	}
	for(i=sz;i;i--)
	{
		printf("%lld%c",sq[i]," \n"[i==1]);
	}
}