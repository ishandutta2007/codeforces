//nathanajah's template
//25-10-2012
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
#define LL long long
#define INF 0x7FFFFFFF
#define INFLL 0x7FFFFFFFFFFFFFFF
#ifdef DEBUG
	#define debug(...) \
	fprintf(stderr,__VA_ARGS__)
#else
	#define debug(...) 
#endif
using namespace std;

int n,m,i,j;
char c[200][20000];
int row;
int rnow,lnow;
bool katok,kitok;
int dirnow;
LL res;
char getc()
{
	char c=' ';
	while (c==' ' || c=='\t' || c=='\r' || c=='\n')
		c=getchar();
	return c;
}
int main()
{
	scanf("%d %d",&n,&m);
	for (i=0;i<=n+1;++i)
		for (j=0;j<=m+1;++j)
			c[i][j]='#';
	for (i=1;i<=n;++i)
	{
		for (j=1;j<=m;++j)
			c[i][j]=getc();
	}
	row=1;
	rnow=1;
	lnow=1;
	katok=0;kitok=0;
	dirnow=1;
	while (row!=n)
	{
//		printf("!%d|%d %d| %d %d %d|%I64d\n",row,lnow,rnow,kitok,katok,dirnow,res);
		if (dirnow==1 && c[row+1][rnow]=='.')
		{
//			printf("TURUN DI %d\n",rnow);
			++row;
			lnow=rnow;
			++res;
			katok=false;
			kitok=false;
		}
		else if(dirnow==-1 && c[row+1][lnow]=='.')
		{
//			printf("TURUN DI %d\n",lnow);
			++row;
			rnow=lnow;
			++res;
			katok=false;
			kitok=false;
		}
		else
		{
			if (katok && kitok)
			{
				printf("Never\n");
				return 0;
			}
			else if (dirnow==1 && c[row][rnow+1]=='.')
			{
//				printf("TEST6\n");
				++rnow;
				++res;
			}
			else if (dirnow==-1 && c[row][lnow-1]=='.')
			{
//				printf("TEST5\n");
				--lnow;
				++res;
			}
			else if (dirnow==1 && c[row][rnow+1]=='+')
			{
//				printf("TEST4\n");
				++rnow;
				res+=(LL)(rnow-lnow);
				dirnow=-1;
			}
			else if (dirnow==-1 && c[row][lnow-1]=='+')
			{
//				printf("TEST3\n");
				--lnow;
				res+=(LL)(rnow-lnow);
				dirnow=1;
			}
			else if (dirnow==1 && c[row][rnow+1]=='#')
			{
//				printf("TEST2\n");
				katok=true;
				res+=(LL)(rnow-lnow+1);
				dirnow=-1;
			}
			else if (dirnow==-1 && c[row][lnow-1]=='#')
			{
//				printf("TEST\n");
				kitok=true;
				res+=(LL)(rnow-lnow+1);
				dirnow=1;
			}
		}
	}
	cout << res << "\n";
}