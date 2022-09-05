#include<bits/stdc++.h>
using namespace std;

int n,T,a[5010],k,m;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n,&m,&k),k=min(k,--m);
		for (int i=1; i<=n; i++) scanf("%d",&a[i]);
		int ans=0;
		for (int i=0; i<=k; i++)
		{
			int nw=1000000000;
			for (int j=0; j<=m-k; j++) nw=min(nw,max(a[i+j+1],a[n-(k-i)-(m-k-j)]));
			ans=max(ans,nw);
		}
		printf("%d\n",ans);
	}
	return 0;
}