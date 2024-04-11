//nathanajah's template
//28-11-2012
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
#include <ctime>
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define fi first
#define se second
#define pb push_back
#define LL long long
#define INF 0x3FFFFFFF
#define INFLL 0x3FFFFFFFFFFFFFFF
#ifdef DEBUG
	#define debug(...) \
	fprintf(stderr,__VA_ARGS__)
#else
	#define debug(...) 
#endif
using namespace std;

int n,i,j;
int arr[100005];
vector <int> primes;
int palingbesar[100005];
bool notprime[100005];
int balik[100005];
vector <int> hafac;
int maxi;

void factorize(int x)
{
	hafac.clear();
	int i;
	for (i=0;primes[i]*primes[i]<=x;++i)
	{
		if (x%primes[i]==0)
		{
			hafac.push_back(i);
			while (x%primes[i]==0)
				x/=primes[i];
		}
	}
	if (x!=1)
		hafac.push_back(balik[x]);
}
int main()
{
	notprime[0]=true;
	notprime[1]=true;
	for (i=2;i<=1000;++i)
	{
		for (j=i*i;j<=100000;j+=i)
			notprime[j]=true;
	}
	for (i=1;i<=100000;++i)
		if (!notprime[i])
		{
			balik[i]=primes.size();
			primes.push_back(i);
		}
	scanf("%d",&n);
	for (i=0;i<n;++i)
		scanf("%d",&arr[i]);
	for (i=0;i<n;++i)
	{
		factorize(arr[i]);
		maxi=0;
		for (j=0;j<hafac.size();++j)
		{
			maxi=max(maxi,palingbesar[hafac[j]]);
		}
		for (j=0;j<hafac.size();++j)
		{
			palingbesar[hafac[j]]=maxi+1;
		}
	}
	maxi=1;
	for (i=0;i<=100000;++i)
		maxi=max(maxi,palingbesar[i]);
	printf("%d\n",maxi);
}