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

bool cekduapangkat(LL n)
{
	while (n>1)
	{
		if (n%2LL==1LL)
			return false;
		n/=2;
	}
	return true;
}
LL n,t;
map <pair<pair<LL,LL>,LL >,LL > x;

LL f(LL lev, LL baris, LL banyak)
{
	if (x.count(make_pair(make_pair(lev,baris),banyak))>0)
		return x[make_pair(make_pair(lev,baris),banyak)];
	if (lev==1 && baris==1)
	{
		if (banyak==1)
			return 1;
		return 0;
	}
	if (baris<=lev/2)
		x[make_pair(make_pair(lev,baris),banyak)]= f(lev/2,baris,banyak);
	else
		x[make_pair(make_pair(lev,baris),banyak)]= f(lev/2,lev/2,banyak)+f(lev/2,baris-(lev/2),banyak/2);
	return x[make_pair(make_pair(lev,baris),banyak)];
		
}
int main()
{
	scanf("%I64d %I64d",&n,&t);
	if (!cekduapangkat(t))
	{
		printf("0\n");
		return 0;
	}
	LL res=0;
	LL i=1;
	while (true)
	{
		LL bawah=(1LL<<i);
		if (bawah>n+1)
			break;
		LL atas=min(n+1,(1LL<<(i+1))-1);
		res+=f(1LL<<i,atas-bawah+1,t);
		++i;
	}
	printf("%I64d\n",res);
}