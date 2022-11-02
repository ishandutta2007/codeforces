#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cassert>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[110],b[110],n;
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);
		int sum=0;
		rep(i,n)scanf("%d",&a[i]),sum+=a[i];
		rep(i,n)scanf("%d",&b[i]),sum-=b[i];
		if(sum!=0)puts("-1");
		else
		{
			int m=0;
			rep(i,n)if(a[i]>b[i])m+=a[i]-b[i];
			printf("%d\n",m);
			int now=1;
			rep(i,n)
			for(;a[i]>b[i];)
			{
				for(;a[now]>=b[now];now++);
				a[now]++;a[i]--;
				printf("%d %d\n",i,now);
			}
		}
	}
    return 0;
}