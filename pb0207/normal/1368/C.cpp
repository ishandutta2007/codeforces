#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
	scanf("%d",&n);
	printf("%d\n",n*3+4);
	puts("0 0");
	puts("0 1");
	puts("1 0");
	puts("1 1");
	for(int i=1;i<=n;i++)
	{
		printf("%d %d\n",i+1,i);
		printf("%d %d\n",i+1,i+1);
		printf("%d %d\n",i,i+1);
	}
}