#include <iostream>
#include <string>

using namespace std;

int main()
{
	char k;
	int c=1;
	long long i;
	string s;
	
	getline(cin,s);
	for(i=0;i<s.length();i++)
	{
		if(i>0)
		{
			if(k==s[i])
			{
				c++;
				if(c==7)
				{
					break;
				}
			}
			else
			{
				c=1;
			}
		}
		k=s[i];
	}
	if(c==7)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
}