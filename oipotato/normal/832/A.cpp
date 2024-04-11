#include <cstdio>
using namespace std;
long long n,k;
int main()
{
	scanf("%I64d%I64d",&n,&k);
	printf(n/k%2?"YES":"NO");
	return 0;
}