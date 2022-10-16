#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long z[2]={0,0},ln,i;
	bool g=true;
	string s;
	
	cin>>s;
	ln=s.length();
	for(i=1;i<ln;i++)
	{
		if(s[i]=='B'&&s[i-1]=='A')
		{
			if(g)
			{
				z[0]+=2;
				g=false;
			}
			else
			{
				z[0]++;
				z[1]--;
				i++;
				g=true;
			}
			continue;
		}
		else if(s[i]=='A'&&s[i-1]=='B')
		{
			if(g)
			{
				z[1]+=2;
				g=false;
			}
			else
			{
				z[1]++;
				z[0]--;
				i++;
				g=true;
			}
			continue;
		}
		g=true;
	}
	for(i=0;i<2;i++)
	{
		if(z[i]>3)
		{
			z[i]=3;
		}
	}
	if(z[1]+z[0]>=4)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}