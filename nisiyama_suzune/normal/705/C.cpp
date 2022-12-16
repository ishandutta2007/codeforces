//IO
#include <iostream>
#include <cstdio>
#include <iomanip>

//General
#include <cmath>
#include <cstdlib>
#include <cstring>

//STL
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int N, Q;
int Anc[400000];
int Lo[400000];
int Col[400000], ColT = 1;
int Tm[400000];
int ans;

int GetAnc (int x)
{
	if (Anc[x] == x) return x;
	Anc[x] = GetAnc (Anc[x]);
	return Anc[x];
}

int main ()
{
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	cin >> N >> Q;
	for (int i = 0; i <= Q + 10; i++)
		Anc[i] = i;
	for (int t = 0; t < Q; t++)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int x;
			cin >> x;
			Lo[x]++;
			ans++;
			Col[ColT++] = x;
		}
		if (op == 2)
		{
			int x;
			cin >> x;
			ans -= Lo[x];
			Lo[x] = 0;
			Tm[x] = ColT;
		}
		if (op == 3)
		{
			int t;
			cin >> t;
			int i = 1;
			while (i <= t)
			{
				if (Anc[i] != i)
				{
					i = GetAnc (i);
					continue;
				}
				if (i < Tm[Col[i]])
				{
					Anc[i] = i + 1;
					i = GetAnc (i);
					continue;
				}
				Lo[Col[i]] --;
				ans --;
				Anc[i] = i + 1;
				i ++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}