#include <iostream>

using namespace std;

int main()
{
	string s[6];
	for(int i = 0; i <= 5; i++)
		cin >> s[i];
	for(int i = 1; i <= 5; i++)
		if(s[i][0] == s[0][0] || s[i][1] == s[0][1])
		{
			cout << "YES" << endl;
			return 0;
		}
	cout << "NO" << endl;
	return 0;
}