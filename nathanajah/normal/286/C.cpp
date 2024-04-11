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

int n,arr[1000005];
int i;
map <int,int> balik;
vector <int> daftar;
int banyak[1000005];
int sum;
vector <pair <int,int> > lol[1000005];

int main()
{
	scanf("%d",&n);
	daftar.push_back(0);
	for (i=0;i<n;++i)
	{
		scanf("%d",&arr[i]);
		bool negatif=false;
		if (arr[i]<0)
		{
			arr[i]=-arr[i];
			negatif=true;
		}
		if (balik.count(arr[i])==0)
		{
			balik[arr[i]]=SZ(daftar);
			daftar.push_back(arr[i]);
		}
		arr[i]=balik[arr[i]];
		if (negatif)
			arr[i]=-arr[i];
	}
	int tnum,tmp;
	scanf("%d",&tnum);
	for (i=0;i<tnum;++i)
	{
		scanf("%d",&tmp);
		arr[tmp-1]=-arr[tmp-1];
	}
	sum=0;
	for (i=n-1;i>=0;--i)
	{
		if (arr[i]<0)
		{
			lol[-arr[i]].pb(mp(sum,banyak[-arr[i]]));
			banyak[-arr[i]]--;
			--sum;
		}
		else
		{
			if (SZ(lol[arr[i]])==0)
			{
				lol[arr[i]].pb(mp(sum,banyak[arr[i]]));
				--banyak[arr[i]];
				--sum;
				arr[i]=-arr[i];
			}
			else
			{
				ii atas=lol[arr[i]][SZ(lol[arr[i]])-1];
				if (banyak[arr[i]]-atas.second==-1 && sum-atas.first==-1)
				{
					lol[arr[i]].pop_back();
					++sum;
					++banyak[arr[i]];
				}
				else
				{
					lol[arr[i]].pb(mp(sum,banyak[arr[i]]));
					--banyak[arr[i]];
					--sum;
					arr[i]=-arr[i];
				}
			}
		}
	}
	if (sum!=0)
		printf("NO\n");
	else
	{
		printf("YES\n");
		for (i=0;i<n;++i)
		{
			bool negatif=false;
			if (arr[i]<0)
			{
				negatif=true;
				arr[i]=-arr[i];
			}
			int baru=daftar[arr[i]];
			if (negatif)
				baru=-baru;
			printf("%d ",baru);
		}
	}
	printf("\n");
}