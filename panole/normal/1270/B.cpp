#include<bits/stdc++.h>
using namespace std;

int T,n,l,r,a[200010];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1; i<=n; i++) scanf("%d",&a[i]);
		l=r=0;
		for (int i=1; i<n; i++) if (a[i+1]-a[i]>=2||a[i+1]-a[i]<=-2) l=i,r=i+1; 
		if (!l) puts("NO"); else puts("YES"),printf("%d %d\n",l,r);
	}
	return 0;
}