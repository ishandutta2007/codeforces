#include <iostream>
#include <string>

using namespace std;

int main()
{
	long long n,i,l,c=0;
	string s;
	bool f;
	
	cin>>n>>s;
	
	while(f==false)
	{
		l=0;
		f=true;
		for(i=0;i<s.length();i++)
		{
			if(s[i]==l)
			{
				s.erase(i,1);
				f=false;
				c++;
				break;
			}
			l=s[i];
		}
	}
	cout<<c<<endl;
}