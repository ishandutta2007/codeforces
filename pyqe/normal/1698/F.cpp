#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[2][569],am[2][569][569],ls[569],zs;
pair<long long,long long> sq[250069];

inline void op(long long lh,long long rh)
{
	long long i;
	
	zs++;
	sq[zs]={lh,rh};
	for(i=1;i<rh-lh+2-i;i++)
	{
		swap(a[0][lh-1+i],a[0][lh-1+rh-lh+2-i]);
	}
}

int main()
{
	long long t,rr,i,j,r,ii,k,l,k2,l2;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					am[ii][i][j]=0;
				}
			}
			for(i=1;i<=n;i++)
			{
				scanf("%lld",&a[ii][i]);
				if(i>1)
				{
					k=a[ii][i-1];
					l=a[ii][i];
					if(k>l)
					{
						swap(k,l);
					}
					am[ii][k][l]++;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(am[0][i][j]!=am[1][i][j])
				{
					break;
				}
			}
			if(j<=n)
			{
				break;
			}
		}
		if(i<=n||a[0][1]!=a[1][1]||a[0][n]!=a[1][n])
		{
			printf("NO\n");
			continue;
		}
		zs=0;
		for(i=1;i<=n;i++)
		{
			if(a[0][i]!=a[1][i])
			{
				k=a[1][i-1];
				l=a[1][i];
				if(k>l)
				{
					swap(k,l);
				}
				for(j=i;j<=n;j++)
				{
					k2=a[0][j-1];
					l2=a[0][j];
					if(k2>l2)
					{
						swap(k2,l2);
					}
					if(k2==k&&l2==l)
					{
						break;
					}
				}
				if(a[0][j-1]!=a[1][i])
				{
					for(r=1;r<=n;r++)
					{
						ls[r]=0;
					}
					for(r=i-1;r<j;r++)
					{
						ls[a[0][r]]=r;
					}
					for(r=j;r<=n;r++)
					{
						if(ls[a[0][r]])
						{
							op(ls[a[0][r]],r);
							break;
						}
					}
				}
				k=a[1][i-1];
				l=a[1][i];
				for(j=i;j<=n;j++)
				{
					k2=a[0][j-1];
					l2=a[0][j];
					if(k2==l&&l2==k)
					{
						break;
					}
				}
				op(i-1,j);
			}
		}
		printf("YES\n%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			printf("%lld %lld\n",sq[i].fr,sq[i].sc);
		}
	}
}