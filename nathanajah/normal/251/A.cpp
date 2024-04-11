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

int n,d;
int x[200000];
int i;
LL res;

int cari(int a)
{
	int l,r,mid;
	l=a;
	r=n-1;
	mid=(l+r)/2;
	while (l<r)
	{
		if (x[mid]-x[a]>d)
		{
			r=mid-1;
			mid=(l+r)/2;
		}
		else
		{
			l=mid;
			mid=(l+r+1)/2;
		}
	}
	return l;
}

int main()
{
	scanf("%d %d",&n,&d);
	for (i=0;i<n;++i)
		scanf("%d",&x[i]);
	for (i=0;i<n;++i)
	{
		LL angka=cari(i);
		//res+=((LL)(n-2-i)*(LL)(n-1-i))/(LL)2;
//		printf("%I64d\n",angka);
//		printf("!%I64d\n",((LL)(n-2-i)*(LL)(n-1-i))/(LL)2);
//		printf("!!%I64d\n",((LL)(angka-1-i)*(LL)(angka-i))/(LL)2);
		res+=((LL)(angka-1-i)*(LL)(angka-i))/(LL)2;
	}
	printf("%I64d\n",res);
}