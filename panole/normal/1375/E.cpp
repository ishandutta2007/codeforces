#include<bits/stdc++.h>
using namespace std;

int rk[1010],a[1010],n,po[1010],ans;
pair<int,int> p[1010];

int main()
{
	scanf("%d",&n),ans=0;
	for (int i=1; i<=n; i++) 
	{
		scanf("%d",&a[i]),p[i]=make_pair(a[i],i);
		for (int j=1; j<i; j++) if (a[j]>a[i]) ans++;
	}
	printf("%d\n",ans),sort(p+1,p+1+n);
	for (int i=1; i<=n; i++) a[p[i].second]=i;
	for (int i=1; i<n; i++)
	{
		if (a[i]==i) continue;
		memset(po,0,sizeof(po));
		for (int j=i+1; j<=n; j++)
			if (a[i]>a[j]) po[a[j]]=j;
		for (int j=a[i]-1; j>=i; j--)
			if (po[j]) printf("%d %d\n",i,po[j]),swap(a[i],a[po[j]]);
	}
	return 0;
}