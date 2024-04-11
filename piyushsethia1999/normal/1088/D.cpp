#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

char get(int a, int b, int i, int aa, int bb)
{
	a = a | (aa << i);
	b = b | (bb << i);
	cout << "? " << a << " " << b << endl;
	int u;
	cin >> u;
	if (u > 0)
		return '>';
	else if (u < 0)
		return '<';
	return '=';
}

void Set(int &a, int &b, int i, int aa, int bb)
{
	a = a | (aa << i);
	b = b | (bb << i);
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int init = 0;
	char ch = '>';
	int a = 0;
	int b = 0;
	for (int i = 29; i >= 0; --i)
	{
		if (!init)
			ch = get(a, b, i, 0, 0);
		if (ch == '<')
		{
			ch = get(a, b, i, 0, 1);
			if (ch == '>')
			{
				init = 1;
				ch = get(a, b, i, 1, 1);
				if (ch == '>')
				{
					Set(a, b, i, 0, 1);
					ch = '>';
				}
				else
				{
					Set(a, b, i, 1, 1);
					ch = '<';
				}
			}
			else if (ch == '<')
			{
				ch = get(a, b, i, 1, 1);
				init = 1;
				if (ch == '>')
				{
					Set(a, b, i, 0, 1);
					ch = '<';
				}
				else
				{
					Set(a, b, i, 0, 0);
					ch = '<';
				}
			}
			else
			{
				Set(a, b, i, 0, 1);
				init = 0;
			}
		}
		else if (ch == '>')
		{
			ch = get(a, b, i, 0, 1);
			if (ch == '>')
			{
				ch = get(a, b, i, 1, 1);
				init = 1;
				if (ch == '>')
					Set(a, b, i, 1, 1);
				else
					Set(a, b, i, 1, 0);
				ch = '>';
			}
			else if (ch == '<')
			{
				ch = get(a, b, i, 1, 0);
				if (ch == '>')
				{
					Set(a, b, i, 0, 0);
					ch = '>';
				}
				else
				{
					Set(a, b, i, 1, 0);
					ch = '<';
				}
				init = 1;
			}
			else
			{
				Set(a, b, i, 1, 0);
				init = 0;
			}
		}
		else {
			ch = get(a, b, i, 1, 0);
			if (ch == '<')
				Set(a, b, i, 1, 1);
			else
				Set(a, b, i, 0, 0);
			init = 0;
		}
	}
	cout << "! " << a << " " << b << endl;
}