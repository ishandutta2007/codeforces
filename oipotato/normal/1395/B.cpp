#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
int main()
{
	int n,m,x,y,la;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	printf("%d %d\n",x,y);
	rep(i,m)if(i!=y)printf("%d %d\n",x,la=i);
	rep(i,n)
	{
		if(i==x)continue;
		printf("%d %d\n",i,la);
		int laa;
		rep(j,m)if(j!=la)printf("%d %d\n",i,laa=j);
		la=laa;
	}
	return 0;
}