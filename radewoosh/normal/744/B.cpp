#include <bits/stdc++.h>
using namespace std;

int n;

int inf=1000000007;

int wyn[1007];

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		wyn[i]=inf;
	
	for (int h=0; h<10; h++)
	{
		vector <int> raz, dwa;
		
		for (int i=1; i<=n; i++)
		{
			if (i&(1<<h))
				raz.push_back(i);
			else
				dwa.push_back(i);
		}
		
		if (!raz.empty())
		{		
			printf("%d\n", (int)raz.size());
			for (int i=0; i<raz.size(); i++)
				printf("%d ", raz[i]);
			printf("\n");
			fflush(stdout);
			for (int i=1; i<=n; i++)
			{
				int p1;
				scanf("%d", &p1);
				if (!(i&(1<<h)))
					wyn[i]=min(wyn[i], p1);
			}
		}
		
		if (!dwa.empty())
		{
			printf("%d\n", (int)dwa.size());
			for (int i=0; i<dwa.size(); i++)
				printf("%d ", dwa[i]);
			printf("\n");
			fflush(stdout);
			for (int i=1; i<=n; i++)
			{
				int p1;
				scanf("%d", &p1);
				if (i&(1<<h))
					wyn[i]=min(wyn[i], p1);
			}
		}
	}
	
	printf("-1\n");
	for (int i=1; i<=n; i++)
		printf("%d ", wyn[i]);
	printf("\n");
	fflush(stdout);
	return 0;
}