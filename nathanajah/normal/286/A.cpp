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

int n,i;
int arr[100005];
int main()
{
	memset(arr,-1,sizeof(arr));
	scanf("%d",&n);
	if (n%4==2 || n%4==3)
	{
		printf("-1\n");
			return 0;
	}
	if (n%4==1)
	{
		arr[(n+1)/2]=(n+1)/2;
		for (i=1;i<=n;++i)
		{
			if (arr[i]<0)
			{
				arr[i]=i+1;
				arr[i+1]=n-i+1;
				arr[n-i+1]=n-i;
				arr[n-i]=i;
			}
		}
	}
	else
	{
		for (i=1;i<=n;++i)
		{
			if (arr[i]<0)
			{
				arr[i]=i+1;
				arr[i+1]=n-i+1;
				arr[n-i+1]=n-i;
				arr[n-i]=i;
			}
		}
	}
	for (i=1;i<=n;++i)
		printf("%d ",arr[i]);
	printf("\n");
}