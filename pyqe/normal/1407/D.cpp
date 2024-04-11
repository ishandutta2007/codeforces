#include <bits/stdc++.h>

using namespace std;

long long n,nn,a[300069],sk[300069],nr[300069],inf=1e18;
vector<long long> al[300069];
queue<long long> q;

int main()
{
	long long i,ii,iii,u,uu,k,l,sz;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		nr[i]=inf;
	}
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		for(iii=0;iii<2;iii++)
		{
			uu=!iii*2-1;
			nn=0;
			for(i=1+(n-1)*iii;i&&i<=n;i+=uu)
			{
				for(;nn&&a[sk[nn]]*u<a[i]*u;nn--);
				if(nn)
				{
					al[min(i,sk[nn])].push_back(max(i,sk[nn]));
				}
				nn++;
				sk[nn]=i;
			}
		}
	}
	q.push(1);
	nr[1]=0;
	for(;!q.empty();)
	{
		k=q.front();
		q.pop();
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i];
			if(nr[k]+1<nr[l])
			{
				q.push(l);
				nr[l]=nr[k]+1;
			}
		}
	}
	printf("%lld\n",nr[n]);
}