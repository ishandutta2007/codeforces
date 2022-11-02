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
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int ans=0;
		rep(i,n)
		{
			char s[110];
			scanf("%s",s+1);
			if(i<n&&s[m]!='D')ans++;
			if(i==n)for(int j=1;j<m;j++)if(s[j]!='R')ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}