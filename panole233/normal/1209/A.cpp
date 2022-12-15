#include<bits/stdc++.h>
using namespace std;

int n,a[110],ans;

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n),ans=0;
	for (int i=1; i<=n; i++)
	{
		bool bo=0;
		for (int j=1; j<i; j++) if (a[i]%a[j]==0) bo=1;
		if (!bo) ans++;
	}
	printf("%d\n",ans);
	return 0;
}