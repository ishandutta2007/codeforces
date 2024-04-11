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

struct state
{
	int x,y,dist;
};
int n,i,j;
int arr[105];
int mindist[105][100005];
queue <state> bfs;
state tmp1,tmp2;
int r1,c1,r2,c2;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;++i)
	{
		scanf("%d",&arr[i]);
		for (j=1;j<=arr[i]+1;++j)
			mindist[i][j]=INF;
	}
	scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
	mindist[r1][c1]=0;
	tmp1.x=r1;
	tmp1.y=c1;
	tmp1.dist=0;
	bfs.push(tmp1);
	while (!bfs.empty())
	{
		tmp1=bfs.front();
		bfs.pop();
		//up
		tmp2.x=tmp1.x-1;
		tmp2.y=min(tmp1.y,arr[tmp2.x]+1);
		tmp2.dist=tmp1.dist+1;
		if (tmp2.x>0 && mindist[tmp2.x][tmp2.y]>tmp2.dist)
		{
			mindist[tmp2.x][tmp2.y]=tmp2.dist;
			bfs.push(tmp2);
		}
		//down
		tmp2.x=tmp1.x+1;
		tmp2.y=min(tmp1.y,arr[tmp2.x]+1);
		tmp2.dist=tmp1.dist+1;
		if (tmp2.x>0 && mindist[tmp2.x][tmp2.y]>tmp2.dist)
		{
			mindist[tmp2.x][tmp2.y]=tmp2.dist;
			bfs.push(tmp2);
		}
		//left
		tmp2.x=tmp1.x;
		tmp2.y=tmp1.y-1;
		tmp2.dist=tmp1.dist+1;
		if (tmp2.y>0 && mindist[tmp2.x][tmp2.y]>tmp2.dist)
		{
			mindist[tmp2.x][tmp2.y]=tmp2.dist;
			bfs.push(tmp2);
		}
		//right
		tmp2.x=tmp1.x;
		tmp2.y=tmp1.y+1;
		tmp2.dist=tmp1.dist+1;
		if (tmp2.y<=arr[tmp2.x]+1 && mindist[tmp2.x][tmp2.y]>tmp2.dist)
		{
			mindist[tmp2.x][tmp2.y]=tmp2.dist;
			bfs.push(tmp2);
		}
	}
	printf("%d\n",mindist[r2][c2]);
}