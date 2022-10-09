#include <bits/stdc++.h>

const int N = 1e5 + 50;
std::multiset<int, std::greater<int>> ms;

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read()
{
	int res = 0;
	char ch;
	do ch = nc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res;
}

int gcd(int x, int y)
{
	return y ? gcd(y, x % y) : x;
}

int main()
{
	int n = read();
	for (int i = 1; i <= n * n; ++i) ms.insert(read());
	std::vector<int> a;
	while (!ms.empty())
	{
		int x = *ms.begin();
		auto it = ms.find(x);
		ms.erase(it);
		for (int y : a) 
		{
			auto it = ms.find(gcd(x, y));
			ms.erase(it);
			it = ms.find(gcd(x, y));
			ms.erase(it);
		}
		a.push_back(x);
	}
	for (int x : a) printf("%d ", x);
	return 0;
}