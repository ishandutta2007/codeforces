#include <cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	if(!(n&1))
		printf("%d 4\n",n-4);
	else
		printf("%d 9\n",n-9);
	return 0;
}