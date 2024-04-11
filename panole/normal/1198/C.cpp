#include<bits/stdc++.h>
using namespace std;

int T,n,m,hd[300010],x[500010],y[500010],ans[500010],ansn;
bool bo[300010];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1; i<=m; i++) scanf("%d%d",&x[i],&y[i]);
		for (int i=1 ;i<=3*n; i++) bo[i]=0;
		ansn=0;
		for (int i=1 ;i<=m; i++)
			if (!bo[x[i]]&&!bo[y[i]]) bo[x[i]]=bo[y[i]]=1,ans[++ansn]=i;
		if (ansn>=n)
		{
			puts("Matching");
			for (int i=1; i<=n; i++) printf("%d ",ans[i]); puts("");
		} else
		{
			puts("IndSet"); int cnt=0;
			for (int i=1; i<=3*n; i++)
				if (!bo[i])
				{
					printf("%d ",i),cnt++;
					if (cnt==n) break;
				}
			puts("");
		}
	}
	return 0;
}