#include<cstdio>
using namespace std;

long long n;

int main()
{
	scanf("%lld",&n);
	if(n==0)
	{
		puts("0");
		return 0;
	}
	n++;
	printf("%lld",(n&1)?n:n/2);	
}