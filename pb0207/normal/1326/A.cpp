#include<bits/stdc++.h>

int T,n;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n==1)
			puts("-1");
		else
		{
			for(int i=1;i<n;i++)
				printf("5");
			puts("4");
		}
	}
}