//qy
#include <bits/stdc++.h>


const int N = 1e5 + 50;

int n;
char A[N], B[N];
bool buc[26];

int main()
{
	int t, n;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%s%s", &n, A, B);
		int max = 0;
		for (int i = 0; i < n; ++i) if (A[i] > B[i])
		{
			puts("-1");
			goto failed;
		}
		for (int i = 'a'; i <= 't'; ++i)
		{
			for (int j = i + 1; j <= 't'; ++j)
			{
				bool flag = false;
				for (int k = 0; k < n; ++k)
					if (A[k] == i && B[k] == j)
					{
						flag = true;
						break;
					}

				if (flag) 
				{
					for (int k = 0; k < n; ++k) if (A[k] == i && B[k] >= j) A[k] = j;
					++max;

				}
			}
		}
		printf("%d\n", max);
failed:
		;
	}
}