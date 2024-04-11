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
int main()
{
	int x,y;
	scanf("%d %d",&x, &y);
	int a,b;
	for (a = 1; a <= 1000; a++)
		for (b = 1; b <= 1000; b++) {
			if (a*a + b*b == x*x) {
				if ((a*y)%x == 0 && (b*y)%x == 0 && (a + (b*y)/x) != 0 && (b - (a*y)/x) != 0) {
					printf("YES\n");
					printf("%d %d\n",0, 0);
					printf("%d %d\n", a, b);
					printf("%d %d\n", a + (b*y)/x, b - (a*y)/x);
					return 0;
				}
			}
		}
	printf("NO\n");
}