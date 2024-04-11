#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s,t,u;
	long long i;
	
	cin>>s>>t>>u;
	if(s.length()+t.length()==u.length())
	{
		for(i=0;i<u.length();i++)
		{
			if(s.find(u[i])<s.length())
			{
				s.erase(s.find(u[i]),1);
			}
			else if(t.find(u[i])<t.length())
			{
				t.erase(t.find(u[i]),1);
			}
			else
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