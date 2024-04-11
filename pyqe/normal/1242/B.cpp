#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,pr[100069],cd[100069],ls[100069],fq[100069],lss[100069];
vector<long long> al[100069];
multiset<long long> ms;
multiset<long long>::iterator it,itt;
bitset<100069> vtd;

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
	long long i,j,k,l,sz,c=-1;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		pr[i]=i;
		cd[i]=1;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		if(k>l)
		{
			swap(k,l);
		}
		al[l].push_back(k);
	}
	for(i=1;i<=n;i++)
	{
		sz=al[i].size();
		for(j=0;j<sz;j++)
		{
			l=al[i][j];
			if(ls[fd(l)]<i)
			{
				fq[fd(l)]=0;
				ls[fd(l)]=i;
			}
			fq[fd(l)]++;
			if(fq[fd(l)]==cd[fd(l)])
			{
				lss[fd(l)]=i;
			}
		}
		for(it=ms.begin();it!=ms.end();)
		{
			k=*it;
			if(lss[k]<i)
			{
				cd[i]+=cd[k];
				pr[k]=i;
				itt=it;
				it++;
				ms.erase(itt);
			}
			else
			{
				it++;
			}
		}
		ms.insert(i);
	}
	for(i=1;i<=n;i++)
	{
		if(!vtd[fd(i)])
		{
			c++;
			vtd[fd(i)]=1;
		}
	}
	printf("%lld\n",c);
}