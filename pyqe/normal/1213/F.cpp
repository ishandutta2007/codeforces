#include <bits/stdc++.h>

using namespace std;

long long n,d,a[200069],pst[200069],pr[200069],z[200069];

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
	long long i,k,l=-1,j,c=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		pst[a[i]]=i;
		pr[i]=i;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(l!=-1)
		{
			for(j=pst[l];j>pst[k];j=pst[pr[a[j-1]]])
			{
				pr[fd(a[j])]=fd(a[j-1]);
			}
		}
		l=k;
	}
	for(i=1;i<=n;i++)
	{
		if(fd(a[i])==a[i])
		{
			c++;
		}
		z[a[i]]=c;
	}
	if(c<d)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
		for(i=1;i<=n;i++)
		{
			printf("%c",(char)min(z[i],(long long)26)-1+'a');
		}
		printf("\n");
	}
}