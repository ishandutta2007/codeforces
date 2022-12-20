#include <iostream>
#include <string>
using namespace std;

int check()
{
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='H') return 1;
		if(s[i]=='Q') return 1;
		if(s[i]=='9') return 1;
	}
	return 0;
}
int main()
{
	if(check()) cout << "YES" << endl;
	else cout << "NO" << endl;
}