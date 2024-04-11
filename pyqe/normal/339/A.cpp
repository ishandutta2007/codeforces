#include <iostream>
#include <string>

using namespace std;

int main()
{
	long long i,a=0,b=0,c=0;
	string s;
	
	getline(cin,s);
	for(i=0;i<s.length();i+=2)
	{
		if(s[i]=='1')
		{
			a++;
		}
		if(s[i]=='2')
		{
			b++;
		}
		if(s[i]=='3')
		{
			c++;
		}
	}
	for(i=0;i<a+b+c;i++)
	{
		if(i<a)
		{
			cout<<"1";
		}
		else if(i<a+b)
		{
			cout<<"2";
		}
		else
		{
			cout<<"3";
		}
		if(i==a+b+c-1)
		{
			cout<<endl;
		}
		else
		{
			cout<<"+";
		}
	}
}