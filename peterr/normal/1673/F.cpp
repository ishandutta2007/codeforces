#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 32;
int a[MAXN][MAXN];
int b[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void f(int r1, int c1, int r2, int c2, int pos)
{
	if (r2 == r1 + 1 && c2 == c1 + 1)
	{
		assert(pos >= -1);
		return;
	}
	int midr = (r1 + r2) / 2;
	int midc = (c1 + c2) / 2;
	int diffr = r2 - r1;
	int diffc = c2 - c1;
	if (diffr > diffc)
	{
		bool flip = ((r1 / diffr) & 1) > 0;
		//bool flip = false;
		//cout << "flip " << c1 << " " << c2 << " " << flip << endl;
		for (int r = flip ? r1 : midr; r < (flip ? midr : r2); r++)
		{
			for (int c = c1; c < c2; c++)
			{
				a[r][c] = a[r][c] ^ (1 << pos);
			}
		}
		f(r1, c1, midr, c2, pos - 1);
		f(midr, c1, r2, c2, pos - 1);
	}
	else
	{
		bool flip = ((c1 / diffc) & 1) > 0;
		//bool flip = false;
		for (int c = flip ? c1 : midc; c < (flip ? midc : c2); c++)
		{
			for (int r = r1; r < r2; r++)
			{
				a[r][c] = a[r][c] ^ (1 << pos);
			}
		}
		f(r1, c1, r2, midc, pos - 1);
		f(r1, midc, r2, c2, pos - 1);
	}
}

bool check(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int x = 0; x < n; x++)
			{
				for (int y = 0; y < n; y++)
				{
					if (i == x && j == y)
						continue;
					if (a[i][j] == a[x][y])
						return false;
				}
			}
		}
	}
	return true;
}

void dfs(int r, int c, int cur)
{
	b[r][c] = cur;
	visited[r][c] = true;
	for (int i = 0; i < 4; i++)
	{
		int newr = r + dr[i];
		int newc = c + dc[i];
		if (newr < 0 || newc < 0 || newr >= MAXN || newc >= MAXN || visited[newr][newc])
			continue;
		dfs(newr, newc, cur ^ a[r][c] ^ a[newr][newc]);
	}
}

int main()
{
	int n = 32;
	f(0, 0, n, n, 9);
	//for (int i = 0; i < n; i++)
	//{
		//for (int j = 0; j < n; j++)
		//{
			//cout << bitset<11>(a[i][j]) << " \n"[j == n - 1];
			//cout << a[i][j] << " \n"[j == n - 1];
			//if (j)
				//cout << (a[i][j] ^ a[i][j - 1]) << " \n"[j == n - 1];
		//}
	//}
	//int sum = 0;
	//for (int i = 0; i < n; i++)
	//{
		//for (int j = 0; j < n - 1; j++)
		//{
			//sum += a[i][j] ^ a[i][j + 1];
		//}
	//}
	//for (int i = 0; i < n - 1; i++)
	//{
		//for (int j = 0; j < n; j++)
		//{
			//sum += a[i][j] ^ a[i + 1][j];
		//}
	//}
	//cout << sum << endl;
	//cout << check(n) << endl;
	int k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			cout << (a[i][j] ^ a[i][j + 1]) << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << (a[i][j] ^ a[i + 1][j]) << " ";
		}
		cout << endl;
	}
	int curr = 0;
	int curc = 0;
	while (k--)
	{
		for (int i = 0; i < MAXN; i++)
			fill(visited[i], visited[i] + MAXN, false);
		dfs(curr, curc, 0);
		int x;
		cin >> x;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (b[i][j] == x)
				{
					curr = i;
					curc = j;
				}
			}
		}
		cout << curr + 1 << " " << curc + 1 << endl;
	}
	return 0;
}