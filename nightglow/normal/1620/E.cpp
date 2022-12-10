#include <bits/stdc++.h>

#define N 500005

#define pb push_back
#define mk make_pair
#define fi first
#define se second

using namespace std;

int last[N], fa[N], q, pos, val[N]; 

int get(int x)
{
	return fa[x] == x ? x : fa[x] = get(fa[x]);
}
int main()
{
	scanf("%d", &q);
	for (;q--;)
	{
		int ty, x, y;
		scanf("%d%d", &ty, &x);
		if (ty == 1)
		{
			++pos; val[pos] = x;
			if (!last[x]) last[x] = pos, fa[pos] = pos;
			else fa[pos] = last[x];
		}
		else
		{
			scanf("%d", &y); if (x == y) continue;
			if (!last[y]) last[y] = last[x], val[last[x]] = y, last[x] = 0;
			else
			{
				if (last[x]) fa[last[x]] = last[y], last[x] = 0;
			}
		}
	}
	for (int i = 1; i <= pos; ++i) printf("%d%c", val[get(i)], i == pos ? '\n' : ' ');
}