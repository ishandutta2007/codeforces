#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

void solve(void)
{
	int n;
	cin >> n;
	vector<vector<int> > kingdoms(n);

	for (int i(0); i < n; ++i)
	{
		int k;
		cin >> k;
		kingdoms[i].resize(k);
		for (int j(0); j < k; ++j)
		{
			cin >> kingdoms[i][j];
			kingdoms[i][j]--;
		}
	}
	vector<bool> available(n, true);
	vector<bool> married(n, false);

	for (int i(0); i < n; ++i)
	{
		int j(0);
		while (j < SZ(kingdoms[i]) and !available[kingdoms[i][j]])
			++j;
		if (j < SZ(kingdoms[i]))
		{
			married[i] = true;
			available[kingdoms[i][j]] = false;
		}
	}
	for (int i(0); i < n; ++i)
		if (!married[i])
			for (int j(0); j < n; ++j)
				if (available[j])
				{
					cout << "IMPROVE\n" << i + 1 << ' ' << j + 1 << '\n';
					return ;
				}
	cout << "OPTIMAL" << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
}