#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,a[169][169],sm[2][169],sq[169],zs;
multiset<pair<long long,pair<bool,long long>>> ms;
multiset<pair<long long,pair<bool,long long>>>::iterator it;
bitset<169> vtd[2];

int main()
{
	long long i,j,ii,kk,k,w,ww;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&a[i][j]);
			sm[0][i]+=a[i][j];
			sm[1][j]+=a[i][j];
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			ms.insert({sm[ii][i],{ii,i}});
		}
		swap(n,m);
	}
	for(it=ms.begin();(*it).fr<0;it=ms.begin())
	{
		kk=(*it).sc.fr;
		k=(*it).sc.sc;
		w=(*it).fr;
		if(kk)
		{
			swap(n,m);
		}
		for(i=1;i<=m;i++)
		{
			ms.erase(ms.find({sm[!kk][i],{!kk,i}}));
			if(kk)
			{
				swap(k,i);
			}
			a[k][i]*=-1;
			ww=a[k][i];
			if(kk)
			{
				swap(k,i);
			}
			sm[!kk][i]+=ww*2;
			ms.insert({sm[!kk][i],{!kk,i}});
		}
		if(kk)
		{
			swap(n,m);
		}
		ms.erase(it);
		sm[kk][k]*=-1;
		ms.insert({sm[kk][k],{kk,k}});
		vtd[kk][k]=!vtd[kk][k];
	}
	for(ii=0;ii<2;ii++)
	{
		zs=0;
		for(i=1;i<=n;i++)
		{
			if(vtd[ii][i])
			{
				zs++;
				sq[zs]=i;
			}
		}
		printf("%lld",zs);
		for(i=1;i<=zs;i++)
		{
			printf(" %lld",sq[i]);
		}
		printf("\n");
		swap(n,m);
	}
}