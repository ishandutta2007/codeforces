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
string x,y;
LL hasil=0;
LL xl,yl;
int i;
LL banyak[1000005][27];
int main()
{
	scanf("%I64d %I64d",&n,&m);
	x=GetString();
	y=GetString();
	xl=SZ(x);yl=SZ(y);
	LL gcd = __gcd(xl,yl);
	for (i=0;i<yl;++i)
	{
		++banyak[i%gcd][y[i]-'a'];
	}
	LL panjang = n*xl;
	LL lcm = xl/gcd*yl;
	for (i=0;i<xl;++i)
	{
		hasil+=(lcm/xl);
		hasil-=banyak[i%gcd][x[i]-'a'];
	}
	hasil*= (panjang/lcm);
	printf("%I64d\n",hasil);
}