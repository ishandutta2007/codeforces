#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

bool isvo(char ch)
{
	return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	string s;
	string t;
	cin >> s >> t;
	if (s.size() != t.size())
	{
		cout << "No";
		exit(0);
	}
	for (int i = 0; i < s.size(); ++i)
		{
			if((isvo(s[i]) && isvo(t[i]) )||(!isvo(s[i]) && !isvo(t[i]) ))
			{

			}
			else
			{
				cout << "No";
				exit(0);
			}

		}	
		cout << "Yes";
}