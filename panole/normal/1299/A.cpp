#include<bits/stdc++.h>
using namespace std;

int n,a[100010],cnt[41]; 

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) 
	{
		scanf("%d",&a[i]);
		for (int j=0; j<30; j++) cnt[j]+=(a[i]>>j&1);
	}
	for (int j=29; j>=0; j--)
		if (cnt[j]==1)
		{
			int p=0;
			for (int i=1; i<=n; i++) if (a[i]>>j&1) p=i;
			printf("%d ",a[p]);
			for (int i=1; i<=n; i++) if (i!=p) printf("%d ",a[i]);
			return puts(""),0;
		}
	for (int i=1; i<=n; i++) printf("%d ",a[i]);
	return puts(""),0; 
}