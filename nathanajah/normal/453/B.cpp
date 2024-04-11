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

int n,i,j;
int arr[105];
int dp[105][132000];
int fact[105];
int primes[17] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};

int hitung(int x, int mask) {
	if (x == -1)
		return 0;
	int i;
	int &ret = dp[x][mask];
	if (ret >= 0)
		return ret;
	ret = 1000000000;
	for (i = 0; i < 60; i++) {
		if ((mask & fact[i]) == fact[i]) {
			ret = min(ret, hitung(x-1, mask & (~fact[i])) + abs(arr[x] - i));
		}
	}
	return ret;
}

void btrack(int x, int mask) {
	if (x == -1)
		return;
	int i;
	int ret = hitung(x, mask);
	for (i = 0; i < 60; i++) {
		if ((mask & fact[i]) == fact[i]) {
			if (hitung(x-1, mask & (~fact[i])) + abs(arr[x] - i) == ret) {
				btrack(x-1, mask & (~fact[i]));
				if (x > 0)
					printf(" ");
				printf("%d",i);
				return;
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	for (i=0;i<n;++i)
		scanf("%d",&arr[i]);
	for (i=1;i<=60;++i) {
		for (j=0;j<17;++j)
			if (i % primes[j] == 0)
				fact[i] |= (1 << j);
	}
	memset(dp, -1, sizeof(dp));
	btrack(n-1, (1<<17)-1);
	printf("\n");
	
}