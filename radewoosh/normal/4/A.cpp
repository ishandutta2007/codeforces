#include <iostream>
#include <cstdio>
using namespace std;

int n;

int main()
{
	scanf("%d", &n);
	if (n&1 || n<4)
	printf("NO");
	else
	printf("YES");
	return 0;
}