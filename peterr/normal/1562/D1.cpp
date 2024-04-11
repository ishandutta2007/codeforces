#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
int a[MAXN + 1];
int pref[MAXN + 2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, q;
		string s;
		cin >> n >> q >> s;
		for (int i = 0; i < (int) s.length(); i++)
		{
			if ((s[i] == '+') == (i & 1))
				a[i + 1] = 1;
			else
				a[i + 1] = -1;
			pref[i + 1] = pref[i] + a[i + 1];
			//cout << "pref " << i << " " << pref[i] << endl;
		}
		//cout << "here is a " << endl;
		//for (int i = 1; i <= n; i++)
			//cout << a[i] << " \n"[i == n];
		while (q--)
		{
			int l, r;
			cin >> l >> r;
			int sum = pref[r] - pref[l - 1];
			//cout << "lr " << l << " " << r << endl;
			//cout << "pref1 " << pref[r] << endl;
			//cout << "pref2 " << pref[l - 1] << endl;
			//cout << "sum is " << sum << endl;
			if (sum == 0)
				cout << "0\n";
			else if (abs(sum) & 1)
				cout << "1\n";
			else
				cout << "2\n";
		}
	}
	return 0;
}