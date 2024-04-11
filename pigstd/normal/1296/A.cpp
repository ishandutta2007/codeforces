#include<bits/stdc++.h>
using namespace std;

int T;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		int n;
		bool ou=0,ji=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			int a;
			scanf("%d",&a);
			if (a%2==0)
				ou=1;
			else
				ji=1;
		}
		if (ou&&!ji)
			printf("NO\n");
		else if (ji&&!ou&&n%2==0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}