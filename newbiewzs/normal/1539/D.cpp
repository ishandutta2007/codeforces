#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LI;

const int N=100005;
int n;
LI cnt,cost;
LI a[N],b[N],c[N];
pair<LI,int> d1[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld",a+i,b+i);
	for(int i=1;i<=n;i++)d1[i]=make_pair(b[i],i);
	sort(d1+1,d1+n+1);
	for(int i=n,j=1;i>=1;)
	{
		for(;j<=n&&cnt>=d1[j].first;j++)
		{
			int x=d1[j].second;
			cnt+=a[x]-c[x];cost+=a[x]-c[x];
			c[x]=a[x];
		}
		int y=d1[i].second;
		if(c[y]==a[y]){i--;continue;}
		LI ad=min(a[y]-c[y],d1[j].first-cnt);
		cnt+=ad;cost+=ad*2;
		c[y]+=ad;
	}
	printf("%lld\n",cost);
	return 0;
}