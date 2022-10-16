#include <iostream>

using namespace std;

int main()
{
	string s;
	
	getline(cin,s);
	if(s[0]>'Z')
	{
		s[0]-=32;
	}
	cout<<s<<endl;
}