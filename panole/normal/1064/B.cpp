#include<cstdio>
#include<cstring>

int a,b,c;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&a);
		int cnt=0;
		for (int i=0; i<31; i++)
			if ((a>>i)&1) cnt++;
		printf("%d\n",1<<cnt);
	}
	return 0;
}