#include <cstdio>
using namespace std;
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;(i*i+1)/2<n;i+=2);
	if(n==3)
		puts("5");
	else
		printf("%d\n",i);
	return 0;
}