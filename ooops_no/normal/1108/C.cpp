#include <iostream>
#include<string>

using namespace std;

#define ll long long


int main()
{
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll   ans = INT_MAX;
	string s1, ans1;
	for (int j = 1; j <= 6; j++)
	{
		s1 = s;
		ll cnt = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (j == 1)
			{
				if (i % 3 == 0) {
					if (s1[i] != 'R') cnt++, s1[i] = 'R';
				}
				if (i % 3 == 1) {
					if (s1[i] != 'G') cnt++, s1[i] = 'G';
				}
				if (i % 3 == 2) {
					if (s[i] != 'B') cnt++, s1[i] = 'B';
				}
			}
			if (j == 2)
			{
				if (i % 3 == 0)
					if (s1[i] != 'R') cnt++, s1[i] = 'R';
				if (i % 3 == 1)
					if (s1[i] != 'B') cnt++, s1[i] = 'B';

				if (i % 3 == 2)
					if (s[i] != 'G') cnt++, s1[i] = 'G';
			}
			if (j == 3)
			{
				if (i % 3 == 0)
					if (s1[i] != 'G') cnt++, s1[i] = 'G';
				if (i % 3 == 1)
					if (s1[i] != 'R') cnt++, s1[i] = 'R';

				if (i % 3 == 2)
					if (s1[i] != 'B') cnt++, s1[i] = 'B';

			}
			if (j == 4)
			{
				if (i % 3 == 0)
					if (s1[i] != 'G') cnt++, s1[i] = 'G';
				if (i % 3 == 1)
					if (s1[i] != 'B') cnt++, s1[i] = 'B';

				if (i % 3 == 2)
					if (s1[i] != 'R') cnt++, s1[i] = 'R';

			}
			if (j == 5)
			{
				if (i % 3 == 0)
					if (s1[i] != 'B') cnt++, s1[i] = 'B';
				if (i % 3 == 1)
					if (s1[i] != 'G') cnt++, s1[i] = 'G';

				if (i % 3 == 2)
					if (s1[i] != 'R') cnt++, s1[i] = 'R';

			}
			if (j == 6)
			{
				if (i % 3 == 0)
					if (s1[i] != 'B') cnt++, s1[i] = 'B';
				if (i % 3 == 1)
					if (s1[i] != 'R') cnt++, s1[i] = 'R';

				if (i % 3 == 2)
					if (s1[i] != 'G') cnt++, s1[i] = 'G';
			}

		}

		if (ans > cnt) { 
			ans = cnt; 
			ans1 = s1;
		}
	}
	cout << ans << "\n" << ans1;
}