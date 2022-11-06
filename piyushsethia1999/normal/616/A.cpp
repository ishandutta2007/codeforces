#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	string s, s1;
	cin >> s >> s1;
	int j = 0;
	int k = 0;
	while(s[j] == '0') {
		j++;
	}
	while(s1[k] == '0') {
		k++;
	}

	if ((s1.size() - k) > (s.size() - j))
	{
		cout << "<";
		exit(0);
	}
	else if((s.size() - j) > (s1.size() - k))
	{
		cout << ">";
	}
	else
	{
		for (int i = 0; i < (s.size() - j); ++i)
		{
			if(s[j + i] > s1[k + i])
			{
				cout << ">";
				return 0;
			}
			else if(s1[k + i] > s[j + i])
			{
				cout << "<";
				return 0;
			}
		}
		cout << "=";
	}
}