#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	string s; cin >> s;
	int x; cin >> x;
	int y; cin >> y;
	if (x < 0)
	{
		x = -x;
		for (int i = 0; i < n; ++i)
		{
			if (s[i] == 'R')
			{
				s[i] = 'L';
			}
			else if (s[i] == 'L')
			{
				s[i] = 'R';
			}
		}
	}
	if (y < 0)
	{
		y = -y;
		for (int i = 0; i < n; ++i)
		{
			if (s[i] == 'U')
			{
				s[i] = 'D';
			}
			else if (s[i] == 'D')
			{
				s[i] = 'U';
			}
		}
	}


	if (x + y > n || (x + y + n) & 1)
	{
		cout << -1;
		return 0;
	}

	int x2 = 0;
	int y2 = 0;
	std::vector<int> x1(n, 0);
	std::vector<int> y1(n, 0);
	for (int i = 0; i < n; ++i)
	{
		switch (s[i])
		{
		case 'L': x2--;
			break;
		case 'R': x2++;
			break;
		case 'U': y2++;
			break;
		case 'D': y2--;
		}
		x1[i] = x2;
		y1[i] = y2;
	}
	if (x2 == x && y == y2)
	{
		cout << 0;
		return 0;
	}


	int mx = 100000000;


	int st = 0;
	int en = n - 1;


	while (st < en)
	{
		int m = (st + en) / 2;
		int xn = x2 - (x1[m]);
		int yn = y2 - (y1[m]);
		if ((abs(x - xn) + abs(y - yn)) <= (m + 1))
			en = m;
		else
			st = m + 1;
	}
	mx = min(mx, st + 1);


	for (int i = 0; i < n - 1; ++i)
	{
		st = i + 1;
		en = n - 1;
		if (abs(x - x1[i]) + abs(y - y1[i]) > (n - i - 1)) {
			continue;
		}

		while (st < en)
		{
			int m = (st + en) / 2;
			int xn = x2 - (x1[m] - x1[i]);
			int yn = y2 - (y1[m] - y1[i]);
			if ((abs(x - xn) + abs(y - yn)) <= (m - i))
				en = m;
			else
				st = m + 1;
		}
		mx = min(mx, st - i);
	}
	cout << mx;
}