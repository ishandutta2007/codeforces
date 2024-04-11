#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long i,j,b=0,w=0;
	string s;
	map<char,long long> m;
	
	m['q']=9;
	m['r']=5;
	m['b']=3;
	m['n']=3;
	m['p']=1;
	m['k']=0;
	for(i=0;i<8;i++)
	{
		cin>>s;
		for(j=0;j<8;j++)
		{
			if(s[j]!='.')
			{
				if(s[j]<97)
				{
					w+=m[s[j]+32];
				}
				else
				{
					b+=m[s[j]];
				}
			}
		}
	}
	if(b>w)
	{
		printf("Black\n");
	}
	else if(b<w)
	{
		printf("White\n");
	}
	else
	{
		printf("Draw\n");
	}
}