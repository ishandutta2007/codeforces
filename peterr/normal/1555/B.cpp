#include <bits/stdc++.h>

using namespace std;

const double INF = 1E18;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int w, h, x1, y1, x2, y2;
		cin >> w >> h >> x1 >> y1 >> x2 >> y2;
		int ww, hh;
		cin >> ww >> hh;
		double ans = INF;
		if (hh + y2 - y1 <= h)
		{
			ans = min(ans, max(0.0, 0.0 + hh - (h - y2)));
			ans = min(ans, max(0.0, 0.0 + hh - y1));
		}
		if (ww + x2 - x1 <= w)
		{
			ans = min(ans, max(0.0, 0.0 + ww - (w - x2)));
			ans = min(ans, max(0.0, 0.0 + ww - x1));
		}
		if (ans == INF)
			cout << "-1\n";
		else
			cout << fixed << setprecision(7) << ans << "\n";
	}
	return 0;
}