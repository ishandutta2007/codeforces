#include <iostream>
#include <string>

using namespace std;

int main()
{
	long long i,c=0;
	string n;
	
	cin>>n;
	for(i=0;i<n.length();i++)
	{
		if(n[i]=='4'||n[i]=='7')
		{
			c++;
		}
	}
	if(c==4||c==7)
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
}