#include <bits/stdc++.h>

using namespace std;

long long a[3];

int main()
{
	long long i;
	
	for(i=0;i<3;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a,a+3);
	if(a[0]==1||(a[0]==2&&(a[1]==2||(a[1]==4&&a[2]==4)))||(a[0]==3&&a[2]==3))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}