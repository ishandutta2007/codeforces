#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int x[4],y[4];
		rep(i,3)scanf("%d%d",&x[i],&y[i]);
		if(x[1]==x[2])
		{
			if(y[1]>y[2])swap(y[1],y[2]);
			if(x[1]==x[3]&&y[1]<y[3]&&y[3]<y[2])printf("%d\n",y[2]-y[1]+2);else printf("%d\n",y[2]-y[1]);
		}
		else if(y[1]==y[2])
		{
			rep(i,3)swap(x[i],y[i]);
			if(y[1]>y[2])swap(y[1],y[2]);
			if(x[1]==x[3]&&y[1]<y[3]&&y[3]<y[2])printf("%d\n",y[2]-y[1]+2);else printf("%d\n",y[2]-y[1]);
		}
		else printf("%d\n",abs(x[1]-x[2])+abs(y[1]-y[2]));
	}
    return 0;
}