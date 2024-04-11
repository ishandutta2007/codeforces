#include <bits/stdc++.h>

using namespace std;

long long n,fq[1069],sq[1069][1069];
queue<long long> vl[3];

void no()
{
	printf("NO\n");
	exit(0);
}

int main()
{
	long long i,j,ii,iii,k,ti,tj;
	
	scanf("%lld",&n);
	for(i=0;i<n*n;i++)
	{
		scanf("%lld",&k);
		fq[k]++;
	}
	for(i=1;i<=1000;i++)
	{
		for(j=2;j+1;j--)
		{
			for(;fq[i]>=1<<j;fq[i]-=1<<j)
			{
				vl[j].push(i);
			}
		}
	}
	if(n%2)
	{
		sq[n/2+1][n/2+1]=vl[0].front();
		vl[0].pop();
	}
	if(!vl[0].empty())
	{
		no();
	}
	if(n%2)
	{
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n/2;i++)
			{
				if(vl[1].empty())
				{
					for(iii=0;iii<2;iii++)
					{
						vl[1].push(vl[2].front());
					}
					vl[2].pop();
				}
				ti=n/2+1;
				tj=i;
				if(ii)
				{
					swap(ti,tj);
				}
				sq[ti][tj]=vl[1].front();
				vl[1].pop();
			}
		}
	}
	if(!vl[1].empty())
	{
		no();
	}
	for(i=1;i<=n/2;i++)
	{
		for(j=1;j<=n/2;j++)
		{
			sq[i][j]=vl[2].front();
			vl[2].pop();
		}
	}
	printf("YES\n");
	for(i=1;i<=n;i++)
	{
		if(i<=n/2)
		{
			ti=i;
		}
		else
		{
			ti=n+1-i;
		}
		for(j=1;j<=n;j++)
		{
			if(j<=n/2)
			{
				tj=j;
			}
			else
			{
				tj=n+1-j;
			}
			printf("%lld%c",sq[ti][tj]," \n"[j==n]);
		}
	}
}