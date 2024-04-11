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
#define INF 0x3FFFFFFF
#define INFLL 0x3FFFFFFFFFFFFFFF
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
//ENDOFTEMPLATE

int n,k;
int i;
int x1,x2;
int last, lastsize;
vii lol;
int maxi;

int main()
{
	scanf("%d",&n);
	last=0;
	lastsize=0;
	maxi=-1;
	for (i=0;i<n;++i)
	{
		scanf("%d %d",&x1,&x2);
		lol.pb(mp(x1,x2));
		maxi=max(maxi,x1);
	}
	sort(lol.begin(),lol.end());
	for (i=0;i<n;++i)
	{
		int selisih=lol[i].fi-lastsize;
		int bisa;
		if (selisih>15)
			bisa=2000000000;
		else
			bisa=(1<<2*selisih);
		int masuk;
		if (last%bisa==0)
			masuk=last/bisa;
		else
			masuk=(last/bisa)+1;
		lastsize=lol[i].fi;
		last=max(lol[i].se,masuk);
	}
	while (last>1)
	{
		if (last%4==0)
			last=last/4;
		else
			last=(last/4)+1;
		++lastsize;
	}
	if (lastsize==maxi)
		++lastsize;
	printf("%d\n",lastsize);
}