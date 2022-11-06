#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
bool good[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < (int) s.length() - 2; i++)
	{
		if (s.substr(i, 3) == "abc")
		{
			good[i] = good[i + 1] = good[i + 2] = true;
			ans++;
		}
	}
	while (q--)
	{
		int ind;
		char ch;
		cin >> ind >> ch;
		ind--;
		if (good[ind])
		{
			if (ch != s[ind])
			{
				good[ind] = false;
				ans--;
				if (s[ind] == 'a')
					good[ind + 1] = good[ind + 2] = false;
				else if (s[ind] == 'b')
					good[ind - 1] = good[ind + 1] = false;
				else
					good[ind - 1] = good[ind - 2] = false;
				//cout << "Dec " << endl;
			}
		}
		s[ind] = ch;
		if (!good[ind])
		{
			for (int i = 0; i < 3; i++)
			{
				//cout << "sub " << s.substr(ind - i, 3) << endl;
				if (ind - i + 2 < n && ind - i >= 0 && s.substr(ind - i, 3) == "abc")
				{
					//cout << "foudn " << endl;
					ans++;
					good[ind - i] = good[ind - i + 1] = good[ind - i + 2] = true;
					break;
				}
			}
		}
		//for (int i = 0; i < n; i++)
		//{
			//cout << good[i];
		//}
		//cout << "\n";
		cout << ans << "\n";
	}
	return 0;
}