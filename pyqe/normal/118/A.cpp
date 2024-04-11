#include <iostream>
#include <string>

using namespace std;

int main()
{
	long long i;
	string s;
	
	cin>>s;
	for(i=0;i<s.size();i++)
	{
		if(!(s[i]=='a'||s[i]=='i'||s[i]=='u'||s[i]=='e'||s[i]=='o'||s[i]=='A'||s[i]=='I'||s[i]=='U'||s[i]=='E'||s[i]=='O'||s[i]=='y'||s[i]=='Y'))
		{
			if((int)s[i]>=65&&(int)s[i]<=90)
			{
				s[i]=s[i]+32;
			}
			if((int)s[i]>=97&&(int)s[i]<=122)
			{
				cout<<"."<<s[i];
			}
		}
	}
	cout<<endl;
}