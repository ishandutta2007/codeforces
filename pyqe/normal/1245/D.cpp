#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,pst[2069][2],pr[2069],d[2069],z=0,sz=0,sz2=0;
pair<long long,pair<long long,long long>> a[2002069];
bitset<2069> spc;
vector<long long> sq;
vector<pair<long long,long long>> sq2;

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
	long long i,j,ii,c=0,k,l,w;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld",&pst[i][ii]);
		}
		pr[i]=i;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[c]={k,{i,i}};
		c++;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",d+i);
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			a[c]={(d[i]+d[j])*(abs(pst[i][0]-pst[j][0])+abs(pst[i][1]-pst[j][1])),{i,j}};
			c++;
		}
	}
	sort(a,a+c);
	for(i=0;i<c;i++)
	{
		w=a[i].fr;
		k=a[i].sc.fr;
		l=a[i].sc.sc;
		if(k==l)
		{
			if(!spc[fd(k)])
			{
				spc[fd(k)]=1;
				z+=w;
				sq.push_back(k);
				sz++;
			}
		}
		else
		{
			if(fd(k)!=fd(l)&&!(spc[fd(k)]&&spc[fd(l)]))
			{
				if(spc[fd(k)])
				{
					pr[fd(l)]=fd(k);
				}
				else
				{
					pr[fd(k)]=fd(l);
				}
				z+=w;
				sq2.push_back({k,l});
				sz2++;
			}
		}
	}
	printf("%lld\n%lld\n",z,sz);
	for(i=0;i<sz;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==sz-1]);
	}
	printf("%lld\n",sz2);
	for(i=0;i<sz2;i++)
	{
		printf("%lld %lld\n",sq2[i].fr,sq2[i].sc);
	}
}