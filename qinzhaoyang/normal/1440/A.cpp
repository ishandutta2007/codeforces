#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n , c0 , c1 , h;
		string s;
		cin >> n >> c0 >> c1 >> h;
		cin >> s;
		int ans = 0;
		if(c0 + h < c1)
		{
			for(int i = 0; i < s.size(); i++)
			{
				if(s[i] == '0')
					ans += c0;
				else
					ans += c0 + h;
			}
		}
		else if(c1 + h < c0)
		{
			for(int i = 0; i < s.size(); i++)
			{
				if(s[i] == '1')
					ans += c1;
				else
					ans += c1 + h;
			}
		}
		else
		{
			for(int i = 0; i < s.size(); i++)
			{
				if(s[i] == '0')
					ans += c0;
				else
					ans += c1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}