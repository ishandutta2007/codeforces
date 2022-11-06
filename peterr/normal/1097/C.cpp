#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5E5;
int freq1[MAXN + 1];
int freq2[MAXN + 1];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		int bal = 0;
		int mn = 0;
		for (char ch : s)
		{
			if (ch == '(')
				bal++;
			else
				bal--;
			mn = min(mn, bal);
		}
		if (mn < 0 && mn < bal)
		{
			//cout << "skip " << i << endl;
			continue;
		}
		if (bal >= 0)
			freq1[bal]++;
		else
			freq2[-bal]++;
	}
	int ans = freq1[0] / 2;
	for (int i = 1; i <= MAXN; i++)
	{
		ans += min(freq1[i], freq2[i]);
		////cout << "freq " << i << " " << freq1[i] << endl;
		//cout << "freq " << i << " " << freq2[i] << endl;
	}
	cout << ans << "\n";
	return 0;
}