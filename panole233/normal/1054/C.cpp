#include<cstdio>
#include<cstring>

int l[1001],r[1001],n,ans[1001],cnt,t[1001],nw;
bool bo[1001];

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&l[i]);
	for (int i=1; i<=n; i++) scanf("%d",&r[i]);
	cnt=nw=n;
	memset(bo,1,sizeof(bo));
	while (cnt)
	{
		t[0]=0;
		for (int i=1; i<=n; i++)
			if (bo[i]&&(!l[i])&&(!r[i])) t[++t[0]]=i,bo[i]=0,ans[i]=nw;
		if (!t[0]) {printf("NO\n"); return 0;}
		nw--; cnt-=t[0];
		for (int i=1; i<=t[0]; i++)
		{
			for (int j=1; j<t[i]; j++) 
				if (bo[j]) r[j]--;
			for (int j=t[i]+1; j<=n; j++) 
				if (bo[j]) l[j]--;
		}
	}
	printf("YES\n");
	for (int i=1; i<=n; i++) printf("%d ",ans[i]);
	return 0;
}