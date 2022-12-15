#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

void solve(void)
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	string a="";
	string b = "";
	bool f = false;
	for (int i(0); i < n; ++i)
	{
		if (s[i] == '2')
		{
			if (!f)
			{
				a += '1';
				b += '1';
			}
			else
			{
				a += '0';
				b += '2';
			}
		}
		else if (s[i] =='1')
		{
			if (!f)
			{
				a += '1';
				b += '0';
				f = true;
			}
			else
			{
				a += '0';
				b += '1';
			}
		}
		else
		{
			a += '0';
			b += '0';
		}
	}
	cout << a << '\n' << b << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
}