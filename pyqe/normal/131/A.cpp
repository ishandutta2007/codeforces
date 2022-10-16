#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	long long i;
	
	cin>>s;
	for(i=1;i<s.length();i++)
	{
		if(s[i]>'Z')
		{
			cout<<s<<endl;
			return 0;
		}
	}
	for(i=0;i<s.length();i++)
	{
		if(s[i]>'Z')
		{
			s[i]-=32;
		}
		else
		{
			s[i]+=32;
		}
	}
	cout<<s<<endl;
}