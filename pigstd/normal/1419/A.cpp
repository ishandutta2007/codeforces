#include<bits/stdc++.h>
using namespace std;

int T;

int main()
{
	cin>>T;
	while(T--)
	{
		string s;int len,_oo=0,_oj=0,_jo=0,_jj=0;
		cin>>len>>s;
		for (int i=0;i<len;i++)
			if ((i+1)%2==0)
			{
				if ((s[i]-'0')%2==0)_oo++;
				else _oj++;
			}
			else
			{
				if ((s[i]-'0')%2==0)_jo++;
				else _jj++;
			}
		if (len%2!=0)
		{
			if (_jj!=0)puts("1");
			else puts("2");
		}
		else
		{
			if (_oo==0)puts("1");
			else puts("2");
		}
	}
	return 0;
}