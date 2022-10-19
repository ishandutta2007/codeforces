#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;

int main()
{
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		int cnt = 0 , cnt1 = 0 , cnt2 = 0;
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == '(')
				cnt1++;
			if(s[i] == '[')
				cnt2++;
			if(s[i] == ')')
			{
				if(cnt1 != 0)
				{
					cnt++;
					cnt1--;
				}
			}
			if(s[i] == ']')
			{
				if(cnt2 != 0)
				{
					cnt++;
					cnt2--;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}