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

LL n, k;
int main()
{
	scanf("%I64d %I64d",&n, &k);
	if ((k * (k-1)/2) + 1 < n)
		printf("-1\n");
	else if (n == 1)
		printf("0\n"); //ga perlu bikin pipa
	else{
		LL lo = 1;
		LL hi = k;
		while (lo < hi) {
			LL mid = (lo + hi + 1)/2;
			//coba ambil dari mid sampai k, yang berarti
			//banyak total penambahan = mid-1 + mid + mid+1  + .. + k-1
			// = (0 + ... + k-1) - (0 + ... + mid-2)
			// = k*(k-1)/2 - (mid - 1) * (mid - 2) / 2
			if ((k* (k-1)/2) - ((mid-1) * (mid-2)/2) + 1 < n) {
				hi = mid - 1;
			}			
			else
				lo = mid;
		}
		printf("%I64d\n", k - lo + 1);
	}
}