#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	
	cin>>s;
	while(s.find("WUB")<s.size())
	{
		if(s.find("WUB")==0||s[s.find("WUB")-1]==' ')
		{
			s.erase(s.find("WUB"),3);
		}
		else
		{
			s.replace(s.find("WUB"),3," ");
		}
	}
	if(s[s.length()-1]==' ')
	{
		s.erase(s.length()-1);
	}
	cout<<s<<endl;
}