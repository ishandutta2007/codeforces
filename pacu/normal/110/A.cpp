#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int cnt = 0;
	for(int i=0;i<s.size();i++)
		if((s[i]=='4')||(s[i]=='7'))
			cnt++;
	if((cnt==4)||(cnt==7)||(cnt==14)||(cnt==17))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}