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
int n,m,i;
set <int> lol;
int l,r,x;
int conq[300005];
int main()
{
	scanf("%d %d",&n,&m);
	for (i=1;i<=n;++i)
	{
		lol.insert(i);
	}
	for (i=0;i<m;++i)
	{
		scanf("%d %d %d",&l,&r,&x);
		set <int> :: iterator now = lol.lower_bound(l);
		set <int> :: iterator hapus;
		while (now!=lol.end() && *now <=r)
		{
			hapus = now;
			int bilangan = *now;
			now++;
			if (bilangan!=x)
			{
				conq[bilangan]=x;
				lol.erase(hapus);
			}
		}
	}
	for (i=1;i<=n;++i)
	{
		printf("%d ",conq[i]);
	}
	printf("\n");
}