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
int banyak[5];
int res=0;
int total=0;
int main()
{
	scanf("%d",&n);
	int tmp;
	for (i=0;i<n;++i)
	{
		scanf("%d",&tmp);
		++banyak[tmp];
		total+=tmp;
	}
	if (total==1 || total==2 || total==5)
		printf("-1\n");
	else
	{
		//move 1 to 2
		int mini=min(banyak[1],banyak[2]);
		banyak[1]-=mini;
		banyak[2]-=mini;
		banyak[3]+=mini;
		res+=mini;
		if (banyak[1]>0)
		{
			//create group of 3
			int bgroup = banyak[1]/3;
			res+=bgroup*2;
			banyak[1]%=3;
			banyak[3]+=bgroup;
			if (banyak[1]==1 && banyak[3]>0)
				res++;
			else if (banyak[1]>0)
				res+=2;
		}
		else if (banyak[2]>0)
		{
			//create group of 3
			int bgroup = banyak[2]/3;
			res+=bgroup*2;
			banyak[2]%=3;
			banyak[3]+=bgroup*2;
			if (banyak[2]==2)
				res+=2;
			else if (banyak[2]==1)
			{
				if (banyak[4]>0)
					++res;
				else
					res+=2;
			}
		}
		printf("%d\n",res);
	}
}