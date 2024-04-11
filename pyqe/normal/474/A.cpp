#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long i,j,ln;
	string ky[3]={"qwertyuiop","asdfghjkl;","zxcvbnm,./"},s;
	map<char,char> m;
	char c;
	
	scanf(" %c",&c);
	for(i=0;i<3;i++)
	{
		for(j=1;j<10;j++)
		{
			if(c=='R')
			{
				m[ky[i][j]]=ky[i][j-1];
			}
			else if(c=='L')
			{
				m[ky[i][j-1]]=ky[i][j];
			}
		}
	}
	cin>>s;
	ln=s.length();
	for(i=0;i<ln;i++)
	{
		s[i]=m[s[i]];
	}
	printf("%s\n",s.c_str());
}