#include<bits/stdc++.h> 
using namespace std;

long long r;

int main()
{
	scanf("%I64d",&r);
	for (int x=1; 1ll*x*x+3*x+1<=r; x++)
	{
		long long y=r-1ll*x*x-x-1;
		if (y%(2*x)==0) return printf("%d %I64d\n",x,y/(2*x)),0;
	}
	puts("NO");
	return 0;
}