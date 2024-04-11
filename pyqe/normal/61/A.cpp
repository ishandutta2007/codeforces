#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s,t,v="";
	long long i;
	
	cin>>s>>t;
	for(i=0;i<s.length();i++)
	{
		if(s[i]==t[i])
		{
			v=v+"0";
		}
		else
		{
			v=v+"1";
		}
	}
	cout<<v<<endl;
}