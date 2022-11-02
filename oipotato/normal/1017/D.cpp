#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<bitset>
#include<cmath>
using namespace std;
int n,m,q,ans[1<<12][110],num[1<<12],w[20];
char s[20];
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<n;i++)scanf("%d",&w[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%s",s);
		reverse(s,s+n);
		int x=0;
		for(int j=0;j<n;j++)x=(x<<1)+(s[j]-'0');
		num[x]++;
	}
	for(int i=0;i<(1<<n);i++)
	for(int j=0;j<(1<<n);j++)
	{
		int x=~(i^j),y=0;
		for(int k=0;k<n;k++)if(x&(1<<k))y+=w[k];
		if(y<=100)ans[j][y]+=num[i];
	}
	for(int i=0;i<(1<<n);i++)for(int j=1;j<=100;j++)ans[i][j]+=ans[i][j-1];
	for(int i=1;i<=q;i++)
	{
		int k;
		scanf("%s%d",s,&k);
		reverse(s,s+n);
		int x=0;
		for(int j=0;j<n;j++)x=(x<<1)+(s[j]-'0');
		printf("%d\n",ans[x][k]);
	}
	return 0;
}