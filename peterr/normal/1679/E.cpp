#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
const int MAXM = 17;
const int MOD = 998244353;
int a[MAXM + 1][1 << MAXM];
int pw[MAXM + 1][MAXN + 1];

void add(int &x, int y)
{
	x += y;
	if (x >= MOD)
		x -= MOD;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 1; i <= MAXM; i++)
	{
		pw[i][0] = 1;
		for (int j = 1; j <= MAXN; j++)
		{
			pw[i][j] = (int) ((long long) pw[i][j - 1] * i % MOD);
		}
	}
	int n, q;
	string s;
	cin >> n >> s >> q;
	int totalq = 0;
	for (char ch : s)
		totalq += ch == '?';
	for (int m = 1; m <= MAXM; m++)
	{
		for (int i = 0; i < n; i++)
		{
			int qs = s[i] == '?';
			int choices = qs;
			int mask = 0;
			add(a[m][mask], pw[m][choices + (totalq - qs)]);
			for (int j = 1; i - j >= 0 && i + j < n; j++)
			{
				qs += s[i - j] == '?';
				qs += s[i + j] == '?';
				if (s[i - j] == '?' && s[i + j] == '?')
				{
					choices++;
				}
				else if (s[i - j] == '?' || s[i + j] == '?')
				{
					int key = s[i - j] != '?' ? s[i - j] - 'a' : s[i + j] - 'a';
					mask = mask | (1 << key);
				}
				else if (s[i - j] != s[i + j])
					break;
				if (m == 1)
				{
					//cout << i - j << " " << i + j << " " << choices + (totalq - qs) << endl;
					//cout << "\t" << choices << endl;
					//cout << "\t" << totalq - qs << endl;
				}
				add(a[m][mask], pw[m][choices + (totalq - qs)]);
			}
		}
	}
	for (int m = 1; m <= MAXM; m++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			int qs = 0;
			int choices = 0;
			int mask = 0;
			for (int j = 0; i - j >= 0 && i + j + 1 < n; j++)
			{
				qs += s[i - j] == '?';
				qs += s[i + j + 1] == '?';
				if (s[i - j] == '?' && s[i + j + 1] == '?')
				{
					choices++;
				}
				else if (s[i - j] == '?' || s[i + j + 1] == '?')
				{
					int key = s[i - j] != '?' ? s[i - j] - 'a' : s[i + j + 1] - 'a';
					mask = mask | (1 << key);
				}
				else if (s[i - j] != s[i + j + 1])
					break;
				add(a[m][mask], pw[m][choices + (totalq - qs)]);
			}
		}
	}
	for (int i = 1; i <= MAXM; i++)
	{
		for (int j = 0; j < MAXM; j++)
		{
			for (int k = 0; k < (1 << MAXM); k++)
			{
				if (k & (1 << j))
					add(a[i][k], a[i][k ^ (1 << j)]);
			}
		}
	}
	while (q--)
	{
		int mask = 0;
		string t;
		cin >> t;
		for (char ch : t)
		{
			int key = ch - 'a';
			mask = mask ^ (1 << key);
		}
		cout << a[(int) t.length()][mask] << "\n";
	}
	return 0;
}