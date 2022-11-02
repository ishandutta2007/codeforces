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

long long t,aaaa;
long long n,m;
long long l,mid,r;

long long hitung(long long req, long long mas)
{
	long long sisa=req*mas;
	long long i=1,j;
	long long comb=1;
	long long res=1;
	long long tambah;
	while (sisa>=i && res<1000000000 &&  i<=req)
	{
		
		long long bil=req-i+1;
		long long ori=i;
		if (i!=0)
		{
			for (j=2;j<=i;++j)
				while (i%j==0)
				{
					i/=j;
					if (comb%j==0)
						comb/=j;
					else
						bil/=j;
				}
			comb=comb*bil;
		}
		if (i==0)
			tambah=1;
		else
			tambah=min(comb,sisa/ori);
		if (tambah==0)
			break;
		res=min(res+tambah,1000000000LL);
		sisa-=tambah*ori;
		i=ori;
		++i;
	}
	return res;
}

int main()
{
	scanf("%I64d",&t);
	for (aaaa=0;aaaa<t;++aaaa)
	{
		scanf("%I64d %I64d",&n,&m);
		l=0;r=1000000000;
		mid=(l+r)/2;
		while (l<r)
		{
			if (hitung(mid,m)>=n)
			{
				r=mid;
				mid=(l+r)/2;
			}
			else
			{
				l=mid+1;
				mid=(l+r+1)/2;
			}
		}
		printf("%I64d\n",mid);
	}
}