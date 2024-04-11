#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],ps[200069],sq[200069];
vector<long long> vl[200069];

int main()
{
	long long t,rr,i,j,k,sz;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			vl[i].clear();
			sq[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			vl[a[i]].push_back(k);
		}
		for(i=1;i<=n;i++)
		{
			sort(vl[i].begin(),vl[i].end(),greater<long long>());
			sz=vl[i].size();
			for(j=0;j<sz;j++)
			{
				ps[j+1]=ps[j]+vl[i][j];
			}
			for(j=1;j<=sz;j++)
			{
				sq[j]+=ps[sz/j*j];
			}
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==n]);
		}
	}
}