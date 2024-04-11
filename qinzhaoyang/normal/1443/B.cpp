#include <bits/stdc++.h>

using namespace std;

int t , a , b;
string s;
int x[100010] , cnt , temp;

int main()
{
	cin >> t;
	while(t--)
	{
		cin >> a >> b >> s;
		s = "0" + s;
		cnt = temp = 0;
		int flag = false;
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == '0')
				flag = true;
			if(s[i] == '0')
				temp++;
			else if(s[i] == '1' && s[i - 1] == '0')
			{
				x[++cnt] = temp;
				temp = 0;
			}
		}
		if(flag == false)
			cout << a << endl;
		else if(cnt == 0)
			cout << 0 << endl;
		else
		{
			int ans = a;
			for(int i = 2; i <= cnt; i++)
			{
				if(a > x[i] * b)
					ans += x[i] * b;
				else
					ans += a;
			}
			cout << ans << endl;
		}
	}
	return 0;
}