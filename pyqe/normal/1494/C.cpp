#include <bits/stdc++.h>

using namespace std;

long long n,m,nn[2],nm[2],a[2][200069],ex[2][200069],sx[200069];

int main()
{
	long long t,rr,i,j,ii,k,e,mx,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(ii=0;ii<2;ii++)
		{
			nn[ii]=0;
			nm[ii]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			e=k<0;
			nn[e]++;
			a[e][nn[e]]=abs(k);
		}
		for(i=1;i<=m;i++)
		{
			scanf("%lld",&k);
			e=k<0;
			nm[e]++;
			ex[e][nm[e]]=abs(k);
		}
		z=0;
		for(ii=0;ii<2;ii++)
		{
			sort(a[ii]+1,a[ii]+nn[ii]+1);
			sort(ex[ii]+1,ex[ii]+nm[ii]+1);
			sx[nm[ii]+1]=0;
			for(i=nm[ii];i;i--)
			{
				k=lower_bound(a[ii]+1,a[ii]+nn[ii]+1,ex[ii][i])-a[ii];
				sx[i]=sx[i+1]+(k<=nn[ii]&&a[ii][k]==ex[ii][i]);
			}
			mx=0;
			for(j=0,i=1;i<=nm[ii];i++)
			{
				for(;j<nn[ii]&&a[ii][j+1]<=ex[ii][i];j++);
				k=lower_bound(ex[ii]+1,ex[ii]+nm[ii]+1,ex[ii][i]-j+1)-ex[ii];
				mx=max(mx,i-k+1+sx[i+1]);
			}
			z+=mx;
		}
		printf("%lld\n",z);
	}
}