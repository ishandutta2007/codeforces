#include<bits/stdc++.h>
using namespace std;

int b,g,n;

int main()
{
	scanf("%d%d%d",&b,&g,&n);
	int nas=0;
	for (int i=0; i<=b&&i<=n; i++)
		if (n-i<=g) nas++;
	printf("%d\n",nas);
	return 0;
}