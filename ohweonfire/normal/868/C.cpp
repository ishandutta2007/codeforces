#include<bits/stdc++.h>
using namespace std;

int n,m,a[100111],cnt[16];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int k=0;k<m;k++)
		{
			int x;scanf("%d",&x);
			a[i]|=x<<k;
		}
		cnt[a[i]]++;
	}
	for(int i=0;i<(1<<m);i++)for(int j=0;j<(1<<m);j++)if(cnt[i]&&cnt[j]&&(i&j)==0)
	{
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}