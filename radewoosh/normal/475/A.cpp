#include <iostream>
#include <cstdio>
using namespace std;

int n;
char gut='O';
char bad='#';

char c(int v)
{
	if (v<=n)
	return gut;
	return bad;
}

int main()
{
	scanf("%d", &n);
	printf("+------------------------+\n");
	printf("|%c.%c.%c.%c.%c.%c.%c.%c.%c.%c.%c.|D|)\n", c(1), c(5), c(8), c(11), c(14), c(17), c(20), c(23), c(26), c(29), c(32));
	printf("|%c.%c.%c.%c.%c.%c.%c.%c.%c.%c.%c.|.|\n", c(1+1), c(5+1), c(8+1), c(11+1), c(14+1), c(17+1), c(20+1), c(23+1), c(26+1), c(29+1), c(32+1));
	printf("|%c.......................|\n", c(3));
	printf("|%c.%c.%c.%c.%c.%c.%c.%c.%c.%c.%c.|.|)\n", c(2+2), c(5+2), c(8+2), c(11+2), c(14+2), c(17+2), c(20+2), c(23+2), c(26+2), c(29+2), c(32+2));
	printf("+------------------------+");
	return 0;
}