#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,pr[200069],z[640069],am[800][800],ky[200069];
pair<long long,pair<long long,long long>> a[200069];
vector<long long> al[869];

long long fd(long long x)
{
	if(pr[x]!=x)
	{
		pr[x]=fd(pr[x]);
	}
	return pr[x];
}

int main()
{
	long long rr,i,j,r,k,l,w,sz,c=0,cc=0;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&a[i].sc.fr,&a[i].sc.sc,&a[i].fr);
	}
	for(i=1;i<=d*2;i++)
	{
		pr[i]=i;
	}
	sort(a,a+m);
	for(i=0;i<min(d,m);i++)
	{
		k=a[i].sc.fr;
		l=a[i].sc.sc;
		w=a[i].fr;
		if(!ky[k])
		{
			c++;
			ky[k]=c;
			k=ky[k];
			for(j=1;j<c;j++)
			{
				am[k][j]=1e18;
				am[j][k]=1e18;
			}
		}
		else
		{
			k=ky[k];
		}
		if(!ky[l])
		{
			c++;
			ky[l]=c;
			l=ky[l];
			for(j=1;j<c;j++)
			{
				am[l][j]=1e18;
				am[j][l]=1e18;
			}
		}
		else
		{
			l=ky[l];
		}
		am[k][l]=min(am[k][l],w);
		am[l][k]=min(am[l][k],w);
		pr[fd(l)]=fd(k);
	}
	for(i=1;i<=c;i++)
	{
		al[fd(i)].push_back(i);
	}
	for(rr=1;rr<=c;rr++)
	{
		sz=al[rr].size();
		if(sz)
		{
			for(r=0;r<sz;r++)
			{
				for(i=0;i<sz;i++)
				{
					for(j=0;j<sz;j++)
					{
						k=al[rr][i];
						l=al[rr][j];
						w=al[rr][r];
						am[k][l]=min(am[k][l],am[k][w]+am[w][l]);
						if(r==sz-1&&i<j)
						{
							cc++;
							z[cc]=am[k][l];
						}
					}
				}
			}
		}
	}
	sort(z+1,z+cc+1);
	printf("%lld\n",z[d]);
}