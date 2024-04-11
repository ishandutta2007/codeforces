#include <bits/stdc++.h>

using namespace std;

long long n,m,dg[1569],sq[1569],zs=0;
array<long long,1569> a[1569];
map<array<long long,1569>,long long> fq,pst;
bitset<1569> spc;
queue<long long> q;

void ad(long long x)
{
	if(!dg[x])
	{
		q.push(x);
	}
}

int main()
{
	long long i,j,k;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&a[0][j]);
		}
		a[0][m+1]=0;
		fq[a[0]]++;
		a[0][m+1]=fq[a[0]];
		pst[a[0]]=i;
	}
	fq.clear();
	spc[1]=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&a[i][j]);
			dg[j]+=i-1&&a[i][j]<a[i-1][j];
		}
		fq[a[i]]++;
		a[i][m+1]=fq[a[i]];
	}
	for(i=1;i<=m;i++)
	{
		ad(i);
	}
	for(;!q.empty();)
	{
		k=q.front();
		q.pop();
		zs++;
		sq[zs]=k;
		for(i=1;i<=n;i++)
		{
			if(!spc[i]&&a[i][k]>a[i-1][k])
			{
				spc[i]=1;
				for(j=1;j<=m;j++)
				{
					if(a[i][j]<a[i-1][j])
					{
						dg[j]--;
						ad(j);
					}
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(!pst[a[i]]||(!spc[i]&&pst[a[i]]<pst[a[i-1]]))
		{
			printf("-1\n");
			return 0;
		}
	}
	printf("%lld\n",zs);
	for(i=zs;i;i--)
	{
		printf("%lld%c",sq[i]," \n"[i==1]);
	}
}