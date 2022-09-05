#include<bits/stdc++.h>
using namespace std;

int n,x,T,a[100010];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&x); int ans=0;
		for (int i=1; i<=n; i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		for (int i=1; i<=n; i++) if (a[i]==x) {ans=1; break;}
		if (ans) {puts("1"); continue;}
		ans=max((x-1)/a[n]+1,2);
		printf("%d\n",ans);
	}
	return 0;
}