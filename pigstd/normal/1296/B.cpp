#include<bits/stdc++.h>
using namespace std;

double k=1.11111111111;
int T;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		int b=a*k;
		printf("%d\n",b);
	}
	return 0;
}