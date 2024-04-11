#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
#include <list>
#include <map>
#include <ctime>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
const int size = 100007;
const ll modulo = 1000000007;
const int INF = 2e9;

int t[size], l[size], r[size];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	int n,m,s,f;
	cin >> n >> m >> s >> f;
	for (int i = 0; i < m; i++)
		cin >> t[i] >> l[i] >> r[i];
	int pos = 0;
	for (int etap = 1; etap <= m + n; etap++)
	{
		if (s == f)
		{
			cout << endl;
			return 0;
		}
		int target = (s < f ? s+1 : s-1);
		if (etap == t[pos])
		{
			if ((s >= l[pos] && s <= r[pos]) || (target >= l[pos] && target <= r[pos]))
				cout << 'X';
			else if (s < f)
			{
				cout << 'R';
				++s;
			}
			else
			{
				cout << 'L';
				--s;
			}
			pos++;
		}
		else if (s < f)
		{
			cout << 'R';
			++s;
		}
		else
		{
			cout << 'L';
			--s;
		}
	}
	return 0;
}