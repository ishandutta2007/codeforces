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

int arr[3000005];
int i,j;
int n;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;++i)
		arr[i]=i;
	for (i=2;i<=n;++i)
	{
		int geser=i-2;
		int tmp=0;
		int tmpbaru;
		for (j=geser+1;j<=geser+n;j+=i)
		{
			tmpbaru=arr[j];
			arr[j]=tmp;
			tmp=tmpbaru;
		}
		arr[geser+n+1]=tmp;
	}
	int geser=n+1-2;
	for (i=n;i<n+n;++i)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}