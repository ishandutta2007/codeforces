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

int n,m;
int i;
int now;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d %d",&n,&m);
	if (n>m)
		now=0;
	else
		now=1;
	while (n>0 || m>0)
	{
		if (now==0)
		{
			if (n>0)
			{
				printf("B");
				--n;
			}
			else
			{
				printf("G");
				--m;
			}
			now=1;
		}
		else
		{
			if (m>0)
			{
				printf("G");
				--m;
			}
			else
			{
				printf("B");
				--n;
			}
			now=0;
		}
	}
	printf("\n");
}