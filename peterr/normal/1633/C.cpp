#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long hc, dc, hm, dm;
		cin >> hc >> dc >> hm >> dm;
		long long k, w, a;
		cin >> k >> w >> a;
		bool ans = false;
		for (int i = 0; i <= k; i++)
		{
			long long h = hc + i * a;
			long long d = dc + (k - i) * w;
			long long turns1 = (hm + d - 1) / d;
			long long turns2 = (h + dm - 1) / dm;
			if (turns1 <= turns2)
				ans = true;
		}
		cout << (ans ? "YES" : "NO") << "\n";
	}
	return 0;
}