#include <iostream>
#include <string>

using namespace std;

int main()
{
	long long i;
	string s;
	
	getline(cin,s);
	for(i=0;i<s.length();i++)
	{
		if(s[i]=='H'||s[i]=='Q'||s[i]=='9')
		{
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";
}