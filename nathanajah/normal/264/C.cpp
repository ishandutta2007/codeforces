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

int n,q,i,j;
LL v[100005];
int c[100005];
LL a,b;

LL maxakhir[100005];
LL nummax1,nummax2;
LL maxbaru;
LL maxi;
int main()
{
	scanf("%d %d",&n,&q);
	for (i=0;i<n;++i)
		scanf("%I64d",&v[i]);
	for (i=0;i<n;++i)
	{
		scanf("%d",&c[i]);
		--c[i];
	}
	for (i=0;i<q;++i)
	{
		scanf("%I64d %I64d",&a,&b);
		for (j=0;j<=n+1;++j)
			maxakhir[j]=-INFLL;
		nummax1=n;nummax2=n+1;
		for (j=0;j<n;++j)
		{
			//awal
			maxbaru=b*v[j];
			//sama
			maxbaru=max(maxbaru,maxakhir[c[j]]+(a*v[j]));
			//beda
			if (nummax1==c[j])
				maxbaru=max(maxbaru,maxakhir[nummax2]+(b*v[j]));
			else
				maxbaru=max(maxbaru,maxakhir[nummax1]+(b*v[j]));
			maxakhir[c[j]]=max(maxakhir[c[j]],maxbaru);
			if (c[j]==nummax1)
			{
			}
			else if (c[j]==nummax2)
			{
				if (maxakhir[c[j]]>maxakhir[nummax1])
				{
					nummax2=nummax1;
					nummax1=c[j];
				}
			}
			else
			{
				if (maxakhir[c[j]]>maxakhir[nummax1])
				{
					nummax2=nummax1;
					nummax1=c[j];
				}
				else if (maxakhir[c[j]]>maxakhir[nummax2])
					nummax2=c[j];
			}
		}
		maxi=0;
		for (j=0;j<n;++j)
			maxi=max(maxi,maxakhir[j]);
		printf("%I64d\n",maxi);
	}
	
}