#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	long long n,i,c=0;
	string s;
	map <char,bool> m;
	
	cin>>n>>s;
	for(i=0;i<n;i++)
	{
		if(!m[tolower(s[i])])
		{
			c++;
			m[tolower(s[i])]=true;
			if(c==26)
			{
				cout<<"YES\n";
				return 0;
			}
		}
	}
	cout<<"NO\n";
}