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
int arr[500005];
int main()
{
	scanf("%d",&n);
	for (i=0;i<n;++i)
		scanf("%d",&arr[i]);
	sort(arr,arr+n);
	int l,mid,r;
	l = 0;
	r = (n/2);
	while (l < r) {
		int m = (l+r+1)/2;
		//check m
		bool can = true;
		for (i=0;i<m;++i) {
			if (2*arr[i] > arr[n-m+i])
				can = false;
		}
		if (can) {
			l = m;
		}
		else
			r = m-1;
	}
	printf("%d\n",(n) - l);
}