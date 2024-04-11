#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);

	int n, w;
	cin >> n >> w;

	int cur(0), minD(0), maxD(0);
	for (int i(0); i < n; ++i)
	{
		int c; cin >> c;
		cur += c;
		minD = min(minD, cur);
		maxD = max(maxD, cur);
	}

	if (maxD > w or minD < -w)
		cout << 0 << endl;
	else
	{
		int left = -minD, right = w - maxD;
		cout << max(0, right - left + 1) << endl;
	}
}