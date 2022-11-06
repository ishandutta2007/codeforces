#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int a[MAXN];
bool del[MAXN];
int prev_[MAXN + 1];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		fill(del, del + MAXN, false);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			prev_[i] = i - 1;
		}
		prev_[n] = n - 1;
		int cnt = 0;
		while (cnt < n)
		{
			int forward = n;
			int ind = prev_[n];
			int skipped = n - 1 - ind;
			while (ind != -1 && a[ind] % (ind + 2 - cnt + skipped) == 0)
			{
				forward = ind;
				ind = prev_[ind];
				skipped += forward - ind - 1;
			}
			if (ind == -1)
				break;
			del[ind] = true;
			cnt++;
			prev_[forward] = prev_[ind];
		}
		cout << (cnt == n ? "YES" : "NO") << "\n";
	}
	return 0;
}