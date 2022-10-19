#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		string str;
		cin >> str;
		int cnt = 0 , ans = 0;
		for(int i = 0; i < str.size(); i++)
		{
			if(str[i] == '(')
				cnt++;
			else if(str[i] == ')')
			{
				if(cnt == 0)
					ans++;
				else
					cnt--;
			}
		}
		cout << ans << endl;
	}
	return 0;
}