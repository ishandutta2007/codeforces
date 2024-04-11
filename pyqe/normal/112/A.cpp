#include <iostream>
#include <string>

using namespace std;

int main()
{
	int m,n;
	long long i;
	string s,t;
	
	getline(cin,s);
	getline(cin,t);
	for(i=0;i<s.length();i++)
	{
		m=s[i];
		n=t[i];
		if(m>'`')
		{
			m-=32;
		}
		if(n>'`')
		{
			n-=32;
		}
		if(m<n)
		{
			cout<<"-1\n";
			break;
		}
		if(m>n)
		{
			cout<<"1\n";
			break;
		}
	}
	if(i==s.length())
	{
		cout<<"0\n";
	}
}