#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <deque>
#include <map>
#ifdef DEBUG
	#define debug(...) \
	fprintf(stderr,__VA_ARGS__)
#else
	#define debug(...) 
#endif
using namespace std;

vector <int> primes;
bool notprime[10000005];
int i,j;
int n,m;
int atas[10000005];
int bawah[10000005];
int tmp;
vector <int> hatas,hbaw;
vector <int> awat,abaw;
long long now;
int main()
{
	notprime[1]=true;
	for (i=2;i<=10000;++i)
		if (!notprime[i])
			for (j=i*i;j<=10000000;j+=i)
				notprime[j]=true;
	for (i=1;i<=10000000;++i)
		if (!notprime[i])
			primes.push_back(i);
	debug("%d\n",primes.size());
	scanf("%d %d",&n,&m);
	for (i=0;i<n;++i)
	{
		scanf("%d",&tmp);
		awat.push_back(tmp);
		j=0;
		while (tmp>1)
		{
			if (!notprime[tmp])
			{
				++atas[tmp];
				tmp=1;
			}
			while (tmp%primes[j]==0)
			{
				++atas[primes[j]];
				tmp/=primes[j];
			}
			++j;
		}
	}
	for (i=0;i<m;++i)
	{
		scanf("%d",&tmp);
		abaw.push_back(tmp);
		j=0;
		while (tmp>1)
		{
			if (!notprime[tmp])
			{
				++bawah[tmp];
				tmp=1;
			}
			while (tmp%primes[j]==0)
			{
				++bawah[primes[j]];
				tmp/=primes[j];
			}
			++j;
		}
	}
	for (i=0;i<primes.size();++i)
	{
		int kurang=min(atas[primes[i]],bawah[primes[i]]);
		atas[primes[i]]-=kurang;
		bawah[primes[i]]-=kurang;
	}
	for (i=0;i<n;++i)
		hatas.push_back(1);
	for (i=0;i<m;++i)
		hbaw.push_back(1);
	for (i=0;i<n;++i)
	{
		j=0;
		while (awat[i]>1)
		{
			if (!notprime[awat[i]])
			{
				if (atas[awat[i]]>0)
				{
					hatas[i]*=awat[i];
					--atas[awat[i]];
				}
				awat[i]=1;
			}
			while (awat[i]%primes[j]==0)
			{
				if (atas[primes[j]]>0)
				{
					hatas[i]*=primes[j];
					--atas[primes[j]];
				}
				awat[i]/=primes[j];
			}
			++j;
		}
	}
	for (i=0;i<m;++i)
	{
		j=0;
		while (abaw[i]>1)
		{
			if (!notprime[abaw[i]])
			{
				if (bawah[abaw[i]]>0)
				{
					hbaw[i]*=abaw[i];
					--bawah[abaw[i]];
				}
				abaw[i]=1;
			}
			while (abaw[i]%primes[j]==0)
			{
				if (bawah[primes[j]]>0)
				{
					hbaw[i]*=primes[j];
					--bawah[primes[j]];
				}
				abaw[i]/=primes[j];
			}
			++j;
		}
	}
	printf("%d %d\n",n,m);
	for (i=0;i<hatas.size();++i)
		printf("%d ",hatas[i]);
	printf("\n");
	for (i=0;i<hbaw.size();++i)
		printf("%d ",hbaw[i]);
	printf("\n");
}