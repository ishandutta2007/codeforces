#include<bits/stdc++.h>
using namespace std;

int a[100010],T,n,k;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&k);
		for (int i=1; i<=n; i++) scanf("%d",&a[i]);
		int ans=n;
		for (int i=1; i<=100; i++)
		{
			int cnt=0,nw=1;
			while (nw<=n)
			{
				while (nw<=n&&a[nw]==i) nw++;
				if (nw>n) break;
				nw+=k,cnt++;
			}
			ans=min(ans,cnt);
		}
		printf("%d\n",ans);
	}
	return 0;
}