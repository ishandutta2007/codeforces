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

string s;
int cnt0[100005],cnt1[100005],cnt2[100005];
int i;

int hitung0(int l, int r)
{
	return cnt0[r]-cnt0[l-1];
}
int hitung1(int l, int r)
{
	return cnt1[r]-cnt1[l-1];
}
int hitung2(int l, int r)
{
	return cnt2[r]-cnt2[l-1];
}

int l,r;
int main()
{
	s=GetString();
	for (i=1;i<=SZ(s);++i)
	{
		cnt0[i]=cnt0[i-1];
		cnt1[i]=cnt1[i-1];
		cnt2[i]=cnt2[i-1];
		if (s[i-1]=='x')
			cnt0[i]++;
		else if(s[i-1]=='y')
			cnt1[i]++;
		else
			cnt2[i]++;
	}
	int m;
	scanf("%d",&m);
	for (i=0;i<m;++i)
	{
		scanf("%d %d",&l,&r);
		int x = hitung0(l,r);
		int y= hitung1(l,r);
		int z = hitung2(l,r);
		int maxi = max(z,max(x,y));
		if (((maxi-x<=1) && maxi-y<=1 && maxi-z<=1) || (r-l<=1))
			printf("YES\n");
		else
			printf("NO\n");
	}
}