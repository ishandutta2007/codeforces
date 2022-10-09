// By Qingyu
#include <bits/stdc++.h>

typedef long long ll;

int a[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
char c[10] = { 'c', 'o', 'd', 'e', 'f', 'o', 'r', 'c', 'e', 's' };

int main()
{
	ll k; scanf("%lld", &k);
	ll forum = 1;
	while (forum < k)
	{
		for (int i = 0; i < 10 && forum < k; ++i)
		{
			forum /= a[i];
			forum *= ++a[i];
		}
	}
	for (int i = 0; i < 10; ++i)
		while (a[i]--) putchar(c[i]);

}