#include<bits/stdc++.h>
using namespace std;

long long a,b,c;

int main()
{
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	a=2*c+2*min(a,b)+(a!=b);
	printf("%I64d\n",a);
	return 0;
}