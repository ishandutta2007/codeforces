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
		long long ans = str.size() , min1 = 0 , cnt = 0;
		for(int i = 0; i < str.size(); i++)
		{
			if(str[i] == '+')
				cnt++;
			else
				cnt--;
			if(cnt < min1)
			{
				min1 = cnt;
				ans += i + 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}