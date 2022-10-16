#include <iostream>
#include <string>

using namespace std;

int main()
{
	long long i,c=0,d=0;
	string s;
	
	cin>>s;
	for(i=0;i<s.length();i++)
	{
		if(s[i]>='A'&&s[i]<='Z')
		{
			c++;
		}
		if(s[i]>='a'&&s[i]<='z')
		{
			d++;
		}
	}
	if(c>d)
	{
		for(i=0;i<s.length();i++)
		{
			if(s[i]>='a'&&s[i]<='z')
			{
				s[i]-=32;
			}
		}
	}
	else
	{
		for(i=0;i<s.length();i++)
		{
			if(s[i]>='A'&&s[i]<='Z')
			{
				s[i]+=32;
			}
		}
	}
	cout<<s<<endl;
}