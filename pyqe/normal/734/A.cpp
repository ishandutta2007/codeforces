#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	long long i,a=0,d=0;
	
	cin>>i>>s;
	for(i=0;i<s.length();i++)
	{
		if(s[i]=='A')
		{
			a++;
			if(a>s.length()/2)
			{
				i=-1;
				break;
			}
		}
		if(s[i]=='D')
		{
			d++;
			if(d>s.length()/2)
			{
				i=-2;
				break;
			}
		}
	}
	if(i==-1)
	{
		cout<<"Anton\n";
	}
	else if(i==-2)
	{
		cout<<"Danik\n";
	}
	else
	{
		cout<<"Friendship\n";
	}
}