#include <bits/stdc++.h>

int main()
{
	int w, h, u1, h1, u2, h2;
	scanf("%d%d%d%d%d%d", &w, &h, &u1, &h1, &u2, &h2);
	for (int i = h; i >= 0; --i)
	{
		w += i;
		if (i == h1)
		{
			w -= u1;
		}
		if (i == h2)
		{
			w -= u2;	
		}
		if (w < 0) w = 0;
	}
	printf("%d", w);
	return 0;
}