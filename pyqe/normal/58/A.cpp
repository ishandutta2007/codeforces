#include <iostream>
#include <string>

using namespace std;

int main()
{
	long long i,c=0;;
	string s;
	
	cin>>s;
	for(i=0;i<s.length();i++)
	{
		if(c==4&&s[i]=='o')
		{
			c++;
			break;
		}
		if(c==3&&s[i]=='l')
		{
			c++;
		}
		if(c==2&&s[i]=='l')
		{
			c++;
		}
		if(c==1&&s[i]=='e')
		{
			c++;
		}
		if(c==0&&s[i]=='h')
		{
			c++;
		}
	}
	if(c==5)
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
}