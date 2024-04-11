#include <iostream>
#include <string>

using namespace std;

int main()
{
	long long n,t,i,j;
	string s;
	
	cin>>n>>t>>s;
	for(i=0;i<t;i++)
	{
		for(j=0;j<s.length();j++)
		{
			if(s[j]=='B'&&s[j+1]=='G')
			{
				s[j]='G';
				s[j+1]='B';
				j++;
			}
		}
	}
	cout<<s<<endl;
}