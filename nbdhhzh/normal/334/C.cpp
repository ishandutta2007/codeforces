#include<cstdio>
using namespace std;
long long n;
int main()
{
	scanf("%I64d",&n);
	long long s=1;while (n%s==0)s*=3;
	printf("%I64d",n/s+1);
	return 0;
}