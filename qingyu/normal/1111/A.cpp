#include <bits/stdc++.h>

const int N = 1e6 + 50;

char s[N], t[N];

inline bool check(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
	return false;	
}

int main()
{
	scanf("%s%s", s, t);
	int ls = strlen(s), lt = strlen(t);
	if (ls != lt) return printf("No"), 0;
	for (int i = 0; i < ls; ++i)
		if (check(s[i]) != check(t[i]))
			return printf("No"), 0;
	return printf("Yes"), 0;
}