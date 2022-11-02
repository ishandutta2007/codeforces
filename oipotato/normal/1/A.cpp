#include <cstdio>
using namespace std;
int n,m,a;
int main()
{
	scanf("%d%d%d",&n,&m,&a);
	printf("%I64d\n",(long long)((n-1)/a+1)*((m-1)/a+1));
	return 0;
}