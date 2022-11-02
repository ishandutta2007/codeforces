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
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int c[110],ans[110],n,a,b;
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%d%d",&n,&a,&b);
		rep(i,n)c[i]=1;c[a]=c[b]=0;
		int c1=0,c2=0;
		rep(i,a)c1+=c[i];
		for(int i=n;i>b;i--)c2+=c[i];
		if(c1>n/2-1||c2>n/2-1){puts("-1");continue;}
		ans[1]=a;ans[n]=b;
		int l=2,r=n-1;
		rep(i,a)if(c[i])ans[r--]=i,c[i]=0;
		for(int i=n;i>b;i--)if(c[i])ans[l++]=i,c[i]=0;
		rep(i,n)if(c[i])ans[l++]=i;
		rep(i,n)printf("%d%c",ans[i]," \n"[i==n]);
	}
    return 0;
}