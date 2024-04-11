#include <bits/stdc++.h>
using namespace std;

int n, m, k;

char wyn='L';

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	k--;
	if (k&1)
		wyn='R';
	k>>=1;
	printf("%d %d %c\n", (k/m)+1, (k%m)+1, wyn);
	return 0;
}