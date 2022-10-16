#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	
	cin>>s;
	if(s[0]=='-')
	{
		if(s[s.length()-1]>s[s.length()-2])
		{
			s.erase(s.length()-1,1);
		}
		else
		{
			s.erase(s.length()-2,1);
		}
	}
	if(s=="-0")
	{
		s="0";
	}
	cout<<s<<'\n';
}