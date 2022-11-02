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

LL n,i;
LL arr[100005];
LL num=0;
int main()
{
	scanf("%I64d",&n);
	for (i=0;i<n;++i)
		scanf("%I64d",&arr[i]);
	sort(arr,arr+n);
	for (i=0;i<(n-1);++i) {
		LL baru=arr[i+1]-arr[i];
		LL banyak=(i+1)*(n-(i+1));
		num+=banyak*baru*2LL;
	}
	for (i=0;i<n;++i)
		num+=arr[i];
	LL den=n;
	LL gcd=__gcd(den,num);
	num/=gcd;
	den/=gcd;
	printf("%I64d %I64d\n",num,den);
}