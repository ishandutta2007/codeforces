#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2021;
int a[MAXN];

void op(int n)
{
	for (int i = 0; i < n / 2; i++)
	{
		swap(a[i], a[n - i - 1]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		bool valid = true;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if ((i & 1) == (a[i] & 1))
				valid = false;
		}
		if (valid)
		{
			vector<int> ans;
			for (int i = n; i > 1; i -= 2)
			{
				int j = i - 1;
				int pos1 = 0;
				while (a[pos1] != i)
					pos1++;
				ans.push_back(pos1 + 1);
				op(pos1 + 1);
				int pos2 = 0;
				while (a[pos2] != j)
					pos2++;
				ans.push_back(pos2);
				op(pos2);
				ans.push_back(pos2 + 2);
				op(pos2 + 2);
				ans.push_back(3);
				op(3);
				ans.push_back(i);
				op(i);
			}	
			cout << ans.size() << "\n";
			for (int x : ans)
			{
				cout << x << " ";
			}
			cout << "\n";
		}
		else
		{
			cout << "-1\n";
		}
	}
	return 0;
}