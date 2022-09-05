#include<bits/stdc++.h>
using namespace std;

int n,m,k,a[200010],b[200010],ta,tb,ans;

int main()
{
	scanf("%d%d%d%d%d",&n,&m,&ta,&tb,&k);
	if (k>=n||k>=m) return puts("-1"),0;
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	for (int i=1; i<=m; i++) scanf("%d",&b[i]);
	int R=m+1; ans=0;
	for (int i=k; i>=0; i--)
	{
		while (R>1&&a[i+1]+ta<=b[R-1]) R--;
		if (R+k-i>m) return puts("-1"),0;
		ans=max(ans,b[R+k-i]);
	}
	printf("%d\n",ans+tb);
	return 0;
}