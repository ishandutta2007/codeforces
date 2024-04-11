#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 2E5;
bool used[MAXN + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		queue<int> q;
		for (int i = 1; i <= n; i++)
		{
			q.push(i);
		}
		int small = n / m;
		int big = (n + m - 1) / m;
		int num_big = n - m * small;
		int num_small = m - num_big;
		for (int i = 0; i < k; i++)
		{
			fill(used + 1, used + n + 1, false);
			for (int j = 0; j < num_big; j++)
			{
				cout << big << " ";
				for (int z = 0; z < big; z++)
				{
					cout << q.front() << " ";
					used[q.front()] = true;
					q.push(q.front());
					q.pop();
				}
				cout << "\n";
			}
			int ptr = 1;
			for (int j = 0; j < num_small; j++)
			{
				cout << small << " ";
				for (int z = 0; z < small; z++)
				{
					while (used[ptr])
						ptr++;
					cout << ptr << " ";
					used[ptr] = true;
				}
				cout << "\n";
			}
		}
		cout << "\n";
	}
	return 0;
}