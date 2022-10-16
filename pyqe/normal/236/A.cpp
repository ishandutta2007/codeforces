#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	map <char,bool> m;
	string s;
	long long i;
	char c;
	bool g=true;
	
	cin>>s;
	for(i=0;i<s.length();i++)
	{
		m[s[i]]=true;
	}
	for(c='a';c<='z';c++)
	{
		if(m[c])
		{
			g=!g;
		}
	}
	if(g)
	{
		cout<<"CHAT WITH HER!\n";
	}
	else
	{
		cout<<"IGNORE HIM!\n";
	}
}