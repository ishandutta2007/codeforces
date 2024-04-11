#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<ctime>
using namespace std;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=1;i<=n;i++)
#define x1 fuckcjb
#define y1 fucksub
#define x2 fuckjtjl
#define y2 fucksf
map<int,int>cnt;
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k+1;i++)
	{
		printf("?");
		for(int j=1;j<=k+1;j++)if(j!=i)printf(" %d",j);printf("\n");
		fflush(stdout);
		int x,y;scanf("%d%d",&x,&y);cnt[y]++;
	}
	printf("! %d\n",cnt.rbegin()->second);fflush(stdout);
	return 0;
}