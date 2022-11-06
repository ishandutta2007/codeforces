#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cout << "1 2" << endl;
		string temp;
		cin >> temp;
		if (temp == "Done")
			continue;
		cout << "1 1" << endl; 
		int r = 1;
		int c = 1;
		bool goLeft = false;
		while (1)
		{
			string s;
			cin >> s;
			if (s == "Done")
				break;
			if (goLeft && c != 1)
			{
				c = 1;
				cout << r << " " << c << endl;
			}
			else if (s.find("Up") != string::npos && c != 1)
			{
				c = 1;
				cout << r << " " << c << endl;
			}
			else if (s.find("Down") != string::npos)
			{
				r++;
				c = max(c - 1, 1);
				cout << r << " " << c << endl;
				goLeft = true;
				continue;
			}
			else if (c == 8)
			{
				r++;
				c = 7;
				cout << r << " " << c << endl;
				goLeft = true;
				continue;
			}
			else
			{
				c++;
				cout << r << " " << c << endl;
			}
			goLeft = false;
		}
	}
	return 0;
}