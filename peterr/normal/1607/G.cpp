#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN];
int b[MAXN];
int ans[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		long long bal = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i] >> b[i];
			int realb = max(0, b[i] - m);
			int reala = a[i] - max(0, m - b[i]);
			bal += reala;
			bal -= realb;
			ans[i] = a[i] - reala;
		}
		if (bal > 0)
		{
			for (int i = 0; i < n; i++)
			{
				//cout << "iter " << i << "\n";
				//cout << "bal " << bal << "\n";
				int mx = min(a[i], m);
				//cout << "mx " << mx << "\n";
				int amt = (int) min((long long) mx, ans[i] + bal / 2);
				//cout << "amt " << amt << "\n";
				//cout << "ans[i] " << ans[i] << "\n";
				bal -= 2 * abs(ans[i] - amt);
				ans[i] = amt;
			}
		}
		cout << abs(bal) << "\n";
		for (int i = 0; i < n; i++)
		{
			cout << ans[i] << " " << m - ans[i] << "\n";
		}
	}
	return 0;
}