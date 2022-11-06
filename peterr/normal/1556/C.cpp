#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int a[MAXN];
long long pref[MAXN];

long long query(int l, int r)
{
	if (l)
		return pref[r] - pref[l - 1];
	return pref[r];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (i & 1)
			a[i] = -a[i];
	}
	pref[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		pref[i] = pref[i - 1] + a[i];
	}
	long long ans = 0;
	for (int i = 0; i < n; i += 2)
	{
		long long bal = a[i];
		long long minBal = bal;
		for (int j = i + 1; j < n; j += 2)
		{
			minBal = min(minBal, bal);
			long long rem = min(minBal, (long long) a[i] - 1);
			if (rem + abs(a[j]) >= bal)
			{
				long long mn = max(bal - rem, 0LL);
				long long mx = min(bal, (long long) abs(a[j]));
				if (mx >= mn)
					ans += mx - mn + 1;
				//cout << "bal " << bal << endl;
				//cout << "minbal " << minBal << endl;
				//cout << "rem " << rem << endl;
				//cout << "mx mn " << mx << " " << mn << endl;
			}
			bal += a[j];
			if (bal < 0)
				break;
			minBal = min(bal, minBal);
			if (j + 1 < n)
				bal += a[j + 1];
		}
	}
	cout << ans << "\n";
	return 0;
}