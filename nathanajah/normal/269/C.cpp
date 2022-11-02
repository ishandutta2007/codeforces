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
#define INF 0x3FFFFFFF
#define INFLL 0x3FFFFFFFFFFFFFFF
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
//ENDOFTEMPLATE

int n,m;
int e[200005];
vii adj[200005];
int now[200005];
int arahe[200005];
int total[200005];
int harus[200005];
int sudah[200005];
queue <int> lol;
int i,j;
int v1[200005],v2[200005];

int main()
{
	memset(arahe,-1,sizeof(arahe));
	scanf("%d %d",&n,&m);
	for (i=0;i<m;++i)
	{
		scanf("%d %d %d",&v1[i],&v2[i],&e[i]);
		--v1[i];--v2[i];
		adj[v1[i]].push_back(mp(v2[i],i));
		adj[v2[i]].push_back(mp(v1[i],i));
		total[v1[i]]+=e[i];
		total[v2[i]]+=e[i];
	}
	for (i=0;i<n;++i)
		harus[i]=total[i]/2;
	for (i=0;i<adj[0].size();++i)
	{
		int nume=adj[0][i].se;
		if (arahe[nume]==-1)
		{
			if (v1[nume]==0)
				arahe[nume]=0;
			else
				arahe[nume]=1;
			sudah[adj[0][i].fi]+=e[nume];
		}
	}
	for (i=0;i<n;++i)
		if (sudah[i]==harus[i])
			lol.push(i);
	while (!lol.empty())
	{
		int atas=lol.front();
		lol.pop();
		if (atas!=n-1 && atas!=0)
		{
			for (i=0;i<adj[atas].size();++i)
			{
				int nume=adj[atas][i].se;
				if (arahe[nume]==-1)
				{
					if (v1[nume]==atas)
						arahe[nume]=0;
					else
						arahe[nume]=1;
					sudah[adj[atas][i].fi]+=e[nume];
					if (sudah[adj[atas][i].fi]==harus[adj[atas][i].fi])
						lol.push(adj[atas][i].fi);
				}
			}
		}
	}
	for (i=0;i<m;++i)
		printf("%d\n",arahe[i]);
}