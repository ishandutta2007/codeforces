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

long long l,r;
long long ll,rr;
long long i,j;
long long ba,at;
vector <long long> prd;
vector <long long> divi;
long long tmp;
long long hasil;
long long hitungp(long long x)
{
	long long ret=0;
	while (x>0)
	{
		x>>=1;
		++ret;
	}
	return ret;
}
bool cekpr(long long x)
{
	if (x==1)
		return false;
	long long i;
	for (i=2;i<x;++i)
		if (x%i==0)
			return false;
	return true;
}
long long constr(long long ul, long long paj)
{
	long long tmp=paj/ul;
	long long i;
	long long ret=1;
	for (i=1;i<ul;++i)
	{
		ret=ret<<tmp;
		++ret;
	}
	return ret;
}
long long lcm(long long a, long long b)
{
	return (a/__gcd(a,b))*b;
}
long long hitung(long long x)
{
	int i,j;
	long long ret=0;
	long long banyak;
	long long angka;
	for (i=1;i<(1<<divi.size());++i)
	{
		angka=1;
		for (j=0;j<divi.size();++j)
		{
			if ((i & (1<<j))!=0)
				angka=lcm(angka,divi[j]);
		}
		banyak=x/angka;
		if (__builtin_popcount(i)%2==0)
			ret-=banyak;
		else
			ret+=banyak;
	}
	return ret;
}
int main()
{
	scanf("%I64d %I64d",&l,&r);
	ll=hitungp(l);
	rr=hitungp(r);
	debug("%I64d %I64d\n",ll,rr);
	for (i=ll;i<=rr;++i)
	{
		prd.clear();
		divi.clear();
		ba=max(l,1LL<<(i-1));
		at=min(r,(1LL<<i)-1);
		debug("%I64d %I64d\n",ba,at);
		for (j=1;j<=i;++j)
			if (i%j==0 && cekpr(j))
				prd.push_back(j);
		for (j=0;j<prd.size();++j)
		{
			divi.push_back(constr(prd[j],i));
			debug("%I64d ",divi[divi.size()-1]);
		}
		debug("\n");
		hasil=hasil+hitung(at)-hitung(ba-1);
	}
	printf("%I64d\n",hasil);
}