//qingyu
#include <bits/stdc++.h>

const int N = 1e5 + 50;

int a[N];

char s[N];

inline char trans(char c)
{
	if (c == 'a') return 'b';
	return 'a';
}

int main()
{
	int t, n;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) scanf("%d", a + i);
		for (int i = 0; i < 100; ++i) s[i] = 'a'; 
		puts(s);
		for (int i = 1; i <= n; ++i)
		{
			s[a[i]] = trans(s[a[i]]);	
			puts(s);
		}	
	}
}