#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
bool ans[MAXN];

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
		fill(ans, ans + n, false);
		vector<tuple<int, int, int>> a;
		vector<tuple<int, int, int>> b;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			a.push_back({x, 0, i});
		}
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			get<1>(a[i]) = x;
			b.push_back({x, get<0>(a[i]), i});
		}
		sort(a.rbegin(), a.rend());
		sort(b.rbegin(), b.rend());
		ans[get<2>(a[0])] = true;
		ans[get<2>(b[0])] = true;
		int mina = get<1>(b[0]);
		int minb = get<1>(a[0]);
		int ptr1 = 1;
		int ptr2 = 1;
		while (true)
		{
			bool changed = false;
			while (ptr1 < n && get<0>(a[ptr1]) > mina)
			{
				changed = true;
				ans[get<2>(a[ptr1])] = true;
				minb = min(minb, get<1>(a[ptr1]));
				ptr1++;
			}
			while (ptr2 < n && get<0>(b[ptr2]) > minb)
			{
				changed = true;
				ans[get<2>(b[ptr2])] = true;
				mina = min(mina, get<1>(b[ptr2]));
				ptr2++;
			}
			if (!changed)
				break;
		}
		for (int i = 0; i < n; i++)
			cout << ans[i];
		cout << "\n";
	}
	return 0;
}