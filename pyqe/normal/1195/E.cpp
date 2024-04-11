#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nn,mm,a[3069][3069],aa[3069][3069],ml,ad,dv;
deque<pair<long long,long long>> dq;

int main()
{
	long long i,j,ii,z=0;
	
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&n,&m,&nn,&mm,&a[1][1],&ml,&ad,&dv);
	for(i=1;i<=n;i++)
	{
		for(j=1+(i==1);j<=m;j++)
		{
			a[i][j]=(a[i-(j==1)][(j+m-2)%m+1]*ml+ad)%dv;
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				for(;!dq.empty()&&dq.back().fr>=a[i][j];dq.pop_back());
				dq.push_back({a[i][j],j});
				if(j>=mm)
				{
					for(;dq.front().sc<j-mm+1;dq.pop_front());
					aa[i][j-mm+1]=dq.front().fr;
				}
			}
			for(;!dq.empty();dq.pop_front());
		}
		m-=mm-1;
		swap(n,m);
		swap(nn,mm);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				a[i][j]=aa[j][i];
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			z+=a[i][j];
		}
	}
	printf("%lld\n",z);
}