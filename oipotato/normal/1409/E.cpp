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
int x[200010],s[200010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		rep(i,n)scanf("%d",&x[i]);
		sort(x+1,x+n+1);
		rep(i,n){int y;scanf("%d",&y);}
		int now=1;
		rep(i,n)
		{
			for(;x[i]-x[now]>k;now++);
			s[i]=max(s[i-1],i-now+1);
		}
		now=n;
		int ans=s[n];
		for(int i=n;i;i--)
		{
			for(;x[now]-x[i]>k;now--);
			ans=max(ans,s[i-1]+now-i+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}