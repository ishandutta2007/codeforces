#include<bits/stdc++.h>
using namespace std;

int T,n,k1,k2,x;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		bool bo=0;
		scanf("%d%d%d",&n,&k1,&k2);
		for (int i=1; i<=k1; i++)
		{
			scanf("%d",&x);
			if (x==n) bo=1;
		}
		for (int i=1; i<=k2; i++) scanf("%d",&x);
		if (bo) puts("YES"); else puts("NO");
	}
	return 0;
}