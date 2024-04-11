#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long z=0,n,d,prk[169],pst[169],a[169],rm;
vector<pair<long long,pair<long long,long long>>> sq;
multiset<pair<long long,long long>> ms;
multiset<pair<long long,long long>>::iterator it;

int main()
{
	long long i,itt,k,p,y,x,c=0,fr;
	bool bad=1;
	
	scanf("%lld%lld",&n,&d);
	for(itt=0;itt<4;itt++)
	{
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			if(itt<=1)
			{
				p=i;
			}
			else
			{
				p=n+n-i-1;
			}
			if(itt==0||itt==3)
			{
				if(k)
				{
					prk[k]=p;
				}
			}
			else
			{
				a[p]=k;
				if(k)
				{
					pst[k]=p;
				}
			}
		}
	}
	rm=d;
	for(i=1;i<=d;i++)
	{
		if(pst[i]==prk[i])
		{
			if(pst[i]<n)
			{
				y=1;
				x=pst[i]+1;
			}
			else
			{
				y=4;
				x=n+n-pst[i];
			}
			a[pst[i]]=0;
			sq.push_back(mp(i,mp(y,x)));
			z++;
			rm--;
		}
	}
	if(rm>0)
	{
		for(i=0;i<n+n;i++)
		{
			if(bad&&a[i]&&!a[(i+n+n-1)%(n+n)])
			{
				bad=0;
				fr=a[i];
			}
			if(a[i]&&!bad)
			{
				c++;
				ms.insert(mp(c,a[i]));
			}
		}
		if(bad)
		{
			printf("-1\n");
			return 0;
		}
		for(i=0;a[i]!=fr;i++)
		{
			if(a[i])
			{
				c++;
				ms.insert(mp(c,a[i]));
			}
		}
		for(it=ms.begin();rm>0;it++)
		{
			if(it==ms.end())
			{
				it=ms.begin();
			}
			k=(*it).fr;
			p=(*it).sc;
			pst[p]=(pst[p]+n+n-1)%(n+n);
			if(pst[p]<n)
			{
				y=2;
				x=pst[p]+1;
			}
			else
			{
				y=3;
				x=n+n-pst[p];
			}
			sq.push_back(mp(p,mp(y,x)));
			z++;
			if(pst[p]==prk[p])
			{
				if(pst[p]<n)
				{
					y=1;
					x=pst[p]+1;
				}
				else
				{
					y=4;
					x=n+n-pst[p];
				}
				if(it==ms.begin())
				{
					it=ms.end();
				}
				it--;
				ms.erase(ms.find(mp(k,p)));
				sq.push_back(mp(p,mp(y,x)));
				z++;
				rm--;
			}
		}
	}
	printf("%lld\n",z);
	for(i=0;i<z;i++)
	{
		printf("%lld %lld %lld\n",sq[i].fr,sq[i].sc.fr,sq[i].sc.sc);
	}
}