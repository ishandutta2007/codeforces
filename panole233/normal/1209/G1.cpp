#include<bits/stdc++.h>
using namespace std;

int n,q,a[200010],l[200010],r[200010],pre[200010],bel[200010],cnt[200010],ma[200010];

int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1; i<=200000; i++) cnt[i]=l[i]=r[i]=0;
	for (int i=1; i<=n; i++) 
	{
		scanf("%d",&a[i]);
		if (!l[a[i]]) l[a[i]]=i;
		r[a[i]]=i,cnt[a[i]]++;
	}
	for (int i=0; i<=n; i++) pre[i]=0;
	for (int i=1; i<=200000; i++) if (l[i])
		pre[l[i]]=max(pre[l[i]],r[i]);
	for (int i=2; i<=n; i++) pre[i]=max(pre[i-1],pre[i]);
	for (int i=1; i<=n; i++) if (pre[i-1]==i-1) bel[i]=i; else bel[i]=bel[i-1];
	memset(ma,0,sizeof(ma));
	for (int i=1; i<=200000; i++) if (l[i]) ma[bel[l[i]]]=max(ma[bel[l[i]]],cnt[i]);
	int ans=n;
	for (int i=1; i<=n; i++) if (bel[i]==i) ans-=ma[i];
	printf("%d\n",ans);
	return 0;
}