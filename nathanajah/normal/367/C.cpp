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
#define mp make_pair
#define LL long long
#define ULL unsigned LL
#define INF 0x3FFFFFFF
#define INFLL 0x3FFFFFFFFFFFFFFF
#define SZ(a) (int)(a).size()
#define ALL(a) (a).begin(),(a).end()
#ifdef DEBUG
	#define debug(...) \
	fprintf(stderr,__VA_ARGS__)
#else
	#define debug(...) 
#endif
using namespace std;

inline string GetString()
{
	char GS[1000005];
	scanf("%s",GS);string ret=GS;
	return ret;
}

inline char getc()
{
	char c=' ';
	while (c==' ' || c=='\t' || c=='\r' || c=='\n')
		c=getchar();
	return c;
}
//ENDOFTEMPLATE

LL n,m;
LL i;
pair <LL,LL> arr[100005];

LL hitung(LL x)
{
	if (x==1)
		return 1;
	if (x%2==1)
	{
		return (x*(x-1)/2)+1;
	}
	else
	{
		LL banyakganjil = x;
		LL tambah = (x-2)/2;
		return (x*(x-1)/2)+1+tambah;
	}
}

LL hasil;

int main()
{
	scanf("%I64d %I64d",&n,&m);
	LL cari=1;
	while (hitung(cari+1)<=n)
		++cari;
	for (i=0;i<m;++i)
	{
		scanf("%I64d %I64d",&arr[i].se,&arr[i].fi);
		arr[i].fi=-arr[i].fi;
	}
	sort(arr,arr+m);
	for (i=0;i<min(m,cari);++i)
		hasil-=arr[i].fi;
	printf("%I64d\n",hasil);
}