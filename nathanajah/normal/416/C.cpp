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

int n,m,c[1005],p[1005];
int k;
pair<int,int> arr[1005];
int i,j;
vector <pair<int,int> > ret;

int main()
{
	scanf("%d",&n);
	for (i=0;i<n;++i) {
		scanf("%d %d",&p[i],&c[i]);
	}
	scanf("%d",&m);
	for (i=0;i<m;++i) {
		scanf("%d",&arr[i].fi);
		arr[i].se = i;
	}
	sort(arr,arr+m);
	int res = 0;
	for (i=0;i<m;++i) {
		int nummax = 0;
		for (j=0;j<n;++j) {
			if (p[j] <= arr[i].fi && (p[nummax] > arr[i].fi || c[j] > c[nummax])) {
				nummax = j;
			}
		}
		if (c[nummax]>=0 && p[nummax] <= arr[i].fi)
		{
			res += c[nummax];
			c[nummax] = -100;
			ret.pb(mp(nummax+1,arr[i].se+1));
		}
	}
	printf("%d %d\n",SZ(ret),res);
	for (i=0;i<SZ(ret);++i)
		printf("%d %d\n",ret[i].fi,ret[i].se);
}