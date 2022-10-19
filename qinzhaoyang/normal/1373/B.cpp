#include <iostream>

using namespace std;

int t;

int main()
{
	cin >> t;
	while(t--)
	{
		string str;
		cin >> str;
		int cnt1 = 0 , cnt2 = 0;
		for(int i = 0; i < str.size(); i++)
		{
			if(str[i] == '0')
				cnt1++;
			else
				cnt2++;
		}
		if(min(cnt1 , cnt2) % 2 == 1)
			cout << "DA" << endl;
		else
			cout << "NET" << endl;
	}
	return 0;
}