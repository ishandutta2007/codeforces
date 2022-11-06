#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
#ifdef PIYUSH_HOME
	I_O;
#else
#define print(...) 0
#endif
	int n; cin >> n;
	int k; cin >> k;
	int pos;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; if (a[o] == 0) pos = o;}
	vector<int> b(k); for (int o = 0; o < k; o++) { cin >> b[o]; }
	if (k == 1)
	{
		a[pos] = b[0];
		bool f = false;
		for (int i = 0; i < n - 1; ++i)
			if (a[i] >= a[i + 1])
				f = true;
		if (!f)
			cout << "No";
		else
			cout << "Yes";
	}
	else if (k > 1)
	{
		cout << "Yes";
	}
}