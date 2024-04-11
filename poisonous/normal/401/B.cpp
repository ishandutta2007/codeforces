#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int use[4010];
int main()
{
	memset(use,0,sizeof(use));
	int x,k,k1,t1,t2,t3;
	cin>>x>>k;
	for(k1=1;k1<=k;k1++)
	{
		scanf("%d",&t1);
		if(t1==2)
		{
			scanf("%d",&t2);
			use[t2]=1;
		}
		else
		{
			scanf("%d%d",&t2,&t3);
			use[t3]=use[t2]=1;
		}
	}
	use[x]=1;
	int minn=0,maxn=0;
	for(t1=1;t1<x;t1++)
	{
		if(!use[t1])
		{
			maxn++;
			minn++;
			if(!use[t1+1])
			{
				maxn++;
				use[t1+1]=1;
			}
		}
	}
	cout<<minn<<' '<<maxn;
}