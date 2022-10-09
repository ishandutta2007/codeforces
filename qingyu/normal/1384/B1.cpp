//qy
#include <bits/stdc++.h>

const int N = 1e6 + 50;

int n, k, L;
int d[N];
std::vector<int> vec;

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read()
{
	int res = 0, neg = 1; char ch; 
	do 
	{
		ch = nc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res * neg;
}

#define UP   true
#define DOWN false

inline bool check(int l, int r)
{
	int t = k;
	bool direction = DOWN;
	for (int i = l; i <= r; ++i)
	{
		if (direction == DOWN)
		{
			--t;
			if (d[i] > L) return false;
			if (L - d[i] < t)
			{
				t = L - d[i];
			}
			if (t == 0) direction = UP;
		}
		else
		{
			++t;
			if (d[i] + t > L) return false;
		}
	}
	return true;
}

int main()
{
	int t = read();
	while (t--)
	{
		vec.clear();
		n = read(), k = read(), L = read();
		for (int i = 1; i <= n; ++i) d[i] = read();
		vec.emplace_back(0);
		for (int i = 1; i <= n; ++i) if (d[i] + k <= L) vec.emplace_back(i);
		vec.emplace_back(n + 1);
		int s = vec.size();
		for (int i = 0; i < s - 1; ++i) if (!check(vec[i] + 1, vec[i + 1] - 1)) goto failed;
	
		puts("Yes");
		continue;
failed:
		puts("No");
	}
}