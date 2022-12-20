#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;
string t = "heidi";

int main()
{
	cin >> s;
	int j = 0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==t[j]) j++;
		if(j==t.size())
		{
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}