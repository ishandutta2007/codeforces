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

int a[200005];
vector <ii> daftar;
int banyak[200005];
int b[200005];
map <int,int> balik;
int n,m,p;
vector <int> ans;
int i,j;
int full=0;
int main()
{
	scanf("%d %d %d",&n,&m,&p);
	for (i=0;i<n;++i)
		scanf("%d",&a[i]);
	for (i=0;i<m;++i)
	{
		scanf("%d",&b[i]);
		if (balik.count(b[i])==0)
		{
			balik[b[i]]=SZ(daftar);
			daftar.pb(mp(b[i],1));
		}
		else
		{
			daftar[balik[b[i]]].se++;
		}
	}
	for (i=0;i<n;++i)
	{
		if (balik.count(a[i])==0)
			a[i]=-1;
		else
			a[i]=balik[a[i]];
	}
	int awal;
	for (awal=0;awal<p;++awal)
	{
		if ((LL)awal+(LL)(m-1)*(LL)p<(LL)n)
		{
			for (j=0;j<m;++j)
				if (a[awal+j*p]!=-1)
				{
					if (banyak[a[awal+j*p]]==daftar[a[awal+j*p]].se)
						--full;
					banyak[a[awal+j*p]]++;
					if (banyak[a[awal+j*p]]==daftar[a[awal+j*p]].se)
						++full;
				}
			if (full==SZ(daftar))
				ans.pb(awal);
			int lastj=awal+m*p-p;
			for (j=awal+m*p;j<n;j+=p)
			{
				lastj=j;
				if (a[j-m*p]!=-1)
				{
					if (banyak[a[j-m*p]]==daftar[a[j-m*p]].se)
						--full;
					--banyak[a[j-m*p]];
					if (banyak[a[j-m*p]]==daftar[a[j-m*p]].se)
						++full;
				}
				if (a[j]!=-1)
				{
					if (banyak[a[j]]==daftar[a[j]].se)
						--full;
					++banyak[a[j]];
					if (banyak[a[j]]==daftar[a[j]].se)
						++full;
				}
				if (full==SZ(daftar))
					ans.pb(j-m*p+p);
			}
			for (j=lastj;j>lastj-m*p;j-=p)
			{
				if (a[j]!=-1)
					--banyak[a[j]];
			}
			full=0;
		}
		
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",SZ(ans));
	for (i=0;i<SZ(ans);++i)
	{
		if (i>0)
			printf(" ");
		printf("%d",ans[i]+1);
	}
	printf("\n");
}