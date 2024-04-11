#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int prev0 = 0;
	int prev1 = 0;
	cin >> s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0')
		{
			prev0++;
			prev1=0;
		}
		else
		{
			prev1++;
			prev0=0;
		}
		if(prev0==7)
		{
			cout << "YES" << endl;
			return 0;
		}
		if(prev1==7)
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}