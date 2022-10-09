#include <bits/stdc++.h>

const int N = 1e6 + 50;
int n, f[26]; std::vector<std::pair<char, char> > v;
char s[N], t[N];

inline int find(int x) { while (x != f[x]) x = f[x] = f[f[x]]; return x; }

int main()
{
	scanf("%d%s%s", &n, s, t);
	for (int i = 0; i < 26; ++i) f[i] = i;
	for (int i = 0; i < n; ++i)
	{
		int c1 = s[i] - 'a', c2 = t[i] - 'a';
		c1 = find(c1), c2 = find(c2);
		if (c1 != c2)
		{
			v.emplace_back(c1 + 'a', c2 + 'a');
			f[c1] = c2;
		}
	}
	printf("%d\n", v.size());
	for (auto c : v) printf("%c %c\n", c.first, c.second);
}

// By Qingyu