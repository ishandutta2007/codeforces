#include<bits/stdc++.h>
using namespace std;

int n,d,T;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&d); int ans=0;
		for (int i=1; i<=n; i++)
		{
			int x;
			scanf("%d",&x);
			while (x&&d>=i-1) d-=(i-1),ans++,x--;
		}
		printf("%d\n",ans);
	}
	return 0;
}