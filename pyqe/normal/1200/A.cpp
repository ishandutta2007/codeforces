#include <bits/stdc++.h>

using namespace std;

bitset<10> vtd;

int main()
{
	long long ln,i,j;
	string s;
	
	scanf("%lld",&ln);
	cin>>s;
	for(i=0;i<ln;i++)
	{
		if(s[i]=='L')
		{
			for(j=0;vtd[j];j++);
			vtd[j]=1;
		}
		else if(s[i]=='R')
		{
			for(j=9;vtd[j];j--);
			vtd[j]=1;
		}
		else
		{
			vtd[s[i]-'0']=0;
		}
	}
	for(i=0;i<10;i++)
	{
		printf("%d",(bool)vtd[i]);
	}
	printf("\n");
}