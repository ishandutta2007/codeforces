#include <bits/stdc++.h>

const int N = 1e5 + 50;

int n, a[N];

inline void put(bool kk)
{
	if (kk) printf("Ya ");
	else printf("Tidak ");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int A, B, C, D;
		scanf("%d%d%d%d", &A, &B, &C, &D);
		int sign = (A + B) & 1;
			bool a = A || D, b = B || C;
		if (sign)
		{
			put(a), put(b), put(false), put(false), putchar('\n');
		
		}
		else
		{
			put(false), put(false);
			put(b), put(a), putchar('\n');
		
		}

	}
}