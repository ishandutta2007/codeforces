#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 1E5;
const int BLOCK = 300;
int p[MAXN + 1];
int pi[MAXN + 1];
int b[MAXN + 1]; 

void upd(int x)
{
	int y = x;
	for (int i = 0; i < BLOCK - 1; i++)
	{
		y = pi[y];
	}
	for (int i = 0; i < BLOCK; i++)
	{
		x = p[x];
		b[y] = x;
		y = p[y];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}
	for (int i = 1; i <= n; i++)
	{
		pi[p[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		int j = i;
		for (int k = 0; k < BLOCK; k++)
		{
			j = p[j];
		}
		b[i] = j;
	}
	while (q--)
	{
		int type;
		cin >> type;
		int x, y;
		cin >> x >> y;
		if (type == 1)
		{
			swap(pi[p[x]], pi[p[y]]);
			swap(p[x], p[y]);
			upd(x);
			upd(y);
		}
		else
		{
			while (y >= BLOCK)
			{
				x = b[x];
				y -= BLOCK;
			}
			while (y)
			{
				x = p[x];
				y--;
			}
			cout << x << "\n";
		}
	}
	return 0;
}