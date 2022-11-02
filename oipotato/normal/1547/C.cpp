#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int a[110],b[110],ans[210];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int k,n,m;scanf("%d%d%d",&k,&n,&m);
		rep(i,n)scanf("%d",&a[i]);
		rep(i,m)scanf("%d",&b[i]);
		int x=1,y=1,cnt=1;
		bool flag=1;
		for(;flag&&x<=n&&y<=m;)
		{
			if(!a[x])k++,ans[cnt++]=a[x++];
			else if(!b[y])k++,ans[cnt++]=b[y++];
			else
			{
				if(min(a[x],b[y])>k)flag=0;
				if(a[x]<b[y])ans[cnt++]=a[x++];else ans[cnt++]=b[y++];
			}
		}
		for(;flag&&x<=n;ans[cnt++]=a[x++])if(!a[x])k++;else flag&=a[x]<=k;
		for(;flag&&y<=m;ans[cnt++]=b[y++])if(!b[y])k++;else flag&=b[y]<=k;
		if(!flag)puts("-1");else rep(i,n+m)printf("%d%c",ans[i]," \n"[i==n+m]);
	}
    return 0;
}