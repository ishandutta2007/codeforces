#include <iostream>
#include <string>

using namespace std;

int main()
{
	long long i;
	string s,t;
	
	cin>>s>>t;
	if(s.length()==t.length())
	{
		for(i=0;i<s.length();i++)
		{
			if(s[i]!=t[t.length()-1-i])
			{
				cout<<"NO\n";
				return 0;
			}
		}
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
}