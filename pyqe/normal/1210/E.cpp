#include <bits/stdc++.h>

using namespace std;

const int mm=5;
int n,m,nn=0,nm,am[169][169],a[200069],ex[169],q[169];
array<int,mm> ky[169];
bitset<169> vtd;

int main()
{
	int i,j,r,l,sz,p;
	array<int,mm> ca;
	long long z=0;
	
	scanf("%d%d",&n,&m);
	for(i=0;i<mm;i++)
	{
		ca[i]=i;
	}
	for(;1;)
	{
		ky[nn]=ca;
		nn++;
		if(!next_permutation(ca.begin(),ca.begin()+m))
		{
			break;
		}
	}
	for(i=0;i<nn;i++)
	{
		for(j=0;j<nn;j++)
		{
			for(r=0;r<m;r++)
			{
				ca[r]=ky[i][ky[j][r]];
			}
			am[i][j]=lower_bound(ky,ky+nn,ca)-ky;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&ca[j]);
			ca[j]--;
		}
		a[i]=lower_bound(ky,ky+nn,ca)-ky;
	}
	for(i=1;i<=nn+1;i++)
	{
		ex[i]=n+1;
	}
	for(i=n;i;i--)
	{
		for(j=1;j<=nn;j++)
		{
			if(ex[j]>n||a[ex[j]]==a[i])
			{
				break;
			}
		}
		for(;j>1;j--)
		{
			ex[j]=ex[j-1];
		}
		ex[1]=i;
		vtd.reset();
		nm=1;
		q[1]=0;
		vtd[0]=1;
		for(j=1;j<=nn;j++)
		{
			if(ex[j]>n)
			{
				break;
			}
			if(!vtd[a[ex[j]]])
			{
				sz=nm;
				for(r=1;r<=sz;r++)
				{
					l=am[q[r]][a[ex[j]]];
					nm++;
					q[nm]=l;
					vtd[l]=1;
				}
				for(r=sz+1;r<=nm;r++)
				{
					for(p=sz+1;p<=r;p++)
					{
						l=am[q[p]][q[r]];
						if(!vtd[l])
						{
							nm++;
							q[nm]=l;
							vtd[l]=1;
						}
						l=am[q[r]][q[p]];
						if(!vtd[l])
						{
							nm++;
							q[nm]=l;
							vtd[l]=1;
						}
					}
				}
			}
			z+=(long long)nm*(ex[j+1]-ex[j]);
		}
	}
	printf("%lld\n",z);
}