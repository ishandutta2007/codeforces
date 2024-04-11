#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,fq[4],zs=0;
pair<long long,long long> a[100069];
vector<long long> v[4],sq;

int main()
{
	long long i,ii,u;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].fr,&a[i].sc);
		a[i].fr+=1000000;
		a[i].sc+=1000000;
	}
	for(;1;)
	{
		for(i=0;i<4;i++)
		{
			v[i].clear();
			fq[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			u=abs(a[i].fr%2)*2+abs(a[i].sc%2);
			v[u].push_back(i);
			fq[u]++;
			a[i].fr/=2;
			a[i].sc/=2;
		}
		if(fq[0]+fq[3]&&fq[1]+fq[2])
		{
			for(ii=0;ii<=3;ii+=3)
			{
				for(i=0;i<fq[ii];i++)
				{
					sq.push_back(v[ii][i]);
					zs++;
				}
			}
			break;
		}
		else if(fq[0]&&fq[3])
		{
			for(i=0;i<fq[0];i++)
			{
				sq.push_back(v[0][i]);
				zs++;
			}
			break;
		}
		else if(fq[1]&&fq[2])
		{
			for(i=0;i<fq[1];i++)
			{
				sq.push_back(v[1][i]);
				zs++;
			}
			break;
		}
	}
	printf("%lld\n",zs);
	for(i=0;i<zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs-1]);
	}
}