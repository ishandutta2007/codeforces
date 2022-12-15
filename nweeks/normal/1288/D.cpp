#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

const int MAXN = 3e5;
const int MAXM = 8;

int arr[MAXN][MAXM];
int i_have, j_have;
int n, m;

bool can_reach(int goal)
{
	int have[(1<<m)];
	for (int i(0); i < (1<<m); ++i)
		have[i] = -1;

	for (int i(0); i < n; ++i)
	{
		int mask = 0;
		for (int j(0); j < m; ++j)
			mask = 2* mask + (arr[i][j] >= goal);
		for (int j(0); j < (1<<m); ++j)
		{
			if ((j&mask) == j)
				have[j] = i;
			if (have[j] != -1 and (mask|j) == (1<<m)-1)
			{
				i_have = i, j_have = have[j];
				return true;
			}
		}
	}
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i(0); i < n; ++i)
		for (int j(0); j < m; ++j)
			cin >> arr[i][j];
	ll l(1), r(1e9);
	while (l < r)
	{
		ll m = (l+r+1)/2;
		if (can_reach(m))
			l = m;
		else
			r = m-1;
	}
	can_reach(l);
	cout << i_have +1 << ' ' << j_have+1 << endl;
}